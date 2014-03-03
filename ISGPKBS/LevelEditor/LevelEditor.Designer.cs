namespace LevelEditor
{
	partial class LevelEditor
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
			this.levelPanel = new System.Windows.Forms.Panel();
			this.SuspendLayout();
			// 
			// levelPanel
			// 
			this.levelPanel.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.levelPanel.BackColor = System.Drawing.SystemColors.ButtonShadow;
			this.levelPanel.Location = new System.Drawing.Point(12, 12);
			this.levelPanel.Name = "levelPanel";
			this.levelPanel.Size = new System.Drawing.Size(361, 261);
			this.levelPanel.TabIndex = 0;
			// 
			// LevelEditor
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(688, 521);
			this.Controls.Add(this.levelPanel);
			this.Name = "LevelEditor";
			this.Text = "Megadude++ Leveleditor";
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Panel levelPanel;
	}
}

