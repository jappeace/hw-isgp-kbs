namespace LevelEditor.Models.IO
{
	public interface IWriter
	{
		void WriteLine(string line);
		void Close();
	}
}
