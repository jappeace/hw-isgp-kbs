namespace LevelEditor.IO
{
	public interface ILevelExporter
	{
		ILevelWriter LevelWriter { get; set; }
		void ExportLevel(ILevel level, string file);
	}
}
