using System.Text;

namespace LevelEditor.Tests.Unit
{
	class LevelStringWriter : ILevelWriter
	{
		private StringBuilder _stringBuilder;

		public string LevelString
		{
			get
			{
				return _stringBuilder.ToString();
			}
		}

		public LevelStringWriter()
		{
			_stringBuilder = new StringBuilder();
		}

		public void WriteLine(string line)
		{
			_stringBuilder.AppendLine(line);
		}
	}
}
