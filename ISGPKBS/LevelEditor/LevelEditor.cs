﻿using System;
using System.Drawing;
using System.Windows.Forms;

namespace LevelEditor
{
	/// <summary>
	/// Main form where the user can import, edit, and export levels.
	/// </summary>
	public partial class LevelEditor : Form
	{
		private ILevel _level;

		public LevelEditor()
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
