using System.Collections.Generic;
using System.Drawing;

namespace LevelEditor.Models
{
	/// <summary>
	/// Interface that defines methods for getting and setting information
	/// about gridobjects in a level.
	/// </summary>
	public interface ILevel
	{
		int Width { get; }
		int Height { get; }
		Point Start { get; set; }
		IDictionary<Point, GridObject> GridObjects { get; set; }
		SpriteSet SpriteSet { get; set; }
		void SetGridObject(Point pos, GridObject obj);
		void RemoveGridObject(Point pos);
	}
}
