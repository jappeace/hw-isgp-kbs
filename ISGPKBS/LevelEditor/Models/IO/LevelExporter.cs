using System;
using System.Collections.Generic;
using System.Drawing;

namespace LevelEditor.Models.IO
{
	public class LevelExporter : ILevelExporter
	{
		private IWriter _levelWriter;

		public IWriter LevelWriter
		{
			get { return _levelWriter; }
			set { _levelWriter = value; }
		}

		/// <summary>
		/// Constructor for using a FileWriter that uses the filesystem.
		/// </summary>
		public LevelExporter(string fileName)
			: this(new FileWriter(fileName))
		{
		}

		/// <summary>
		/// Alternative constructor for dependency injection.
		/// </summary>
		public LevelExporter(IWriter levelWriter)
		{
			LevelWriter = levelWriter;
		}

		/// <summary>
		/// Exports the specified level to the specified file. If the file
		/// already exists, it will be deleted and a new file will be created.
		/// </summary>
		public void ExportLevel(ILevel level)
		{
			LevelWriter.WriteLine(string.Format("width={0}", level.Width));
			LevelWriter.WriteLine(string.Format("height={0}", level.Height));
			LevelWriter.WriteLine(string.Format("start={0},{1}",
				level.Start.X, level.Start.Y));
			LevelWriter.WriteLine(string.Format("finish={0},{1}",
				level.Finish.X, level.Finish.Y));
			foreach (KeyValuePair<Point, GridObject> pair in level.GridObjects)
			{
				LevelWriter.WriteLine(TileToString(pair.Key, pair.Value));
			}
			LevelWriter.Close();
		}

		/// <summary>
		/// Creates a line for a tile.
		/// </summary>
		private string TileToString(Point position, GridObject obj)
		{
			string typeName = string.Empty;
			switch (obj.Type)
			{
				case GridObjectType.Tile:
					typeName = "tile";
					break;
				case GridObjectType.Ghost:
					typeName = "ghost";
					break;
				case GridObjectType.Patrol:
					typeName = "patrol";
					break;
			}
			return string.Format("{0},{1}={2}", position.X, position.Y, typeName);
		}
	}
}
