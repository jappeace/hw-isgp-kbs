using System.Collections.Generic;
using System.Drawing;

namespace LevelEditor.Models
{
	/// <summary>
	/// This class represents a gridobject and contains information about its
	/// position in the map, its behaviour and its type.
	/// </summary>
	class GridObject
	{
		/// <summary>
		/// Type of the tile.
		/// </summary>
		public GridObjectType Type { get; set; }

		/// <summary>
		/// Collection of behaviour for this gridobject.
		/// </summary>
		public IEnumerable<Behaviour> Behaviour { get; set; }

		/// <summary>
		/// Position of the tile in the map.
		/// </summary>
		public Point Position { get; set; }

		/// <summary>
		/// Topleft coordinate in the spriteset in pixels where the sprite for
		/// this gridobject starts.
		/// </summary>
		public Point SpriteSetLocation { get; set; }

		public GridObject(GridObjectType type, Point position)
		{
			Type = type;
			Position = position;
			Behaviour = new List<Behaviour>();
			SpriteSetLocation = new Point();
		}
	}
}
