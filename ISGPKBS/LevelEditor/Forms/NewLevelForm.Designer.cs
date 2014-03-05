namespace LevelEditor.Forms
{
	partial class NewLevelForm
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
			this.widthLabel = new System.Windows.Forms.Label();
			this.heightLabel = new System.Windows.Forms.Label();
			this.createBtn = new System.Windows.Forms.Button();
			this.cancelBtn = new System.Windows.Forms.Button();
			this.widthNum = new System.Windows.Forms.NumericUpDown();
			this.heightNum = new System.Windows.Forms.NumericUpDown();
			((System.ComponentModel.ISupportInitialize)(this.widthNum)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.heightNum)).BeginInit();
			this.SuspendLayout();
			// 
			// widthLabel
			// 
			this.widthLabel.AutoSize = true;
			this.widthLabel.Location = new System.Drawing.Point(13, 16);
			this.widthLabel.Name = "widthLabel";
			this.widthLabel.Size = new System.Drawing.Size(35, 13);
			this.widthLabel.TabIndex = 0;
			this.widthLabel.Text = "Width";
			// 
			// heightLabel
			// 
			this.heightLabel.AutoSize = true;
			this.heightLabel.Location = new System.Drawing.Point(12, 38);
			this.heightLabel.Name = "heightLabel";
			this.heightLabel.Size = new System.Drawing.Size(38, 13);
			this.heightLabel.TabIndex = 1;
			this.heightLabel.Text = "Height";
			// 
			// createBtn
			// 
			this.createBtn.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.createBtn.Location = new System.Drawing.Point(115, 67);
			this.createBtn.Name = "createBtn";
			this.createBtn.Size = new System.Drawing.Size(75, 23);
			this.createBtn.TabIndex = 4;
			this.createBtn.Text = "Create level";
			this.createBtn.UseVisualStyleBackColor = true;
			this.createBtn.Click += new System.EventHandler(this.createBtn_Click);
			// 
			// cancelBtn
			// 
			this.cancelBtn.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.cancelBtn.Location = new System.Drawing.Point(33, 67);
			this.cancelBtn.Name = "cancelBtn";
			this.cancelBtn.Size = new System.Drawing.Size(75, 23);
			this.cancelBtn.TabIndex = 5;
			this.cancelBtn.Text = "Cancel";
			this.cancelBtn.UseVisualStyleBackColor = true;
			this.cancelBtn.Click += new System.EventHandler(this.cancelBtn_Click);
			// 
			// widthNum
			// 
			this.widthNum.Location = new System.Drawing.Point(70, 12);
			this.widthNum.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
			this.widthNum.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
			this.widthNum.Name = "widthNum";
			this.widthNum.Size = new System.Drawing.Size(120, 20);
			this.widthNum.TabIndex = 6;
			this.widthNum.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
			// 
			// heightNum
			// 
			this.heightNum.Location = new System.Drawing.Point(70, 36);
			this.heightNum.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
			this.heightNum.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
			this.heightNum.Name = "heightNum";
			this.heightNum.Size = new System.Drawing.Size(120, 20);
			this.heightNum.TabIndex = 7;
			this.heightNum.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
			// 
			// NewLevelDialog
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(202, 97);
			this.Controls.Add(this.heightNum);
			this.Controls.Add(this.widthNum);
			this.Controls.Add(this.cancelBtn);
			this.Controls.Add(this.createBtn);
			this.Controls.Add(this.heightLabel);
			this.Controls.Add(this.widthLabel);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.Name = "NewLevelDialog";
			this.Text = "New level";
			((System.ComponentModel.ISupportInitialize)(this.widthNum)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.heightNum)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label widthLabel;
		private System.Windows.Forms.Label heightLabel;
		private System.Windows.Forms.Button createBtn;
		private System.Windows.Forms.Button cancelBtn;
		private System.Windows.Forms.NumericUpDown widthNum;
		private System.Windows.Forms.NumericUpDown heightNum;
	}
}