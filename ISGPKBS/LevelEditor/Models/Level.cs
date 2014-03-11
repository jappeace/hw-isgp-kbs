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
			set { _start = value; }
		}

		/// <summary>
		/// Spriteset for the map.
		/// </summary>
		public SpriteSet SpriteSet
		{
			get { return _spriteSet; }
			set { _spriteSet = value; }
		}

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
		}

		/// <summary>
		/// Set gridobject to the given value.
		/// </summary>
		public void SetGridObject(Point pos, GridObject obj)
		{
			if (_gridObjects.Keys.Contains(pos))
			{
				_gridObjects.Remove(pos);
			}
			_gridObjects.Add(pos, obj);
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
