using System.Drawing;
using System.Windows.Forms;

namespace LevelEditor
{
	/// <summary>
	/// Main form where the user can import, edit, and export levels.
	/// </summary>
	public partial class LevelEditor : Form
	{
		public LevelEditor()
		{
			InitializeComponent();
		}

		protected override void OnPaint(PaintEventArgs e)
		{
			
			levelPanel.CreateGraphics().FillEllipse(new SolidBrush(Color.Red), 100, 100, 10000, 10000);
			base.OnPaint(e);
		}

		private void loadToolStripMenuItem_Click(object sender, System.EventArgs e)
		{

		}
	}
}
