using System.IO;

namespace LevelEditor
{
	/// <summary>
	/// Class that handles writing to a file.
	/// </summary>
	class LevelFileWriter : ILevelWriter
	{
		private StreamWriter _streamWriter;

		/// <summary>
		/// Creates an object that is capable of writing to the specified file.
		/// </summary>
		public LevelFileWriter(string fileName)
		{
			if (File.Exists(fileName))
			{
				File.Delete(fileName);
			}
			_streamWriter = new StreamWriter(fileName);
		}

		/// <summary>
		/// Writes a line to the level file.
		/// </summary>
		public void WriteLine(string line)
		{
			_streamWriter.WriteLine(line);
		}
	}
}
