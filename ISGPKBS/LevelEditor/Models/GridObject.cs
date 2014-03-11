using System.Collections.Generic;
using System.Drawing;

namespace LevelEditor.Models
{
	/// <summary>
	/// This class represents a gridobject and contains information about its
	/// position in the map, its behaviour and its type.
	/// </summary>
	public class GridObject
	{
		/// <summary>
		/// Type of the tile.
		/// </summary>
		public GridObjectType Type { get; set; }

		/// <summary>
		/// Topleft coordinate in the spriteset in pixels where the sprite for
		/// this gridobject starts.
		/// </summary>
		public Point SpriteSetLocation { get; set; }

		public GridObject(GridObjectType type)
		{
			Type = type;
			SpriteSetLocation = new Point();
		}
	}
}
