namespace GFX_FONT_GEN
{
    partial class MainForm
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.FontComboBox = new System.Windows.Forms.ComboBox();
            this.FontSize = new System.Windows.Forms.NumericUpDown();
            this.OutputTextBox = new System.Windows.Forms.TextBox();
            this.FormUpdateTimer = new System.Windows.Forms.Timer(this.components);
            this.OutputFolder = new System.Windows.Forms.TextBox();
            this.FontBaseName = new System.Windows.Forms.TextBox();
            this.TargetFolderLabel = new System.Windows.Forms.Label();
            this.FontNameLabel = new System.Windows.Forms.Label();
            this.InitFontButton = new System.Windows.Forms.Button();
            this.InitFontHeight = new System.Windows.Forms.NumericUpDown();
            this.InitFontWidth = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.BuildFontButton = new System.Windows.Forms.Button();
            this.GenerateTT_FontData = new System.Windows.Forms.Button();
            this.BuiladAll_TT_Button = new System.Windows.Forms.Button();
            this.StartingPx = new System.Windows.Forms.NumericUpDown();
            this.EndingPx = new System.Windows.Forms.NumericUpDown();
            this.TrueTypeRenderingHint = new System.Windows.Forms.ComboBox();
            this.FontStyleCB = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.ImagePlaneTypeCB = new System.Windows.Forms.ComboBox();
            this.label6 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label7 = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.WorkFlowCB = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.FontSize)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.InitFontHeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.InitFontWidth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.StartingPx)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.EndingPx)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.SuspendLayout();
            // 
            // FontComboBox
            // 
            this.FontComboBox.FormattingEnabled = true;
            this.FontComboBox.Location = new System.Drawing.Point(9, 66);
            this.FontComboBox.Name = "FontComboBox";
            this.FontComboBox.Size = new System.Drawing.Size(244, 21);
            this.FontComboBox.TabIndex = 4;
            // 
            // FontSize
            // 
            this.FontSize.Location = new System.Drawing.Point(334, 67);
            this.FontSize.Maximum = new decimal(new int[] {
            500,
            0,
            0,
            0});
            this.FontSize.Minimum = new decimal(new int[] {
            12,
            0,
            0,
            0});
            this.FontSize.Name = "FontSize";
            this.FontSize.Size = new System.Drawing.Size(74, 20);
            this.FontSize.TabIndex = 5;
            this.FontSize.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.FontSize.Value = new decimal(new int[] {
            12,
            0,
            0,
            0});
            // 
            // OutputTextBox
            // 
            this.OutputTextBox.BackColor = System.Drawing.Color.Black;
            this.OutputTextBox.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.OutputTextBox.ForeColor = System.Drawing.Color.Yellow;
            this.OutputTextBox.Location = new System.Drawing.Point(594, 23);
            this.OutputTextBox.Multiline = true;
            this.OutputTextBox.Name = "OutputTextBox";
            this.OutputTextBox.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.OutputTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.OutputTextBox.Size = new System.Drawing.Size(548, 617);
            this.OutputTextBox.TabIndex = 8;
            this.OutputTextBox.WordWrap = false;
            this.OutputTextBox.TextChanged += new System.EventHandler(this.OutputTextBox_TextChanged);
            // 
            // FormUpdateTimer
            // 
            this.FormUpdateTimer.Enabled = true;
            this.FormUpdateTimer.Interval = 250;
            this.FormUpdateTimer.Tick += new System.EventHandler(this.FormUpdateTimer_Tick);
            // 
            // OutputFolder
            // 
            this.OutputFolder.Location = new System.Drawing.Point(6, 39);
            this.OutputFolder.Name = "OutputFolder";
            this.OutputFolder.Size = new System.Drawing.Size(526, 20);
            this.OutputFolder.TabIndex = 9;
            this.OutputFolder.Text = ".\\";
            // 
            // FontBaseName
            // 
            this.FontBaseName.Location = new System.Drawing.Point(6, 90);
            this.FontBaseName.Name = "FontBaseName";
            this.FontBaseName.Size = new System.Drawing.Size(188, 20);
            this.FontBaseName.TabIndex = 10;
            this.FontBaseName.Text = "MY_FONT";
            // 
            // TargetFolderLabel
            // 
            this.TargetFolderLabel.AutoSize = true;
            this.TargetFolderLabel.Location = new System.Drawing.Point(6, 23);
            this.TargetFolderLabel.Name = "TargetFolderLabel";
            this.TargetFolderLabel.Size = new System.Drawing.Size(105, 13);
            this.TargetFolderLabel.TabIndex = 11;
            this.TargetFolderLabel.Text = "Target Output Folder";
            // 
            // FontNameLabel
            // 
            this.FontNameLabel.AutoSize = true;
            this.FontNameLabel.Location = new System.Drawing.Point(3, 74);
            this.FontNameLabel.Name = "FontNameLabel";
            this.FontNameLabel.Size = new System.Drawing.Size(86, 13);
            this.FontNameLabel.TabIndex = 12;
            this.FontNameLabel.Text = "Font Base Name";
            // 
            // InitFontButton
            // 
            this.InitFontButton.Location = new System.Drawing.Point(9, 19);
            this.InitFontButton.Name = "InitFontButton";
            this.InitFontButton.Size = new System.Drawing.Size(75, 38);
            this.InitFontButton.TabIndex = 13;
            this.InitFontButton.Text = "Initialize Font";
            this.InitFontButton.UseVisualStyleBackColor = true;
            this.InitFontButton.Click += new System.EventHandler(this.InitFontButton_Click);
            // 
            // InitFontHeight
            // 
            this.InitFontHeight.Location = new System.Drawing.Point(113, 30);
            this.InitFontHeight.Maximum = new decimal(new int[] {
            640,
            0,
            0,
            0});
            this.InitFontHeight.Minimum = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.InitFontHeight.Name = "InitFontHeight";
            this.InitFontHeight.Size = new System.Drawing.Size(51, 20);
            this.InitFontHeight.TabIndex = 14;
            this.InitFontHeight.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            // 
            // InitFontWidth
            // 
            this.InitFontWidth.Location = new System.Drawing.Point(195, 30);
            this.InitFontWidth.Maximum = new decimal(new int[] {
            640,
            0,
            0,
            0});
            this.InitFontWidth.Minimum = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.InitFontWidth.Name = "InitFontWidth";
            this.InitFontWidth.Size = new System.Drawing.Size(55, 20);
            this.InitFontWidth.TabIndex = 15;
            this.InitFontWidth.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(110, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 13);
            this.label1.TabIndex = 16;
            this.label1.Text = "Height";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(192, 14);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 17;
            this.label2.Text = "Width";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // BuildFontButton
            // 
            this.BuildFontButton.Location = new System.Drawing.Point(9, 76);
            this.BuildFontButton.Name = "BuildFontButton";
            this.BuildFontButton.Size = new System.Drawing.Size(75, 38);
            this.BuildFontButton.TabIndex = 18;
            this.BuildFontButton.Text = "Build Font";
            this.BuildFontButton.UseVisualStyleBackColor = true;
            this.BuildFontButton.Click += new System.EventHandler(this.BuildFontButton_Click);
            // 
            // GenerateTT_FontData
            // 
            this.GenerateTT_FontData.Location = new System.Drawing.Point(9, 19);
            this.GenerateTT_FontData.Name = "GenerateTT_FontData";
            this.GenerateTT_FontData.Size = new System.Drawing.Size(143, 21);
            this.GenerateTT_FontData.TabIndex = 19;
            this.GenerateTT_FontData.Text = "Build TT Font";
            this.GenerateTT_FontData.UseVisualStyleBackColor = true;
            this.GenerateTT_FontData.Click += new System.EventHandler(this.GenerateTT_FontData_Click);
            // 
            // BuiladAll_TT_Button
            // 
            this.BuiladAll_TT_Button.Enabled = false;
            this.BuiladAll_TT_Button.Location = new System.Drawing.Point(9, 46);
            this.BuiladAll_TT_Button.Name = "BuiladAll_TT_Button";
            this.BuiladAll_TT_Button.Size = new System.Drawing.Size(139, 23);
            this.BuiladAll_TT_Button.TabIndex = 20;
            this.BuiladAll_TT_Button.Text = "Build all TT from Range";
            this.BuiladAll_TT_Button.UseVisualStyleBackColor = true;
            this.BuiladAll_TT_Button.Click += new System.EventHandler(this.button1_Click);
            // 
            // StartingPx
            // 
            this.StartingPx.Enabled = false;
            this.StartingPx.Location = new System.Drawing.Point(9, 75);
            this.StartingPx.Maximum = new decimal(new int[] {
            240,
            0,
            0,
            0});
            this.StartingPx.Minimum = new decimal(new int[] {
            12,
            0,
            0,
            0});
            this.StartingPx.Name = "StartingPx";
            this.StartingPx.Size = new System.Drawing.Size(56, 20);
            this.StartingPx.TabIndex = 21;
            this.StartingPx.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.StartingPx.Value = new decimal(new int[] {
            12,
            0,
            0,
            0});
            // 
            // EndingPx
            // 
            this.EndingPx.Enabled = false;
            this.EndingPx.Location = new System.Drawing.Point(92, 75);
            this.EndingPx.Maximum = new decimal(new int[] {
            240,
            0,
            0,
            0});
            this.EndingPx.Minimum = new decimal(new int[] {
            12,
            0,
            0,
            0});
            this.EndingPx.Name = "EndingPx";
            this.EndingPx.Size = new System.Drawing.Size(56, 20);
            this.EndingPx.TabIndex = 22;
            this.EndingPx.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.EndingPx.Value = new decimal(new int[] {
            12,
            0,
            0,
            0});
            // 
            // TrueTypeRenderingHint
            // 
            this.TrueTypeRenderingHint.FormattingEnabled = true;
            this.TrueTypeRenderingHint.Location = new System.Drawing.Point(9, 108);
            this.TrueTypeRenderingHint.Name = "TrueTypeRenderingHint";
            this.TrueTypeRenderingHint.Size = new System.Drawing.Size(244, 21);
            this.TrueTypeRenderingHint.TabIndex = 30;
            // 
            // FontStyleCB
            // 
            this.FontStyleCB.FormattingEnabled = true;
            this.FontStyleCB.Location = new System.Drawing.Point(6, 146);
            this.FontStyleCB.Name = "FontStyleCB";
            this.FontStyleCB.Size = new System.Drawing.Size(244, 21);
            this.FontStyleCB.TabIndex = 31;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(259, 105);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(86, 21);
            this.label3.TabIndex = 32;
            this.label3.Text = "Font Style";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(262, 146);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(205, 21);
            this.label4.TabIndex = 33;
            this.label4.Text = "True Type Rendering Hint";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(415, 66);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(147, 21);
            this.label5.TabIndex = 34;
            this.label5.Text = "Font Size in Pixels";
            // 
            // ImagePlaneTypeCB
            // 
            this.ImagePlaneTypeCB.FormattingEnabled = true;
            this.ImagePlaneTypeCB.Location = new System.Drawing.Point(9, 22);
            this.ImagePlaneTypeCB.Name = "ImagePlaneTypeCB";
            this.ImagePlaneTypeCB.Size = new System.Drawing.Size(244, 21);
            this.ImagePlaneTypeCB.TabIndex = 35;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(262, 22);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(146, 21);
            this.label6.TabIndex = 36;
            this.label6.Text = "Image Plane Type";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.FontBaseName);
            this.groupBox1.Controls.Add(this.FontNameLabel);
            this.groupBox1.Controls.Add(this.OutputFolder);
            this.groupBox1.Controls.Add(this.TargetFolderLabel);
            this.groupBox1.Location = new System.Drawing.Point(7, 81);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(581, 116);
            this.groupBox1.TabIndex = 37;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Font Output Setup";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.ImagePlaneTypeCB);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.FontStyleCB);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.FontComboBox);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.TrueTypeRenderingHint);
            this.groupBox2.Controls.Add(this.FontSize);
            this.groupBox2.Location = new System.Drawing.Point(7, 205);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(581, 173);
            this.groupBox2.TabIndex = 38;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Font Generation Options";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(259, 67);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(44, 21);
            this.label7.TabIndex = 39;
            this.label7.Text = "Font";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.InitFontButton);
            this.groupBox3.Controls.Add(this.InitFontHeight);
            this.groupBox3.Controls.Add(this.InitFontWidth);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.BuildFontButton);
            this.groupBox3.Location = new System.Drawing.Point(7, 384);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(581, 147);
            this.groupBox3.TabIndex = 39;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Manual Font Generation";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.GenerateTT_FontData);
            this.groupBox4.Controls.Add(this.BuiladAll_TT_Button);
            this.groupBox4.Controls.Add(this.StartingPx);
            this.groupBox4.Controls.Add(this.EndingPx);
            this.groupBox4.Location = new System.Drawing.Point(7, 537);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(581, 103);
            this.groupBox4.TabIndex = 40;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "True Type Font Generation";
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.WorkFlowCB);
            this.groupBox5.Location = new System.Drawing.Point(7, 12);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(581, 63);
            this.groupBox5.TabIndex = 41;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Workflow Select";
            // 
            // WorkFlowCB
            // 
            this.WorkFlowCB.Font = new System.Drawing.Font("Segoe UI", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.WorkFlowCB.FormattingEnabled = true;
            this.WorkFlowCB.Items.AddRange(new object[] {
            "Manual Font Generation",
            "True Type Font Generation"});
            this.WorkFlowCB.Location = new System.Drawing.Point(5, 20);
            this.WorkFlowCB.Name = "WorkFlowCB";
            this.WorkFlowCB.Size = new System.Drawing.Size(557, 38);
            this.WorkFlowCB.TabIndex = 0;
            this.WorkFlowCB.SelectedIndexChanged += new System.EventHandler(this.WorkFlowCB_SelectedIndexChanged);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1152, 648);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.OutputTextBox);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximumSize = new System.Drawing.Size(1168, 686);
            this.MinimumSize = new System.Drawing.Size(1168, 686);
            this.Name = "MainForm";
            this.Text = "eGFX Font Builder";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.FontSize)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.InitFontHeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.InitFontWidth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.StartingPx)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.EndingPx)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox FontComboBox;
        private System.Windows.Forms.NumericUpDown FontSize;
        private System.Windows.Forms.TextBox OutputTextBox;
        private System.Windows.Forms.Timer FormUpdateTimer;
        private System.Windows.Forms.TextBox OutputFolder;
        private System.Windows.Forms.TextBox FontBaseName;
        private System.Windows.Forms.Label TargetFolderLabel;
        private System.Windows.Forms.Label FontNameLabel;
        private System.Windows.Forms.Button InitFontButton;
        private System.Windows.Forms.NumericUpDown InitFontHeight;
        private System.Windows.Forms.NumericUpDown InitFontWidth;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button BuildFontButton;
        private System.Windows.Forms.Button GenerateTT_FontData;
        private System.Windows.Forms.Button BuiladAll_TT_Button;
        private System.Windows.Forms.NumericUpDown StartingPx;
        private System.Windows.Forms.NumericUpDown EndingPx;
        private System.Windows.Forms.ComboBox TrueTypeRenderingHint;
        private System.Windows.Forms.ComboBox FontStyleCB;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox ImagePlaneTypeCB;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.ComboBox WorkFlowCB;

    }
}

