﻿using System.IO;
using System.Text;
using LevelEditor.Models.IO;

namespace LevelEditor.Tests.Unit.IO
{
	class StringReader : IReader
	{
		private StreamReader _streamReader;

		public StringReader(string levelString)
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
