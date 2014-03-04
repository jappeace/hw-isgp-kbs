using System;
using System.Windows.Forms;

namespace LevelEditor.Forms
{
	public partial class NewLevelDialog : Form
	{
		/// <summary>
		/// Width set by the user.
		/// </summary>
		public int MapWidth
		{
			get { return (int)widthNum.Value; }
		}

		/// <summary>
		/// Height set by the user.
		/// </summary>
		public int MapHeight
		{
			get { return (int)heightNum.Value; }
		}

		public NewLevelDialog()
		{
			InitializeComponent();
		}

		/// <summary>
		/// Action fired when the user clicks on "Create level"
		/// </summary>
		private void createBtn_Click(object sender, EventArgs e)
		{
			DialogResult = DialogResult.OK;
			Dispose();
		}

		/// <summary>
		/// Action fired when the user clicks on "Cancel"
		/// </summary>
		private void cancelBtn_Click(object sender, EventArgs e)
		{
			DialogResult = DialogResult.Cancel;
			Dispose();
		}
	}
}
