namespace SE
{
    partial class Form1
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
            this.pictureBoxShades = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.hScrollBar1 = new System.Windows.Forms.HScrollBar();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.CopyPrevBtn = new System.Windows.Forms.Button();
            this.PrevBtn = new System.Windows.Forms.Button();
            this.MarkPrevBtn = new System.Windows.Forms.Button();
            this.NextBtn = new System.Windows.Forms.Button();
            this.MarkNextBtn = new System.Windows.Forms.Button();
            this.CopyNextBtn = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.ClrAllBtn = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.label2 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxShades)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBoxShades
            // 
            this.pictureBoxShades.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.pictureBoxShades.Image = global::SE.Properties.Resources.background150inv;
            this.pictureBoxShades.Location = new System.Drawing.Point(0, 15);
            this.pictureBoxShades.Name = "pictureBoxShades";
            this.pictureBoxShades.Size = new System.Drawing.Size(1005, 382);
            this.pictureBoxShades.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBoxShades.TabIndex = 0;
            this.pictureBoxShades.TabStop = false;
            this.pictureBoxShades.Tag = "-1";
            this.pictureBoxShades.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBoxShades_Paint);
            this.pictureBoxShades.MouseClick += new System.Windows.Forms.MouseEventHandler(this.Pixel_MouseMove_1);
            this.pictureBoxShades.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Pixel_MouseMove_1);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.ForeColor = System.Drawing.Color.Silver;
            this.label1.Location = new System.Drawing.Point(483, 40);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(33, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Pix??";
            // 
            // hScrollBar1
            // 
            this.hScrollBar1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.hScrollBar1.Location = new System.Drawing.Point(0, 557);
            this.hScrollBar1.Maximum = 1024;
            this.hScrollBar1.Name = "hScrollBar1";
            this.hScrollBar1.Size = new System.Drawing.Size(1005, 16);
            this.hScrollBar1.TabIndex = 3;
            this.hScrollBar1.ValueChanged += new System.EventHandler(this.hScrollBar1_ValueChanged);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.DimGray;
            this.button1.ForeColor = System.Drawing.Color.LightGray;
            this.button1.Location = new System.Drawing.Point(12, 521);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 5;
            this.button1.Text = "Save";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.DimGray;
            this.button2.ForeColor = System.Drawing.Color.LightGray;
            this.button2.Location = new System.Drawing.Point(93, 521);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 6;
            this.button2.Text = "Open";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // CopyPrevBtn
            // 
            this.CopyPrevBtn.BackColor = System.Drawing.Color.DimGray;
            this.CopyPrevBtn.ForeColor = System.Drawing.Color.LightGray;
            this.CopyPrevBtn.Location = new System.Drawing.Point(351, 521);
            this.CopyPrevBtn.Name = "CopyPrevBtn";
            this.CopyPrevBtn.Size = new System.Drawing.Size(75, 23);
            this.CopyPrevBtn.TabIndex = 7;
            this.CopyPrevBtn.Text = "< Copy";
            this.CopyPrevBtn.UseVisualStyleBackColor = false;
            this.CopyPrevBtn.Click += new System.EventHandler(this.CopyPrevBtn_Click);
            // 
            // PrevBtn
            // 
            this.PrevBtn.BackColor = System.Drawing.Color.DimGray;
            this.PrevBtn.ForeColor = System.Drawing.Color.LightGray;
            this.PrevBtn.Location = new System.Drawing.Point(270, 521);
            this.PrevBtn.Name = "PrevBtn";
            this.PrevBtn.Size = new System.Drawing.Size(75, 23);
            this.PrevBtn.TabIndex = 8;
            this.PrevBtn.Text = "<<<";
            this.PrevBtn.UseVisualStyleBackColor = false;
            this.PrevBtn.Click += new System.EventHandler(this.PrevBtn_Click);
            // 
            // MarkPrevBtn
            // 
            this.MarkPrevBtn.BackColor = System.Drawing.Color.DimGray;
            this.MarkPrevBtn.ForeColor = System.Drawing.Color.LightGray;
            this.MarkPrevBtn.Location = new System.Drawing.Point(432, 521);
            this.MarkPrevBtn.Name = "MarkPrevBtn";
            this.MarkPrevBtn.Size = new System.Drawing.Size(75, 23);
            this.MarkPrevBtn.TabIndex = 9;
            this.MarkPrevBtn.Text = "< Mark";
            this.MarkPrevBtn.UseVisualStyleBackColor = false;
            this.MarkPrevBtn.Click += new System.EventHandler(this.MarkPrevBtn_Click);
            // 
            // NextBtn
            // 
            this.NextBtn.BackColor = System.Drawing.Color.DimGray;
            this.NextBtn.ForeColor = System.Drawing.Color.LightGray;
            this.NextBtn.Location = new System.Drawing.Point(675, 521);
            this.NextBtn.Name = "NextBtn";
            this.NextBtn.Size = new System.Drawing.Size(75, 23);
            this.NextBtn.TabIndex = 12;
            this.NextBtn.Text = ">>>";
            this.NextBtn.UseVisualStyleBackColor = false;
            this.NextBtn.Click += new System.EventHandler(this.NextBtn_Click);
            // 
            // MarkNextBtn
            // 
            this.MarkNextBtn.BackColor = System.Drawing.Color.DimGray;
            this.MarkNextBtn.ForeColor = System.Drawing.Color.LightGray;
            this.MarkNextBtn.Location = new System.Drawing.Point(513, 521);
            this.MarkNextBtn.Name = "MarkNextBtn";
            this.MarkNextBtn.Size = new System.Drawing.Size(75, 23);
            this.MarkNextBtn.TabIndex = 11;
            this.MarkNextBtn.Text = "Mark >";
            this.MarkNextBtn.UseVisualStyleBackColor = false;
            this.MarkNextBtn.Click += new System.EventHandler(this.MarkNextBtn_Click);
            // 
            // CopyNextBtn
            // 
            this.CopyNextBtn.BackColor = System.Drawing.Color.DimGray;
            this.CopyNextBtn.ForeColor = System.Drawing.Color.LightGray;
            this.CopyNextBtn.Location = new System.Drawing.Point(594, 521);
            this.CopyNextBtn.Name = "CopyNextBtn";
            this.CopyNextBtn.Size = new System.Drawing.Size(75, 23);
            this.CopyNextBtn.TabIndex = 10;
            this.CopyNextBtn.Text = "Copy >";
            this.CopyNextBtn.UseVisualStyleBackColor = false;
            this.CopyNextBtn.Click += new System.EventHandler(this.CopyNextBtn_Click);
            // 
            // button9
            // 
            this.button9.BackColor = System.Drawing.Color.DimGray;
            this.button9.ForeColor = System.Drawing.Color.LightGray;
            this.button9.Location = new System.Drawing.Point(913, 521);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(75, 23);
            this.button9.TabIndex = 13;
            this.button9.Text = "Upload";
            this.button9.UseVisualStyleBackColor = false;
            // 
            // ClrAllBtn
            // 
            this.ClrAllBtn.BackColor = System.Drawing.Color.DimGray;
            this.ClrAllBtn.ForeColor = System.Drawing.Color.LightGray;
            this.ClrAllBtn.Location = new System.Drawing.Point(172, 521);
            this.ClrAllBtn.Name = "ClrAllBtn";
            this.ClrAllBtn.Size = new System.Drawing.Size(75, 23);
            this.ClrAllBtn.TabIndex = 14;
            this.ClrAllBtn.Text = "CLR All";
            this.ClrAllBtn.UseVisualStyleBackColor = false;
            this.ClrAllBtn.Click += new System.EventHandler(this.ClrAllBtn_Click);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.ForeColor = System.Drawing.Color.Silver;
            this.label2.Location = new System.Drawing.Point(483, 355);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(20, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "#0";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(1005, 573);
            this.Controls.Add(this.ClrAllBtn);
            this.Controls.Add(this.button9);
            this.Controls.Add(this.NextBtn);
            this.Controls.Add(this.MarkNextBtn);
            this.Controls.Add(this.CopyNextBtn);
            this.Controls.Add(this.MarkPrevBtn);
            this.Controls.Add(this.PrevBtn);
            this.Controls.Add(this.CopyPrevBtn);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.hScrollBar1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pictureBoxShades);
            this.MaximumSize = new System.Drawing.Size(1013, 600);
            this.MinimumSize = new System.Drawing.Size(1013, 600);
            this.Name = "Form1";
            this.Text = "LED Shades Editor";
            this.Activated += new System.EventHandler(this.Form1_Activated);
            this.LocationChanged += new System.EventHandler(this.Form1_Activated);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBoxShades_Paint);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxShades)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBoxShades;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.HScrollBar hScrollBar1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button CopyPrevBtn;
        private System.Windows.Forms.Button PrevBtn;
        private System.Windows.Forms.Button MarkPrevBtn;
        private System.Windows.Forms.Button NextBtn;
        private System.Windows.Forms.Button MarkNextBtn;
        private System.Windows.Forms.Button CopyNextBtn;
        private System.Windows.Forms.Button button9;
        private System.Windows.Forms.Button ClrAllBtn;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label label2;
    }
}

