namespace LevelEditor
{
	public interface ILevelImporter
	{
		ILevelReader LevelReader { get; set; }
		ILevel ImportLevel();
	}
}
