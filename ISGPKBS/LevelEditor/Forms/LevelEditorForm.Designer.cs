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
			this.levelPanel = new LevelEditor.Forms.LevelPanel();
			this.menuStrip.SuspendLayout();
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
			this.menuStrip.KeyDown += new System.Windows.Forms.KeyEventHandler(this.LevelEditorForm_KeyDown);
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
			this.newLevelToolStripMenuItem.ShortcutKeyDisplayString = "Ctrl + N";
			this.newLevelToolStripMenuItem.Size = new System.Drawing.Size(149, 22);
			this.newLevelToolStripMenuItem.Text = "New";
			this.newLevelToolStripMenuItem.Click += new System.EventHandler(this.newLevelToolStripMenuItem_Click);
			// 
			// loadLevelToolStripMenuItem
			// 
			this.loadLevelToolStripMenuItem.Name = "loadLevelToolStripMenuItem";
			this.loadLevelToolStripMenuItem.ShortcutKeyDisplayString = "Ctrl + O";
			this.loadLevelToolStripMenuItem.Size = new System.Drawing.Size(149, 22);
			this.loadLevelToolStripMenuItem.Text = "Load";
			this.loadLevelToolStripMenuItem.Click += new System.EventHandler(this.loadLevelToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
			this.saveToolStripMenuItem.ShortcutKeyDisplayString = "Ctrl + S";
			this.saveToolStripMenuItem.Size = new System.Drawing.Size(149, 22);
			this.saveToolStripMenuItem.Text = "Save";
			this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
			// 
			// settingsGroup
			// 
			this.settingsGroup.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.settingsGroup.Location = new System.Drawing.Point(519, 27);
			this.settingsGroup.Name = "settingsGroup";
			this.settingsGroup.Size = new System.Drawing.Size(261, 530);
			this.settingsGroup.TabIndex = 2;
			this.settingsGroup.TabStop = false;
			this.settingsGroup.Text = "Settings";
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
			this.levelPanel.SelectedType = LevelEditor.Models.GridObjectType.NPC;
			this.levelPanel.Size = new System.Drawing.Size(501, 530);
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
			this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.LevelEditorForm_KeyDown);
			this.menuStrip.ResumeLayout(false);
			this.menuStrip.PerformLayout();
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
		private LevelPanel levelPanel;

	}
}

