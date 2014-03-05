using System.Collections.Generic;
using System.Drawing;

namespace LevelEditor.Models
{
	public class Level : ILevel
	{
		private int _width;
		private int _height;
		private Point _start;
		private Point _finish;
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
		/// Position of the starting point.
		/// </summary>
		public Point Start
		{
			get { return _start; }
			set { _start = value; }
		}

		/// <summary>
		/// Position of the starting point.
		/// </summary>
		public Point Finish
		{
			get { return _finish; }
			set { _finish = value; }
		}

		/// <summary>
		/// Creates an empty level with the specified width and height in tiles.
		/// </summary>
		public Level(int width, int height)
		{
			_width = width;
			_height = height;
			Start = new Point(0, 0);
			Start = new Point(1, 0);
			_tiles = new Dictionary<Point, TileType>();
		}

		/// <summary>
		/// Creates a tile on the specified position of the specified type.
		/// If a tile exists on the specified position, the tile will be
		/// replaced.
		/// If position is outside the level, no tile will be set.
		/// If TileType is a start/finish, the start/finish position will be
		/// changed.
		/// </summary>
		public void SetTile(Point position, TileType tileType)
		{
			if (position.X < Width && position.Y < Height)
			{
				if (tileType == TileType.Start)
				{
					Start = position;
				}
				else if (tileType == TileType.Finish)
				{
					Finish = position;
				}
				else if (Start != position && Finish != position)
				{
					if (_tiles.ContainsKey(position))
					{
						_tiles.Remove(position);
					}
					_tiles.Add(position, tileType);
				}
			}
		}

		/// <summary>
		/// Removes a tile on the specified position. Does nothing if no
		/// tile exists on the specified position.
		/// </summary>
		public void RemoveTile(Point position)
		{
			_tiles.Remove(position);
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
