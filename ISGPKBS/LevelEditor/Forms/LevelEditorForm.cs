using System;
using System.Drawing;
using System.IO;
using System.Windows.Forms;
using LevelEditor.Models;
using LevelEditor.Models.IO;

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

		/// <summary>
		/// Show a filedialog to save the level. An error will show if there
		/// is no level to save.
		/// </summary>
		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (levelPanel.Level != null)
			{
				FileDialog dialog = new SaveFileDialog();
				dialog.AddExtension = true;
				dialog.Filter = "Level files (*.level)|*.level";
				if (dialog.ShowDialog() == DialogResult.OK)
				{
					ILevelExporter levelExporter = new LevelExporter(dialog.FileName);
					levelExporter.ExportLevel(levelPanel.Level);
				}
			}
			else
			{
				// No level to save.
				MessageBox.Show("There is nothing to save!", "Cannot save level",
					MessageBoxButtons.OK, MessageBoxIcon.Error);
			}
		}

		/// <summary>
		/// Shows a filedialog to load a level.
		/// </summary>
		private void loadLevelToolStripMenuItem_Click(object sender, EventArgs e)
		{
			FileDialog dialog = new OpenFileDialog();
			dialog.Filter = "Level files (*.level)|*.level";
			if (dialog.ShowDialog() == DialogResult.OK)
			{
				ILevelImporter levelImporter = new LevelImporter(dialog.FileName);
				try
				{
					levelPanel.Level = levelImporter.ImportLevel();
				}
				catch (ArgumentException ex)
				{
					MessageBox.Show(ex.Message, "Cannot load level",
						MessageBoxButtons.OK, MessageBoxIcon.Error);
				}
			}
		}
	}
}
