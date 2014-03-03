using System.Drawing;
using LevelEditor.IO;
using LevelEditor.Tests.Unit.IO;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace LevelEditor.Tests.Unit
{
	[TestClass]
	public class LevelImporterExporter
	{
		[TestMethod]
		public void Import_ExportedLevel_SameLevel()
		{
			ILevel level = new Level(10, 10);
			level.SetTile(new Point(3, 2), TileType.Brick);
			level.SetTile(new Point(5, 9), TileType.Start);
			StringWriter stringWriter = new StringWriter();
			ILevelExporter levelExporter = new LevelExporter(stringWriter);
			levelExporter.ExportLevel(level);
			StringReader stringReader = new StringReader(stringWriter.LevelString);
			ILevelImporter levelImporter = new LevelImporter(stringReader);
			ILevel importedLevel = levelImporter.ImportLevel();
		}
	}
}
