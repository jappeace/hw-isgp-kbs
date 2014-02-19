using System.Collections.Generic;
using System.Drawing;

namespace LevelEditor
{
	/// <summary>
	/// Interface that defines methods for getting and setting information
	/// about tiles in a level.
	/// </summary>
	interface ILevel
	{
		void SetTile(Point position, TileType tileType);
		IDictionary<Point, TileType> GetTiles();
	}
}
