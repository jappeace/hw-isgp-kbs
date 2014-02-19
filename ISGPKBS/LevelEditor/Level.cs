using System.Collections.Generic;
using System.Drawing;

namespace LevelEditor
{
	class Level : ILevel
	{
		private int _width;
		private int _height;
		private IDictionary<Point, TileType> _tiles;

		/// <summary>
		/// Width of the level in tiles.
		/// </summary>
		public int Width
		{
			get { return _width; }
		}

		/// <summary>
		/// Height of the level in tiles.
		/// </summary>
		public int Height
		{
			get { return _height; }
		}

		/// <summary>
		/// Creates an empty level with the specified width and height in tiles.
		/// </summary>
		public Level(int width, int height)
		{
			_width = width;
			_height = height;
			_tiles = new Dictionary<Point, TileType>();
		}

		/// <summary>
		/// Creates a tile on the specified position of the specified type.
		/// </summary>
		public void SetTile(Point position, TileType tileType)
		{
			_tiles.Add(position, tileType);
		}

		/// <summary>
		/// Gets a dictionary that contains all non-empty tiles.
		/// </summary>
		public IDictionary<Point, TileType> GetTiles()
		{
			return _tiles;
		}
	}
}
