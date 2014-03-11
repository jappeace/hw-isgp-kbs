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
			this.actionBox = new System.Windows.Forms.GroupBox();
			this.rmBtn = new System.Windows.Forms.RadioButton();
			this.addBtn = new System.Windows.Forms.RadioButton();
			this.pointBtn = new System.Windows.Forms.RadioButton();
			this.levelPanel = new LevelEditor.Forms.LevelPanel();
			this.typeBox = new System.Windows.Forms.GroupBox();
			this.tileRadio = new System.Windows.Forms.RadioButton();
			this.ghostRadio = new System.Windows.Forms.RadioButton();
			this.menuStrip.SuspendLayout();
			this.settingsGroup.SuspendLayout();
			this.actionBox.SuspendLayout();
			this.typeBox.SuspendLayout();
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
			this.settingsGroup.Controls.Add(this.typeBox);
			this.settingsGroup.Controls.Add(this.actionBox);
			this.settingsGroup.Location = new System.Drawing.Point(519, 27);
			this.settingsGroup.Name = "settingsGroup";
			this.settingsGroup.Size = new System.Drawing.Size(261, 530);
			this.settingsGroup.TabIndex = 2;
			this.settingsGroup.TabStop = false;
			this.settingsGroup.Text = "Settings";
			// 
			// actionBox
			// 
			this.actionBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.actionBox.Controls.Add(this.rmBtn);
			this.actionBox.Controls.Add(this.addBtn);
			this.actionBox.Controls.Add(this.pointBtn);
			this.actionBox.Location = new System.Drawing.Point(6, 19);
			this.actionBox.Name = "actionBox";
			this.actionBox.Size = new System.Drawing.Size(249, 100);
			this.actionBox.TabIndex = 1;
			this.actionBox.TabStop = false;
			this.actionBox.Text = "Click action";
			// 
			// rmBtn
			// 
			this.rmBtn.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.rmBtn.AutoSize = true;
			this.rmBtn.Location = new System.Drawing.Point(7, 68);
			this.rmBtn.Name = "rmBtn";
			this.rmBtn.Size = new System.Drawing.Size(65, 17);
			this.rmBtn.TabIndex = 2;
			this.rmBtn.TabStop = true;
			this.rmBtn.Text = "Remove";
			this.rmBtn.UseVisualStyleBackColor = true;
			// 
			// addBtn
			// 
			this.addBtn.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.addBtn.AutoSize = true;
			this.addBtn.Location = new System.Drawing.Point(7, 44);
			this.addBtn.Name = "addBtn";
			this.addBtn.Size = new System.Drawing.Size(44, 17);
			this.addBtn.TabIndex = 1;
			this.addBtn.TabStop = true;
			this.addBtn.Text = "Add";
			this.addBtn.UseVisualStyleBackColor = true;
			// 
			// pointBtn
			// 
			this.pointBtn.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.pointBtn.AutoSize = true;
			this.pointBtn.Location = new System.Drawing.Point(7, 20);
			this.pointBtn.Name = "pointBtn";
			this.pointBtn.Size = new System.Drawing.Size(55, 17);
			this.pointBtn.TabIndex = 0;
			this.pointBtn.TabStop = true;
			this.pointBtn.Text = "Select";
			this.pointBtn.UseVisualStyleBackColor = true;
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
			// typeBox
			// 
			this.typeBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.typeBox.Controls.Add(this.ghostRadio);
			this.typeBox.Controls.Add(this.tileRadio);
			this.typeBox.Location = new System.Drawing.Point(7, 126);
			this.typeBox.Name = "typeBox";
			this.typeBox.Size = new System.Drawing.Size(248, 72);
			this.typeBox.TabIndex = 2;
			this.typeBox.TabStop = false;
			this.typeBox.Text = "Type";
			// 
			// tileRadio
			// 
			this.tileRadio.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.tileRadio.AutoSize = true;
			this.tileRadio.Location = new System.Drawing.Point(7, 20);
			this.tileRadio.Name = "tileRadio";
			this.tileRadio.Size = new System.Drawing.Size(42, 17);
			this.tileRadio.TabIndex = 0;
			this.tileRadio.TabStop = true;
			this.tileRadio.Text = "Tile";
			this.tileRadio.UseVisualStyleBackColor = true;
			// 
			// ghostRadio
			// 
			this.ghostRadio.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.ghostRadio.AutoSize = true;
			this.ghostRadio.Location = new System.Drawing.Point(7, 44);
			this.ghostRadio.Name = "ghostRadio";
			this.ghostRadio.Size = new System.Drawing.Size(53, 17);
			this.ghostRadio.TabIndex = 1;
			this.ghostRadio.TabStop = true;
			this.ghostRadio.Text = "Ghost";
			this.ghostRadio.UseVisualStyleBackColor = true;
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
			this.settingsGroup.ResumeLayout(false);
			this.actionBox.ResumeLayout(false);
			this.actionBox.PerformLayout();
			this.typeBox.ResumeLayout(false);
			this.typeBox.PerformLayout();
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
		private System.Windows.Forms.GroupBox actionBox;
		private System.Windows.Forms.RadioButton rmBtn;
		private System.Windows.Forms.RadioButton addBtn;
		private System.Windows.Forms.RadioButton pointBtn;
		private System.Windows.Forms.GroupBox typeBox;
		private System.Windows.Forms.RadioButton ghostRadio;
		private System.Windows.Forms.RadioButton tileRadio;

	}
}

