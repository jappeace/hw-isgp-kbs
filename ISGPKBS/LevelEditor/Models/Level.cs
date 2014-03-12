using System.Collections.Generic;
using System.Drawing;

namespace LevelEditor.Models
{
	/// <summary>
	/// A level with information about its contents.
	/// </summary>
	public class Level : ILevel
	{
		private int _width;
		private int _height;
		private Point _start;
		private Point _finish;
		private SpriteSet _spriteSet;
		private IDictionary<Point, GridObject> _gridObjects;

		/// <summary>
		/// Width of the map in tiles.
		/// </summary>
		public int Width
		{
			get { return _width; }
		}

		/// <summary>
		/// Height of the map in tiles.
		/// </summary>
		public int Height
		{
			get { return _height; }
		}

		/// <summary>
		/// Startposition of the player.
		/// </summary>
		public Point Start
		{
			get { return _start; }
			set
			{
				if (!GridObjects.Keys.Contains(value))
				{
					_start = value;
				}
			}
		}

		/// <summary>
		/// Finish of the player.
		/// </summary>
		public Point Finish
		{
			get { return _finish; }
			set
			{
				if (!GridObjects.Keys.Contains(value))
				{
					_finish = value;
				}
			}
		}

		/// <summary>
		/// Spriteset for the map.
		/// </summary>
		public SpriteSet SpriteSet
		{
			get { return _spriteSet; }
			set { _spriteSet = value; }
		}

		/// <summary>
		/// Collection of all gridobjects in the level.
		/// </summary>
		public IDictionary<Point, GridObject> GridObjects
		{
			get
			{
				return _gridObjects;
			}
			set
			{
				_gridObjects = value;
			}
		}

		/// <summary>
		/// Creates a level with the given width, height and spriteset.
		/// </summary>
		public Level(int width, int height)
		{
			_gridObjects = new Dictionary<Point, GridObject>();
			_width = width;
			_height = height;
			Start = new Point(0, 0);
			Finish = new Point(1, 0);
		}

		/// <summary>
		/// Set gridobject to the given value.
		/// </summary>
		public void SetGridObject(Point pos, GridObject obj)
		{
			if (pos.X < Width && pos.Y < Height)
			{
				if (_gridObjects.Keys.Contains(pos))
				{
					_gridObjects.Remove(pos);
				}
				_gridObjects.Add(pos, obj);
			}
		}

		/// <summary>
		/// Removes the gridobject at the given position if it exists.
		/// </summary>
		public void RemoveGridObject(Point pos)
		{
			_gridObjects.Remove(pos);
		}
	}
}
