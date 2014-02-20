using System.IO;

namespace LevelEditor
{
	class LevelFileWriter : ILevelWriter
	{
		private StreamWriter _streamWriter;

		public LevelFileWriter(string fileName)
		{
			if (File.Exists(fileName))
			{
				File.Delete(fileName);
			}
			_streamWriter = new StreamWriter(fileName);
		}

		public void WriteLine(string line)
		{
			_streamWriter.WriteLine(line);
		}
	}
}
