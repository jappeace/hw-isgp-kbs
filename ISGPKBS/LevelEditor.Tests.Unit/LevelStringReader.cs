using System.IO;
using System.Text;
using LevelEditor.IO;

namespace LevelEditor.Tests.Unit
{
	class LevelStringReader : ILevelReader
	{
		private StreamReader _streamReader;

		public LevelStringReader(string levelString)
		{
			byte[] levelBytes = Encoding.ASCII.GetBytes(levelString);
			MemoryStream memoryStream = new MemoryStream(levelBytes);
			_streamReader = new StreamReader(memoryStream);
		}

		public string ReadLine()
		{
			return _streamReader.ReadLine();
		}
	}
}
