using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LevelEditor
{
	class LevelFileReader : ILevelReader
	{
		private StreamReader _streamReader;

		public LevelFileReader(string fileName)
		{
			_streamReader = new StreamReader(fileName);
		}
	}
}
