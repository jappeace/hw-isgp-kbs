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

		private void newLevelToolStripMenuItem_Click(object sender, System.EventArgs e)
		{
			var newLevelDialog = new NewLevelDialog();
			if (newLevelDialog.ShowDialog() == DialogResult.OK)
			{
				MessageBox.Show(newLevelDialog.MapWidth + "");
				MessageBox.Show(newLevelDialog.MapHeight + "");
			}
		}
	}
}
