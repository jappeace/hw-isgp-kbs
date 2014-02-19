using System.Drawing;

namespace LevelEditor
{
	/// <summary>
	/// This class represents a tile and contains information about its
	/// position in the map and the type of the tile.
	/// </summary>
	class Tile
	{
		/// <summary>
		/// Type of the tile.
		/// </summary>
		public TileType Type { get; set; }

		/// <summary>
		/// Position of the tile in the map.
		/// </summary>
		public Point Position { get; set; }

		public Tile(TileType type, Point position)
		{
			Type = type;
			Position = position;
		}
	}
}
