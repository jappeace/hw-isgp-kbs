using System.IO;

namespace LevelEditor.IO
{
	/// <summary>
	/// Class that reads the contents of a level from a file.
	/// </summary>
	class LevelFileReader : ILevelReader
	{
		private StreamReader _streamReader;

		/// <summary>
		/// Create a LevelFileReader object that can read the contents of the
		/// specified file.
		/// </summary>
		public LevelFileReader(string fileName)
		{
			_streamReader = new StreamReader(fileName);
		}

		/// <summary>
		/// Read a line from the level file and move the cursor to the next line.
		/// </summary>
		public string ReadLine()
		{
			return _streamReader.ReadLine();
		}
	}
}
