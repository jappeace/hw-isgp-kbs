namespace LevelEditor.Forms
{
	partial class LevelEditorForm
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.menuStrip = new System.Windows.Forms.MenuStrip();
			this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.newLevelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.loadLevelToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.settingsGroup = new System.Windows.Forms.GroupBox();
			this.spriteBox = new System.Windows.Forms.PictureBox();
			this.tileTypeLabel = new System.Windows.Forms.Label();
			this.spritePicker = new System.Windows.Forms.ComboBox();
			this.levelPanel = new LevelEditor.Forms.LevelPanel();
			this.menuStrip.SuspendLayout();
			this.settingsGroup.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.spriteBox)).BeginInit();
			this.SuspendLayout();
			// 
			// menuStrip
			// 
			this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
			this.menuStrip.Location = new System.Drawing.Point(0, 0);
			this.menuStrip.Name = "menuStrip";
			this.menuStrip.Size = new System.Drawing.Size(792, 24);
			this.menuStrip.TabIndex = 1;
			this.menuStrip.Text = "menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newLevelToolStripMenuItem,
            this.loadLevelToolStripMenuItem,
            this.saveToolStripMenuItem});
			this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
			this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
			this.fileToolStripMenuItem.Text = "File";
			// 
			// newLevelToolStripMenuItem
			// 
			this.newLevelToolStripMenuItem.Name = "newLevelToolStripMenuItem";
			this.newLevelToolStripMenuItem.Size = new System.Drawing.Size(100, 22);
			this.newLevelToolStripMenuItem.Text = "New";
			this.newLevelToolStripMenuItem.Click += new System.EventHandler(this.newLevelToolStripMenuItem_Click);
			// 
			// loadLevelToolStripMenuItem
			// 
			this.loadLevelToolStripMenuItem.Name = "loadLevelToolStripMenuItem";
			this.loadLevelToolStripMenuItem.Size = new System.Drawing.Size(100, 22);
			this.loadLevelToolStripMenuItem.Text = "Load";
			this.loadLevelToolStripMenuItem.Click += new System.EventHandler(this.loadLevelToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
			this.saveToolStripMenuItem.Size = new System.Drawing.Size(100, 22);
			this.saveToolStripMenuItem.Text = "Save";
			this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
			// 
			// settingsGroup
			// 
			this.settingsGroup.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.settingsGroup.Controls.Add(this.spriteBox);
			this.settingsGroup.Controls.Add(this.tileTypeLabel);
			this.settingsGroup.Controls.Add(this.spritePicker);
			this.settingsGroup.Location = new System.Drawing.Point(583, 27);
			this.settingsGroup.Name = "settingsGroup";
			this.settingsGroup.Size = new System.Drawing.Size(197, 530);
			this.settingsGroup.TabIndex = 2;
			this.settingsGroup.TabStop = false;
			this.settingsGroup.Text = "Settings";
			// 
			// spriteBox
			// 
			this.spriteBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.spriteBox.Location = new System.Drawing.Point(172, 38);
			this.spriteBox.Name = "spriteBox";
			this.spriteBox.Size = new System.Drawing.Size(16, 16);
			this.spriteBox.TabIndex = 2;
			this.spriteBox.TabStop = false;
			// 
			// tileTypeLabel
			// 
			this.tileTypeLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.tileTypeLabel.AutoSize = true;
			this.tileTypeLabel.Location = new System.Drawing.Point(7, 20);
			this.tileTypeLabel.Name = "tileTypeLabel";
			this.tileTypeLabel.Size = new System.Drawing.Size(47, 13);
			this.tileTypeLabel.TabIndex = 1;
			this.tileTypeLabel.Text = "Tile type";
			// 
			// spritePicker
			// 
			this.spritePicker.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.spritePicker.FormattingEnabled = true;
			this.spritePicker.Location = new System.Drawing.Point(6, 36);
			this.spritePicker.Name = "spritePicker";
			this.spritePicker.Size = new System.Drawing.Size(160, 21);
			this.spritePicker.TabIndex = 0;
			this.spritePicker.SelectedIndexChanged += new System.EventHandler(this.spritePicker_SelectedIndexChanged);
			// 
			// levelPanel
			// 
			this.levelPanel.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.levelPanel.AutoScroll = true;
			this.levelPanel.BackColor = System.Drawing.SystemColors.ControlLightLight;
			this.levelPanel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
			this.levelPanel.Level = null;
			this.levelPanel.Location = new System.Drawing.Point(12, 27);
			this.levelPanel.Name = "levelPanel";
			this.levelPanel.SelectedType = LevelEditor.Models.TileType.Start;
			this.levelPanel.Size = new System.Drawing.Size(565, 530);
			this.levelPanel.TabIndex = 3;
			// 
			// LevelEditorForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(792, 569);
			this.Controls.Add(this.levelPanel);
			this.Controls.Add(this.settingsGroup);
			this.Controls.Add(this.menuStrip);
			this.MainMenuStrip = this.menuStrip;
			this.MinimumSize = new System.Drawing.Size(800, 600);
			this.Name = "LevelEditorForm";
			this.Text = "Megadude++ Leveleditor";
			this.menuStrip.ResumeLayout(false);
			this.menuStrip.PerformLayout();
			this.settingsGroup.ResumeLayout(false);
			this.settingsGroup.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.spriteBox)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.MenuStrip menuStrip;
		private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem newLevelToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem loadLevelToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
		private System.Windows.Forms.GroupBox settingsGroup;
		private System.Windows.Forms.ComboBox spritePicker;
		private System.Windows.Forms.Label tileTypeLabel;
		private System.Windows.Forms.PictureBox spriteBox;
		private LevelPanel levelPanel;

	}
}

