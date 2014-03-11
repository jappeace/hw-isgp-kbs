﻿using System;
using System.Drawing;

namespace LevelEditor.Models.IO
{
	/// <summary>
	/// Imports a level from an external resource.
	/// </summary>
	public class LevelImporter : ILevelImporter
	{
		private IReader _levelReader;

		/// <summary>
		/// Object used to read the level.
		/// </summary>
		public IReader LevelReader
		{
			get { return _levelReader; }
			set { _levelReader = value; }
		}

		/// <summary>
		/// Constructor for using a FileReader that reads from the filesystem.
		/// </summary>
		public LevelImporter(string fileName)
			: this(new FileReader(fileName))
		{
		}

		/// <summary>
		/// Alternative constructor for dependency injection.
		/// </summary>
		public LevelImporter(IReader levelReader)
		{
			LevelReader = levelReader;
		}

		/// <summary>
		/// Loads a level file and returns an ILevel object.
		/// May throw a FileNotFoundException if the file is not found.
		/// </summary>
		public ILevel ImportLevel()
		{
			int width = GetIntValue(LevelReader.ReadLine());
			int height = GetIntValue(LevelReader.ReadLine());
			ILevel level = new Level(width, height);
			level.Start = GetPosition(LevelReader.ReadLine());

			Point gridObjectPos;
			GridObjectType gridObjectType;
			string tileLine = LevelReader.ReadLine();
			while (tileLine != null)
			{
				gridObjectPos = GetPosition(tileLine);
				switch (GetStringValue(tileLine))
				{
					case "tile":
						gridObjectType = GridObjectType.Tile;
						break;
					case "ghost":
						gridObjectType = GridObjectType.Ghost;
						break;
				}
			}
			return level;
		}

		/// <summary>
		/// Gets the string value from a string that looks like:
		/// name=value
		/// </summary>
		private string GetStringValue(string line)
		{
			// line.Split() returns ["name", "value"].
			// We return the third index, which is the value we want.
			return line.Split('=')[1];
		}

		/// <summary>
		/// Gets the int value from a string that looks like:
		/// name=value
		/// May throw a format exception if the value is not an int.
		/// </summary>
		private int GetIntValue(string line)
		{
			return Int32.Parse(GetStringValue(line));
		}

		/// <summary>
		/// Gets the Point with a position of a string tha tlooks like:
		/// xcoordinate,ycoordinate=tiletype
		/// </summary>
		private Point GetPosition(string line)
		{
			// line.Split() => ["point", "tiletype"]
			string point = line.Split('=')[0];
			// point.Split() => ["x-coordinate", "y-coordinate"]
			string[] coordinates = point.Split(',');

			return new Point(Int32.Parse(coordinates[0]),
				Int32.Parse(coordinates[1]));
		}
	}
}
