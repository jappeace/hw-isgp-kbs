using System.Collections.Generic;
using System.Drawing;

namespace LevelEditor.Models
{
	public class Level : ILevel
	{
		private int _width;
		private int _height;
		private Point _start;
		private IDictionary<Point, IDictionary<Layer, GridObject>> _gridObjects;
		private SpriteSet _spriteSet;

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
		/// Collection of all gridobjects.
		/// </summary>
		public IDictionary<Point, IDictionary<Layer, GridObject>> GridObjects
		{
			get { return _gridObjects; }
			set { _gridObjects = value; }
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
		/// Creates a level with the given width, height and spriteset.
		/// </summary>
		public Level(int width, int height, SpriteSet spriteSet)
		{
			_width = width;
			_height = height;
			_spriteSet = spriteSet;
		}
	}
}
