namespace LevelEditor.IO
{
	public interface ILevelExporter
	{
		IWriter LevelWriter { get; set; }
		void ExportLevel(ILevel level);
	}
}
