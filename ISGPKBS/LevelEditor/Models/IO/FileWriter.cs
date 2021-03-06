﻿using System.IO;

namespace LevelEditor.Models.IO
{
	/// <summary>
	/// Class that handles writing to a file.
	/// </summary>
	class FileWriter : IWriter
	{
		private StreamWriter _streamWriter;

		/// <summary>
		/// Creates an object that is capable of writing to the specified file.
		/// </summary>
		public FileWriter(string fileName)
		{
			if (File.Exists(fileName))
			{
				File.Delete(fileName);
			}
			_streamWriter = new StreamWriter(fileName);
		}

		/// <summary>
		/// Writes a line to the file.
		/// </summary>
		public void WriteLine(string line)
		{
			_streamWriter.WriteLine(line);
		}

		/// <summary>
		/// Closes the filewriter.
		/// </summary>
		public void Close()
		{
			_streamWriter.Close();
		}
	}
}
