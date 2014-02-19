using System.Collections.Generic;
using System.Drawing;
using System.IO;

namespace LevelEditor
{
	class LevelExport : ILevelExporter
	{
		/// <summary>
		/// Exports the specified level to the specified file. If the file
		/// already exists, it will be deleted and a new file will be created.
		/// </summary>
		public void ExportLevel(ILevel level, string file)
		{
			IDictionary<Point, TileType> tiles = level.GetTiles();

			// Delete the level file if it already exists.
			if (File.Exists(file))
			{
				File.Delete(file);
			}

			using (var streamWriter = new StreamWriter(file))
			{

				// Write width and height to the file.
				streamWriter.WriteLine(string.Format("width={0}", level.Width));
				streamWriter.WriteLine(string.Format("width={1}", level.Height));
				foreach (Point key in tiles.Keys)
				{
					streamWriter.WriteLine(TileToString(key, tiles[key]));
				}
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
