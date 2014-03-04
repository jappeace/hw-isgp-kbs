﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LevelEditor
{
	public partial class NewLevelDialog : Form
	{
		public NewLevelDialog()
		{
			InitializeComponent();
		}

		private void createBtn_Click(object sender, EventArgs e)
		{
			DialogResult = DialogResult.OK;
			Dispose();
		}

		private void cancelBtn_Click(object sender, EventArgs e)
		{
			DialogResult = DialogResult.Cancel;
			Dispose();
		}
	}
}
