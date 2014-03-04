using System.Drawing;
using System.Windows.Forms;

namespace LevelEditor.Forms
{
	class LevelPanel : Panel
	{
		public LevelPanel()
		{
			// Enable double buffering for a smoother user experience.
			DoubleBuffered = true;
			// Enable scrollbars.
			AutoScroll = true;
			BackColor = Color.AliceBlue;
		}

		/// <summary>
		/// Draws the level on the panel.
		/// </summary>
		/// <param name="e"></param>
		protected override void OnPaint(PaintEventArgs e)
		{
			base.OnPaint(e);
		}
	}
}
