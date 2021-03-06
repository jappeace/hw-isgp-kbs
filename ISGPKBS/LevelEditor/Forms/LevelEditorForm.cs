﻿using System;
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
		public LevelEditorForm()
		{
			InitializeComponent();
			Init();
		}

		private void Init()
		{
			KeyPreview = true;
		}

		/// <summary>
		/// Event for new level menu item. Allows user to create a new level.
		/// </summary>
		private void newLevelToolStripMenuItem_Click(object sender, EventArgs e)
		{
			NewLevelDialog();
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
			NewLevelForm dialog = new NewLevelForm();
			if (dialog.ShowDialog() == DialogResult.OK)
			{
				levelPanel.Level = new Level(dialog.MapWidth, dialog.MapHeight);
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

		private void addBtn_CheckedChanged(object sender, EventArgs e)
		{
			ChangeMouseAction();
		}

		private void pointBtn_CheckedChanged(object sender, EventArgs e)
		{
			ChangeMouseAction();
		}

		private void rmBtn_CheckedChanged(object sender, EventArgs e)
		{
			ChangeMouseAction();
		}

		private void startRadio_CheckedChanged(object sender, EventArgs e)
		{
			ChangeMouseAction();
		}

		private void finishRadio_CheckedChanged(object sender, EventArgs e)
		{

		}

		private void ChangeMouseAction()
		{
			if (!selectRadio.Checked)
			{
				levelPanel.SelectedPoint = new Point(-1, -1);
			}

			if (selectRadio.Checked)
			{
				levelPanel.MouseAction = MouseAction.Select;
			}
			else if (addRadio.Checked)
			{
				levelPanel.MouseAction = MouseAction.Add;
			}
			else if (startRadio.Checked)
			{
				levelPanel.MouseAction = MouseAction.Start;
			}
			else if (finishRadio.Checked)
			{
				levelPanel.MouseAction = MouseAction.Finish;
			}
			else
			{
				levelPanel.MouseAction = MouseAction.Remove;
			}
			levelPanel.Invalidate();
		}

		private void tileRadio_CheckedChanged(object sender, EventArgs e)
		{
			ChangeType();
		}

		private void ghostRadio_CheckedChanged(object sender, EventArgs e)
		{
			ChangeType();
		}

		private void gravityBootsRadio_CheckedChanged(object sender, EventArgs e)
		{
			ChangeType();
		}

		private void jumpPlatformRadio_CheckedChanged(object sender, EventArgs e)
		{
			ChangeType();
		}

		private void ChangeType()
		{
			if (ghostRadio.Checked)
			{
				levelPanel.SelectedType = GridObjectType.Ghost;
			}
			else if (tileRadio.Checked)
			{
				levelPanel.SelectedType = GridObjectType.Tile;
			}
			else if (patrolRadio.Checked)
			{
				levelPanel.SelectedType = GridObjectType.Patrol;
			}
			else if (gravityBootsRadio.Checked)
			{
				levelPanel.SelectedType = GridObjectType.GravityBoots;
			}
			else if (jumpPlatformRadio.Checked)
			{
				levelPanel.SelectedType = GridObjectType.JumpPlatform;
			}

			if (levelPanel.SelectedPoint.X != -1)
			{
				levelPanel.Level.SetGridObject(levelPanel.SelectedPoint,
					new GridObject(levelPanel.SelectedType));
				levelPanel.Invalidate();
			}
		}

	}
}
