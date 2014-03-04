using System;
using System.Drawing;
using System.Windows.Forms;
using LevelEditor.Models;

namespace LevelEditor.Forms
{
	/// <summary>
	/// Main form where the user can import, edit, and export levels.
	/// </summary>
	public partial class LevelEditorForm : Form
	{
		private ILevel _level;

		public LevelEditorForm()
		{
			InitializeComponent();
		}

		/// <summary>
		/// Event for new level menu item. Allows user to create a new level.
		/// </summary>
		private void newLevelToolStripMenuItem_Click(object sender, EventArgs e)
		{
			var newLevelDialog = new NewLevelDialog();
			if (newLevelDialog.ShowDialog() == DialogResult.OK)
			{
				_level = new Level(newLevelDialog.MapWidth,
					newLevelDialog.MapHeight);
			}
		}
	}
}
