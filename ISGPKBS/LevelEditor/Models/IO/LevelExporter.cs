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
			throw new NotImplementedException();
		}

		/// <summary>
		/// Creates a line for a tile.
		/// </summary>
		private string TileToString(Point position, GridObjectType type)
		{
			return string.Format("{0},{1}={2}", position.X, position.Y, (int)type);
		}
	}
}
