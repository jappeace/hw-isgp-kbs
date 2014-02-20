using System.Collections.Generic;
using System.Drawing;
using System.IO;

namespace LevelEditor.IO
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
			IDictionary<Point, TileType> tiles = level.GetTiles();

			// Write width and height to the file.
			LevelWriter.WriteLine(string.Format("width={0}", level.Width));
			LevelWriter.WriteLine(string.Format("width={0}", level.Height));
			foreach (Point key in tiles.Keys)
			{
				LevelWriter.WriteLine(TileToString(key, tiles[key]));
			}
		}

		/// <summary>
		/// Creates a line for a tile.
		/// </summary>
		private string TileToString(Point position, TileType type)
		{
			return string.Format("{0},{1}={2}", position.X, position.Y, (int)type);
		}
	}
}
