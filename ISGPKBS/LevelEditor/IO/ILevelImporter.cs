namespace LevelEditor.IO
{
	public interface ILevelImporter
	{
		IReader LevelReader { get; set; }
		ILevel ImportLevel();
	}
}
