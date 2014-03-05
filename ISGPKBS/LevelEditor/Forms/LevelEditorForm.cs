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
			KeyPreview = true;
			spritePicker.DataSource = Enum.GetNames(typeof(TileType));
		}

		/// <summary>
		/// Event for new level menu item. Allows user to create a new level.
		/// </summary>
		private void newLevelToolStripMenuItem_Click(object sender, EventArgs e)
		{
			NewLevelDialog();
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
			SaveLevelDialog();
		}

		private void loadLevelToolStripMenuItem_Click(object sender, EventArgs e)
		{
			LoadLevelDialog();
		}

		/// <summary>
		/// Show a filedialog to save the level. An error will show if there
		/// is no level to save.
		/// </summary>
		private void SaveLevelDialog()
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
		/// Will show an error message if the file is not a valid level file.
		/// </summary>
		private void LoadLevelDialog()
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

		private void NewLevelDialog()
		{
			var newLevelDialog = new NewLevelForm();
			if (newLevelDialog.ShowDialog() == DialogResult.OK)
			{
				levelPanel.Level = new Level(newLevelDialog.MapWidth,
					newLevelDialog.MapHeight);
				levelPanel.Invalidate();
			}
		}

		/// <summary>
		/// Keyboard hotkeys
		/// </summary>
		private void LevelEditorForm_KeyDown(object sender, KeyEventArgs e)
		{
			// Control key must be pressed.
			if (e.Control)
			{
				switch (e.KeyCode)
				{
					case Keys.S:
						SaveLevelDialog();
						break;
					case Keys.O:
						LoadLevelDialog();
						break;
					case Keys.N:
						NewLevelDialog();
						break;
				}
			}
		}
	}
}
