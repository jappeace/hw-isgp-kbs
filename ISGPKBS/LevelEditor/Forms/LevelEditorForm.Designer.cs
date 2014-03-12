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
			this.typeBox = new System.Windows.Forms.GroupBox();
			this.ghostRadio = new System.Windows.Forms.RadioButton();
			this.tileRadio = new System.Windows.Forms.RadioButton();
			this.actionBox = new System.Windows.Forms.GroupBox();
			this.startRadio = new System.Windows.Forms.RadioButton();
			this.rmRadio = new System.Windows.Forms.RadioButton();
			this.addRadio = new System.Windows.Forms.RadioButton();
			this.selectRadio = new System.Windows.Forms.RadioButton();
			this.finishRadio = new System.Windows.Forms.RadioButton();
			this.levelPanel = new LevelEditor.Forms.LevelPanel();
			this.patrolRadio = new System.Windows.Forms.RadioButton();
			this.menuStrip.SuspendLayout();
			this.settingsGroup.SuspendLayout();
			this.typeBox.SuspendLayout();
			this.actionBox.SuspendLayout();
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
			// typeBox
			// 
			this.typeBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.typeBox.Controls.Add(this.patrolRadio);
			this.typeBox.Controls.Add(this.ghostRadio);
			this.typeBox.Controls.Add(this.tileRadio);
			this.typeBox.Location = new System.Drawing.Point(7, 174);
			this.typeBox.Name = "typeBox";
			this.typeBox.Size = new System.Drawing.Size(248, 107);
			this.typeBox.TabIndex = 2;
			this.typeBox.TabStop = false;
			this.typeBox.Text = "Type";
			// 
			// ghostRadio
			// 
			this.ghostRadio.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.ghostRadio.AutoSize = true;
			this.ghostRadio.Location = new System.Drawing.Point(7, 45);
			this.ghostRadio.Name = "ghostRadio";
			this.ghostRadio.Size = new System.Drawing.Size(53, 17);
			this.ghostRadio.TabIndex = 1;
			this.ghostRadio.Text = "Ghost";
			this.ghostRadio.UseVisualStyleBackColor = true;
			this.ghostRadio.CheckedChanged += new System.EventHandler(this.ghostRadio_CheckedChanged);
			// 
			// tileRadio
			// 
			this.tileRadio.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.tileRadio.AutoSize = true;
			this.tileRadio.Checked = true;
			this.tileRadio.Location = new System.Drawing.Point(7, 21);
			this.tileRadio.Name = "tileRadio";
			this.tileRadio.Size = new System.Drawing.Size(42, 17);
			this.tileRadio.TabIndex = 0;
			this.tileRadio.TabStop = true;
			this.tileRadio.Text = "Tile";
			this.tileRadio.UseVisualStyleBackColor = true;
			this.tileRadio.CheckedChanged += new System.EventHandler(this.tileRadio_CheckedChanged);
			// 
			// actionBox
			// 
			this.actionBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.actionBox.Controls.Add(this.finishRadio);
			this.actionBox.Controls.Add(this.startRadio);
			this.actionBox.Controls.Add(this.rmRadio);
			this.actionBox.Controls.Add(this.addRadio);
			this.actionBox.Controls.Add(this.selectRadio);
			this.actionBox.Location = new System.Drawing.Point(6, 19);
			this.actionBox.Name = "actionBox";
			this.actionBox.Size = new System.Drawing.Size(249, 149);
			this.actionBox.TabIndex = 1;
			this.actionBox.TabStop = false;
			this.actionBox.Text = "Click action";
			// 
			// startRadio
			// 
			this.startRadio.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.startRadio.AutoSize = true;
			this.startRadio.Location = new System.Drawing.Point(7, 92);
			this.startRadio.Name = "startRadio";
			this.startRadio.Size = new System.Drawing.Size(47, 17);
			this.startRadio.TabIndex = 3;
			this.startRadio.TabStop = true;
			this.startRadio.Text = "Start";
			this.startRadio.UseVisualStyleBackColor = true;
			this.startRadio.CheckedChanged += new System.EventHandler(this.startRadio_CheckedChanged);
			// 
			// rmRadio
			// 
			this.rmRadio.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.rmRadio.AutoSize = true;
			this.rmRadio.Location = new System.Drawing.Point(7, 68);
			this.rmRadio.Name = "rmRadio";
			this.rmRadio.Size = new System.Drawing.Size(65, 17);
			this.rmRadio.TabIndex = 2;
			this.rmRadio.Text = "Remove";
			this.rmRadio.UseVisualStyleBackColor = true;
			this.rmRadio.CheckedChanged += new System.EventHandler(this.rmBtn_CheckedChanged);
			// 
			// addRadio
			// 
			this.addRadio.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.addRadio.AutoSize = true;
			this.addRadio.Location = new System.Drawing.Point(7, 44);
			this.addRadio.Name = "addRadio";
			this.addRadio.Size = new System.Drawing.Size(44, 17);
			this.addRadio.TabIndex = 1;
			this.addRadio.Text = "Add";
			this.addRadio.UseVisualStyleBackColor = true;
			this.addRadio.CheckedChanged += new System.EventHandler(this.addBtn_CheckedChanged);
			// 
			// selectRadio
			// 
			this.selectRadio.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.selectRadio.AutoSize = true;
			this.selectRadio.Checked = true;
			this.selectRadio.Location = new System.Drawing.Point(7, 20);
			this.selectRadio.Name = "selectRadio";
			this.selectRadio.Size = new System.Drawing.Size(55, 17);
			this.selectRadio.TabIndex = 0;
			this.selectRadio.TabStop = true;
			this.selectRadio.Text = "Select";
			this.selectRadio.UseVisualStyleBackColor = true;
			this.selectRadio.CheckedChanged += new System.EventHandler(this.pointBtn_CheckedChanged);
			// 
			// finishRadio
			// 
			this.finishRadio.AutoSize = true;
			this.finishRadio.Location = new System.Drawing.Point(8, 116);
			this.finishRadio.Name = "finishRadio";
			this.finishRadio.Size = new System.Drawing.Size(52, 17);
			this.finishRadio.TabIndex = 4;
			this.finishRadio.TabStop = true;
			this.finishRadio.Text = "Finish";
			this.finishRadio.UseVisualStyleBackColor = true;
			this.finishRadio.CheckedChanged += new System.EventHandler(this.finishRadio_CheckedChanged);
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
			this.levelPanel.MouseAction = LevelEditor.Models.MouseAction.Select;
			this.levelPanel.Name = "levelPanel";
			this.levelPanel.SelectedPoint = new System.Drawing.Point(0, 0);
			this.levelPanel.SelectedType = LevelEditor.Models.GridObjectType.Tile;
			this.levelPanel.Size = new System.Drawing.Size(501, 530);
			this.levelPanel.TabIndex = 3;
			// 
			// patrolRadio
			// 
			this.patrolRadio.AutoSize = true;
			this.patrolRadio.Location = new System.Drawing.Point(7, 68);
			this.patrolRadio.Name = "patrolRadio";
			this.patrolRadio.Size = new System.Drawing.Size(52, 17);
			this.patrolRadio.TabIndex = 2;
			this.patrolRadio.TabStop = true;
			this.patrolRadio.Text = "Patrol";
			this.patrolRadio.UseVisualStyleBackColor = true;
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
			this.typeBox.ResumeLayout(false);
			this.typeBox.PerformLayout();
			this.actionBox.ResumeLayout(false);
			this.actionBox.PerformLayout();
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
		private System.Windows.Forms.RadioButton rmRadio;
		private System.Windows.Forms.RadioButton addRadio;
		private System.Windows.Forms.RadioButton selectRadio;
		private System.Windows.Forms.GroupBox typeBox;
		private System.Windows.Forms.RadioButton ghostRadio;
		private System.Windows.Forms.RadioButton tileRadio;
		private System.Windows.Forms.RadioButton startRadio;
		private System.Windows.Forms.RadioButton finishRadio;
		private System.Windows.Forms.RadioButton patrolRadio;

	}
}

