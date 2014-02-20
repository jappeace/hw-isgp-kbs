using System.IO;

namespace LevelEditor
{
	class LevelFileReader : ILevelReader
	{
		private StreamReader _streamReader;

		public LevelFileReader(string fileName)
		{
			_streamReader = new StreamReader(fileName);
		}

		public string ReadLine()
		{
			return _streamReader.ReadLine();
		}
	}
}
