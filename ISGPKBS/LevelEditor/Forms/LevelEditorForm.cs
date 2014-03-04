using System;
using System.Drawing;
using System.IO;
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
			Init();
		}

		private void Init()
		{
			spritePicker.DataSource = Enum.GetNames(typeof(TileType));
		}

		/// <summary>
		/// Event for new level menu item. Allows user to create a new level.
		/// </summary>
		private void newLevelToolStripMenuItem_Click(object sender, EventArgs e)
		{
			var newLevelDialog = new NewLevelDialog();
			if (newLevelDialog.ShowDialog() == DialogResult.OK)
			{
				levelPanel.Level = new Level(newLevelDialog.MapWidth,
					newLevelDialog.MapHeight);
				levelPanel.Invalidate();
			}
		}

		private void spritePicker_SelectedIndexChanged(object sender, EventArgs e)
		{
			TileType selectedType = (TileType)Enum.Parse(typeof(TileType), spritePicker.Text);
			levelPanel.SelectedType = selectedType;
			Bitmap bitmap;
			try
			{
				bitmap = BitmapCollection.GetBitmapForType(selectedType);
			}
			catch (FileNotFoundException)
			{
				bitmap = new Bitmap(64, 64);
			}
			spriteBox.Image = bitmap;
		}

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (levelPanel.Level != null)
			{
				FileDialog dialog = new SaveFileDialog();
				dialog.AddExtension = true;
				dialog.Filter = "Level files (*.level)|*.level";
				dialog.ShowDialog();
			}
			else
			{
				// No level to save.
				MessageBox.Show("There is nothing to save!", "Cannot save level",
					MessageBoxButtons.OK, MessageBoxIcon.Error);
			}
		}

		private void loadLevelToolStripMenuItem_Click(object sender, EventArgs e)
		{
			// TODO: Load level.
		}
	}
}
