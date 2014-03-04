﻿using System.Collections.Generic;
using System.Drawing;

namespace LevelEditor.Models
{
	public class Level : ILevel
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
		/// If a tile exists on the specified position, the tile will be
		/// replaced.
		/// If position is outside the level, no tile will be set.
		/// </summary>
		public void SetTile(Point position, TileType tileType)
		{
			if (position.X < Width && position.Y < Height)
			{
				if (_tiles.ContainsKey(position))
				{
					_tiles.Remove(position);
				}
				_tiles.Add(position, tileType);
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
