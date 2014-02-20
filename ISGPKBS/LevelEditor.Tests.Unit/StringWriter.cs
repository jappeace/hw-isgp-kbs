using System.Text;
using LevelEditor.IO;

namespace LevelEditor.Tests.Unit
{
	class StringWriter : IWriter
	{
		private StringBuilder _stringBuilder;

		public string LevelString
		{
			get
			{
				return _stringBuilder.ToString();
			}
		}

		public StringWriter()
		{
			_stringBuilder = new StringBuilder();
		}

		public void WriteLine(string line)
		{
			_stringBuilder.AppendLine(line);
		}
	}
}
