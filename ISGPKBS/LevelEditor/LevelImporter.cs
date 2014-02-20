using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LevelEditor
{
	class LevelImporter : ILevelImporter
	{
		/// <summary>
		/// Loads a level file and returns an ILevel object.
		/// May throw a FileNotFoundException if the file is not found.
		/// </summary>
		public ILevel ImportLevel(string file)
		{
			ILevel level;
			var streamReader = new StreamReader(file);

			// Create level with the width and height specified in the file.
			int width = GetIntValue(streamReader.ReadLine());
			int height = GetIntValue(streamReader.ReadLine());
			level = new Level(width, height);

			// Read all coordinates and add them as tiles to the level.
			TileType tileType;
			Point position;
			string line = streamReader.ReadLine();
			while (line != null)
			{
				tileType = (TileType)GetIntValue(line);
				position = GetPosition(line);
				level.SetTile(position, tileType);
				line = streamReader.ReadLine();
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
