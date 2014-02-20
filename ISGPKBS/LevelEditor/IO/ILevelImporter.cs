namespace LevelEditor.IO
{
	public interface ILevelImporter
	{
		ILevelReader LevelReader { get; set; }
		ILevel ImportLevel();
	}
}
