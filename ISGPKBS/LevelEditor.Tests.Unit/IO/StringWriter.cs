using System.Text;
using LevelEditor.Models.IO;

namespace LevelEditor.Tests.Unit.IO
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

		public void Close()
		{
			// Nothing needs to be closed.
		}
	}
}
