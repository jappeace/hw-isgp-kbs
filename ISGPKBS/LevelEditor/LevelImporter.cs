using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LevelEditor
{
	class LevelImporter : ILevelImporter
	{
		/// <summary>
		/// Loads a level file and returns an ILevel object.
		/// May throw a FileNotFoundException if the file is not found.
		/// </summary>
		public ILevel ImportLevel(string file)
		{
			ILevel level;
			var streamReader = new StreamReader(file);

			return null;
		}

		private string GetStringValue(string line)
		{
			// line.Split() returns ["name", "=", "value"].
			// We return the third index, which is the value we want.
			return line.Split('=')[2];
		}
	}
}
