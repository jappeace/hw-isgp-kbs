using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LevelEditor
{
	class Level : ILevel
	{
		public void SetTile(System.Drawing.Point position, TileType tileType)
		{
			throw new NotImplementedException();
		}

		public IDictionary<System.Drawing.Point, TileType> GetTiles()
		{
			throw new NotImplementedException();
		}
	}
}
