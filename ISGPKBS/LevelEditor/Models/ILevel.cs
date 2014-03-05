using System.Collections.Generic;
using System.Drawing;

namespace LevelEditor.Models
{
	/// <summary>
	/// Interface that defines methods for getting and setting information
	/// about tiles in a level.
	/// </summary>
	public interface ILevel
	{
		int Width { get; }
		int Height { get; }
		Point Start { get; set; }
		Point Finish { get; set; }
		void SetTile(Point position, GridObjectType tileType);
		void RemoveTile(Point position);
		IDictionary<Point, GridObjectType> GetTiles();
	}
}
