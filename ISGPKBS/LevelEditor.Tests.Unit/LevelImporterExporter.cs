using LevelEditor.Models;
using LevelEditor.Models.IO;
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
			// Create simple levelstring.
			string levelString = "width=10\r\nheight=10\r\n";
			levelString += "start=0,1\r\nfinish=0,2\r\n";
			levelString += "1,2=2\r\n5,3=3\r\n";

			// Import from levelstring to ILevel object.
			ILevelImporter importer = new LevelImporter(new StringReader(levelString));
			ILevel level = importer.ImportLevel();

			// Export from imported ILevel to string.
			StringWriter writer = new StringWriter();
			ILevelExporter exporter = new LevelExporter(writer);
			exporter.ExportLevel(level);

			// Levelstrings should be exactly the same.
			Assert.AreEqual(levelString, writer.LevelString);
		}
	}
}
