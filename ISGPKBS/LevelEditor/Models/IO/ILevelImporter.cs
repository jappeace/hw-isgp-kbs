namespace LevelEditor.Models.IO
{
	public interface ILevelImporter
	{
		IReader LevelReader { get; set; }
		ILevel ImportLevel();
	}
}
