using System.Collections.Generic;
using System.Drawing;
using System.IO;

namespace LevelEditor
{
	class LevelExport : ILevelExporter
	{
		public void ExportLevel(ILevel level, string file)
		{
			IDictionary<Point, TileType> tiles = level.GetTiles();
			var streamWriter = new StreamWriter(file);
			foreach (Point key in tiles.Keys)
			{
			}

			throw new System.NotImplementedException();
		}

		private string TileToString(Point position, TileType type)
		{
			return string.Format("{0},{1}={2}", position.X, position.Y, (int)type);
		}
	}
}
