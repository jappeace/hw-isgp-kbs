﻿using System;
using System.Collections.Generic;
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
					Invalidate();
				}
			}
		}

		public GridObjectType SelectedType { get; set; }
		public MouseAction MouseAction { get; set; }

		public Point SelectedPoint { get; set; }

		private ILevel _level;
		private Pen _gridPen;
		private Pen _selectedPen;

		private const int GridLineWidth = 1;
		private const int GridSize = 16 + GridLineWidth;

		public LevelPanel()
		{
			MouseAction = MouseAction.Select;
			// Enable double buffering for a smoother user experience.
			DoubleBuffered = true;
			// Enable scrollbars.
			AutoScroll = true;
			BackColor = Color.Red;
			_gridPen = new Pen(Color.Black, GridLineWidth);
			_selectedPen = new Pen(Color.Blue, GridLineWidth * 2);
			Scroll += OnScroll;
			MouseClick += levelPanel_MouseClick;
			MouseMove += LevelPanel_MouseMove;
			MouseDown += LevelPanel_MouseDown;
			MouseUp += LevelPanel_MouseUp;
		}

		private bool _mouseDown = false;

		private void levelPanel_MouseClick(object sender, MouseEventArgs e)
		{
			if (_level == null)
			{
				return;
			}
			if (e.Button == MouseButtons.Left)
			{
				if (MouseAction == MouseAction.Select)
				{
					Point pos = PanelToGridLocation(e.Location);
					if (pos.X < Level.Width && pos.Y < Level.Height)
					{
						SelectedPoint = PanelToGridLocation(e.Location);
					}
				}
				if (MouseAction == MouseAction.Remove)
				{
					_level.RemoveGridObject(PanelToGridLocation(e.Location));
				}
				if (MouseAction == MouseAction.Add)
				{
					_level.SetGridObject(PanelToGridLocation(e.Location),
						new GridObject(SelectedType));
				}
				if (MouseAction == MouseAction.Start)
				{
					Level.Start = PanelToGridLocation(e.Location);
				}
				if (MouseAction == MouseAction.Finish)
				{
					Level.Finish = PanelToGridLocation(e.Location);
				}
			}

			Invalidate();
		}

		private Point PanelToGridLocation(Point panelLocation)
		{
			// Adjust coordinates according to the position of the scrollbar.
			panelLocation.X -= AutoScrollPosition.X;
			panelLocation.Y -= AutoScrollPosition.Y;

			Point gridLocation = new Point();
			gridLocation.X = panelLocation.X / GridSize;
			gridLocation.Y = panelLocation.Y / GridSize;
			return gridLocation;
		}

		private void OnScroll(object sender, ScrollEventArgs args)
		{
			Invalidate();
		}


		/// <summary>
		/// Draws the level on the panel if the level isn't null.
		/// </summary>
		protected override void OnPaint(PaintEventArgs e)
		{
			if (Level != null)
			{
				e.Graphics.TranslateTransform(AutoScrollPosition.X, AutoScrollPosition.Y);
				DrawGrid(e.Graphics);
				DrawTiles(e.Graphics);
			}
		}

		/// <summary>
		/// Draws the grid.
		/// </summary>
		private void DrawGrid(Graphics g)
		{
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

			// Draw selection.
			if (SelectedPoint.X != -1)
			{
				g.DrawRectangle(_selectedPen, SelectedPoint.X * GridSize,
					SelectedPoint.Y * GridSize, GridSize, GridSize);
			}
		}

		private void DrawTiles(Graphics g)
		{
			Brush tileBrush;
			foreach (KeyValuePair<Point, GridObject> pair in Level.GridObjects)
			{
				if (pair.Value.Type == GridObjectType.Tile)
				{
					tileBrush = new SolidBrush(Color.Black);
				}
				else if (pair.Value.Type == GridObjectType.Ghost)
				{
					tileBrush = new SolidBrush(Color.Gray);
				}
				else if (pair.Value.Type == GridObjectType.GravityBoots)
				{
					tileBrush = new SolidBrush(Color.Gold);
				}
				else if (pair.Value.Type == GridObjectType.JumpPlatform)
				{
					tileBrush = new SolidBrush(Color.HotPink);
				}
				else
				{
					tileBrush = new SolidBrush(Color.Brown);
				}
				g.FillRectangle(tileBrush, pair.Key.X * GridSize + GridLineWidth,
					pair.Key.Y * GridSize + GridLineWidth,
					GridSize - GridLineWidth, GridSize - GridLineWidth);
			}
			g.FillRectangle(new SolidBrush(Color.Green), Level.Start.X * GridSize + GridLineWidth,
				Level.Start.Y * GridSize + GridLineWidth,
				GridSize - GridLineWidth, GridSize - GridLineWidth);
			g.FillRectangle(new SolidBrush(Color.Red), Level.Finish.X * GridSize + GridLineWidth,
				Level.Finish.Y * GridSize + GridLineWidth,
				GridSize - GridLineWidth, GridSize - GridLineWidth);
		}

		private void InitializeComponent()
		{
			this.SuspendLayout();
			// 
			// LevelPanel
			// 
			this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.LevelPanel_MouseDown);
			this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.LevelPanel_MouseMove);
			this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.LevelPanel_MouseUp);
			this.ResumeLayout(false);

		}

		private void LevelPanel_MouseMove(object sender, MouseEventArgs e)
		{
			if (_mouseDown)
			{
				if (e.Button == MouseButtons.Right || MouseAction == MouseAction.Remove)
				{
					_level.RemoveGridObject(PanelToGridLocation(e.Location));
				}
				else if (MouseAction == MouseAction.Add)
				{
					_level.SetGridObject(PanelToGridLocation(e.Location),
						new GridObject(SelectedType));
				}
				Invalidate();
			}
		}

		private void LevelPanel_MouseUp(object sender, MouseEventArgs e)
		{
			_mouseDown = false;
		}

		private void LevelPanel_MouseDown(object sender, MouseEventArgs e)
		{
			_mouseDown = true;
		}
	}
}
