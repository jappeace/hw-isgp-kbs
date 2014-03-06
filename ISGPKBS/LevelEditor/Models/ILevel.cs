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
		void SetTile(Point position, GridObjectType tileType);
		void RemoveGridObjectsAt(Point position);
		IEnumerable<GridObject> GetTiles();
	}
}
