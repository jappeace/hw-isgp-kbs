using System.Drawing;
using System.Windows.Forms;
using LevelEditor.Models;

namespace LevelEditor.Forms
{
	class LevelPanel : Panel
	{
		/// <summary>
		/// The level that will be displayed by the panel.
		/// </summary>
		public ILevel Level
		{
			get { return _level; }
			set
			{
				if (value != null)
				{
					// Set size for scrollbars.
					AutoScrollMinSize = new Size(
						value.Width * GridSize, value.Height * GridSize);
					_level = value;
				}
			}
		}

		private ILevel _level;
		private Pen _gridPen;

		private const int GridSize = 16;
		private const int GridLineWidth = 1;

		public LevelPanel()
		{
			// Enable double buffering for a smoother user experience.
			DoubleBuffered = true;
			// Enable scrollbars.
			AutoScroll = true;
			BackColor = Color.Red;
			_gridPen = new Pen(Color.Black, GridLineWidth);
		}

		/// <summary>
		/// Draws the level on the panel if the level isn't null.
		/// </summary>
		protected override void OnPaint(PaintEventArgs e)
		{
			if (Level != null)
			{
				DrawGrid(e.Graphics);
			}
		}

		/// <summary>
		/// Draws the grid.
		/// </summary>
		private void DrawGrid(Graphics g)
		{
			g.FillEllipse(new SolidBrush(Color.Red), 1000, 100, 1000, 100);

			// Draw horizontal lines.
			for (int i = 0; i < Level.Height; i++)
			{
				g.DrawLine(_gridPen, 0, i * GridSize,
					Level.Width * GridSize, i * GridSize);
			}

			// Draw vertical lines.
			for (int i = 0; i < Level.Width; i++)
			{
				g.DrawLine(_gridPen, i * GridSize, 0,
					i * GridSize, Level.Height * GridSize);
			}

			// Draw bottom line.
			g.DrawLine(_gridPen, 0, Level.Height * GridSize,
				Level.Width * GridSize, Level.Height * GridSize);

			// Draw right line.
			g.DrawLine(_gridPen, Level.Width * GridSize, 0,
				Level.Width * GridSize, Level.Height * GridSize);
		}
	}
}
