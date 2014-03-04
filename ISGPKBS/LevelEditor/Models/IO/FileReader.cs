using System.IO;

namespace LevelEditor.Models.IO
{
	/// <summary>
	/// Class that reads the contents of a file.
	/// </summary>
	class FileReader : IReader
	{
		private StreamReader _streamReader;

		/// <summary>
		/// Create a FileReader object that can read the contents of the
		/// specified file.
		/// </summary>
		public FileReader(string fileName)
		{
			_streamReader = new StreamReader(fileName);
		}

		/// <summary>
		/// Read a line from the file and move the cursor to the next line.
		/// </summary>
		public string ReadLine()
		{
			return _streamReader.ReadLine();
		}
	}
}
