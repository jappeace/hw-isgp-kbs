﻿using System.Collections.Generic;
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

		public TileType SelectedType { get; set; }

		private ILevel _level;
		private Pen _gridPen;

		private const int GridLineWidth = 1;
		private const int GridSize = 16 + GridLineWidth;

		public LevelPanel()
		{
			// Enable double buffering for a smoother user experience.
			DoubleBuffered = true;
			// Enable scrollbars.
			AutoScroll = true;
			BackColor = Color.Red;
			_gridPen = new Pen(Color.Black, GridLineWidth);
			Scroll += OnScroll;
			MouseClick += levelPanel_MouseClick;
		}

		private void levelPanel_MouseClick(object sender, MouseEventArgs e)
		{
			if (Level != null)
			{
				Point gridLocation = PanelToGridLocation(e.Location);
				if (e.Button == MouseButtons.Left)
				{
					Level.SetTile(gridLocation, SelectedType);
				}
				else if (e.Button == MouseButtons.Right)
				{
					Level.RemoveTile(gridLocation);
				}
				Invalidate();
			}
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
		}

		private void DrawTiles(Graphics g)
		{
			IDictionary<Point, TileType> tiles = Level.GetTiles();
			Point gridLocation;
			Bitmap bitmap;
			foreach (Point point in tiles.Keys)
			{
				gridLocation = new Point(point.X * GridSize, point.Y * GridSize);
				gridLocation.X += (GridLineWidth + 1) / 2;
				gridLocation.Y += (GridLineWidth + 1) / 2;
				bitmap = BitmapCollection.GetBitmapForType(tiles[point]);
				g.DrawImage(bitmap, gridLocation);
			}
			gridLocation = new Point(Level.Start.X * GridSize, Level.Start.Y * GridSize);
			gridLocation.X += (GridLineWidth + 1) / 2;
			gridLocation.Y += (GridLineWidth + 1) / 2;
			bitmap = BitmapCollection.GetBitmapForType(TileType.Start);
			g.DrawImage(bitmap, gridLocation);
			gridLocation = new Point(Level.Finish.X * GridSize, Level.Finish.Y * GridSize);
			gridLocation.X += (GridLineWidth + 1) / 2;
			gridLocation.Y += (GridLineWidth + 1) / 2;
			bitmap = BitmapCollection.GetBitmapForType(TileType.Finish);
			g.DrawImage(bitmap, gridLocation);
		}
	}
}