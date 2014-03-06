using System.Collections.Generic;
using System.Drawing;

namespace LevelEditor.Models
{
	/// <summary>
	/// This class represents a tile and contains information about its
	/// position in the map and the type of the tile.
	/// </summary>
	class GridObject
	{
		/// <summary>
		/// Type of the tile.
		/// </summary>
		public GridObjectType Type { get; set; }

		public IEnumerable<Behaviour> Behaviour { get; set; }

		/// <summary>
		/// Position of the tile in the map.
		/// </summary>
		public Point Position { get; set; }

		public GridObject(GridObjectType type, Point position)
		{
			Type = type;
			Position = position;
		}
	}
}
