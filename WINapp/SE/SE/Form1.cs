using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Windows.Forms;

namespace SE
{



    public partial class Form1 : Form
    {

        PictureBox[] PixelArray = new PictureBox[160];
        Label[] ByteLabels1 = new Label[20];
        uint[] PixelActive = new uint[160];
        uint[] PixelMarked = new uint[160];
        uint[] PixelOn = new uint[160];
        byte[] imgBytes = new byte[20*1024];
        int CurrentFrame = 0;

        int lastnum = -1;


        public Form1()
        {

            InitializeComponent();
            this.SetStyle(
              ControlStyles.AllPaintingInWmPaint |
              ControlStyles.UserPaint |
              ControlStyles.DoubleBuffer, true);

            hScrollBar1.Maximum = imgBytes.Length / 20 - 1;
            // Init and Draw "Pixels" ... 
            InitPixels();
            DrawGrid();

            // Add byte labels
            int horiz = 17;
            for (int i=0; i<20; i++)
            {
                ByteLabels1[i] = new Label();
                ByteLabels1[i].Location = new Point(horiz, 2);
                ByteLabels1[i].Text = "0";
                ByteLabels1[i].ForeColor = Color.LightGray;
                ByteLabels1[i].Size = new Size(42, 15);
                ByteLabels1[i].AutoSize = false;
                ByteLabels1[i].TextAlign = ContentAlignment.MiddleCenter;
                this.Controls.Add(ByteLabels1[i]);
                
                if (i == 9) horiz += 44 * 2;  // Jump over mid section (from left to right)
                horiz += 44;
                
            }

            for (int i=0; i< imgBytes.Length; i++) imgBytes[i] = 0;

            pictureBoxShades.SendToBack();  

        }

        private bool IsPixelOnShades(int idx)
        {
            int[] InactivePixel = { 0,1,5,6,7,8,15,73,64,72,79,80,81,87,88,144,151,152,153,157,158,159 };

            return !InactivePixel.Contains(idx);
        }

        private void UpdateValues()
        {
            for (int i = 0; i < 20; i++)
            {
                byte x = 0;
                byte c = 128;
                for (int b=0; b<8; b++)
                {
                    if (PixelOn[i * 8 + b] == 1) x += c;
                    c >>= 1;
                }
                imgBytes[i+20* CurrentFrame] = x;
                ByteLabels1[i].Text = x.ToString();
            }
        }

        private void UpdatePixles()
        {
            for (int i = 0; i < 20; i++)
            {
                byte x = imgBytes[i + 20 * CurrentFrame];
                byte c = 128;
                for (int b = 0; b < 8; b++)
                {
                    if ((x & c) > 0)
                    {
                        PixelOn[i * 8 + b] = 1;
                        DrawPixel(pictureBoxShades, i * 8 + b, Pens.Yellow);
                    }
                    else
                    {
                        DrawPixel(pictureBoxShades, i * 8 + b, Pens.Black);
                    }

                    //SetPixelColor(i*8+b);
                    c >>= 1;
                }
                ByteLabels1[i].Text = x.ToString();
                
            }
        }


        private void hScrollBar1_ValueChanged(object sender, EventArgs e)
        {
            HScrollBar hb = (HScrollBar)sender;
            CurrentFrame = hb.Value;

            for (int i = 0; i < 160; i++)
            {
                PixelOn[i] = 0;
                PixelMarked[i] = 0;
                MarkPixel(pictureBoxShades, i, Pens.Black);
            }
            UpdatePixles();
            label2.Text = "#"+CurrentFrame.ToString();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Displays a SaveFileDialog 
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            saveFileDialog1.Filter = "Shades Editor file|*.se|Text file|*.txt|C source code|*.c";
            saveFileDialog1.Title = "Save your LED Shades animation";
            saveFileDialog1.ShowDialog();

            // If the file name is not an empty string open it for saving.
            if (saveFileDialog1.FileName != "")
            {
               
                switch (saveFileDialog1.FilterIndex)
                {
                    case 1:  // Save as Shades Editor file
                        File.WriteAllBytes(saveFileDialog1.FileName, imgBytes);
                        break;

                    case 2: // Save as text
                        File.WriteAllText(saveFileDialog1.FileName, ByteArrayToString(imgBytes));

                        break;

                    case 3: // Save as C source
                        

                        break;
                }

                
            }

        }


        private static string ByteArrayToString(byte[] byteArray)
        {
            var hex = new StringBuilder(byteArray.Length * 2);
            foreach (var b in byteArray)
                hex.AppendFormat("{0:x2}", b);
            return hex.ToString();
        }

        private void PrevBtn_Click(object sender, EventArgs e)
        {
            if (hScrollBar1.Value > 0) hScrollBar1.Value--;
        }

        private void NextBtn_Click(object sender, EventArgs e)
        {
            if (hScrollBar1.Value < hScrollBar1.Maximum) hScrollBar1.Value++;
        }

        private void MarkFrom(int WhichFrame)
        {
            for (int i = 0; i < 20; i++)
            {
                byte x = imgBytes[i + 20 * WhichFrame];
                byte c = 128;
                for (int b = 0; b < 8; b++)
                {
                    if ((x & c) > 0)
                    {
                        PixelMarked[i * 8 + b] = 1;
                        MarkPixel(pictureBoxShades, i * 8 + b, Pens.Beige);
                    }
                    else
                    {
                        PixelMarked[i * 8 + b] = 0;
                        MarkPixel(pictureBoxShades, i * 8 + b, Pens.Black);
                    }
                    //SetPixelColor(i * 8 + b);
                    c >>= 1;
                }
                
            }
        }

        private void CopyFrom(int WhichFrame)
        {
            for (int i = 0; i < 20; i++)
            {
                imgBytes[i + 20 * CurrentFrame] = imgBytes[i + 20 * WhichFrame];
                UpdatePixles();
            }
        }


        private void MarkPrevBtn_Click(object sender, EventArgs e)
        {
            if (CurrentFrame > 0)
            {
                MarkFrom(CurrentFrame - 1);
            }
        }

        private void MarkNextBtn_Click(object sender, EventArgs e)
        {
            if (CurrentFrame < 1024)
            {
                MarkFrom(CurrentFrame + 1);
            }
        }

        private void CopyPrevBtn_Click(object sender, EventArgs e)
        {
            if (CurrentFrame > 0)
            {
                CopyFrom(CurrentFrame - 1);
            }
        }

        private void CopyNextBtn_Click(object sender, EventArgs e)
        {
            if (CurrentFrame < 1024)
            {
                CopyFrom(CurrentFrame + 1);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // Displays an OpenFileDialog 
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Filter = "Shades Editor file|*.se";
            openFileDialog1.Title = "Open LED Shades animation";
            openFileDialog1.ShowDialog();

            // If the file name is not an empty string ....
            if (openFileDialog1.FileName != "")
            {
                imgBytes = File.ReadAllBytes(openFileDialog1.FileName);
                hScrollBar1.Value = 0;
                CurrentFrame = 0;
                UpdatePixles();
            }
        }

        private void ClrAllBtn_Click(object sender, EventArgs e)
        {
            DialogResult dialogResult = MessageBox.Show("Sure", "Clear All ?", MessageBoxButtons.YesNo);
            if (dialogResult == DialogResult.Yes)
            {
                for (int i = 0; i < imgBytes.Length; i++) imgBytes[i] = 0;
                for (int i = 0; i < PixelArray.Length; i++)
                {
                    PixelMarked[i] = 0;
                    PixelOn[i] = 0;
                }
                CurrentFrame = 0;
                hScrollBar1.Value = 0;
            }
            
            UpdatePixles();
        }

        private int coord2num(int x, int y)
        {
            int xn = -1, yn = -1, n;
            if (x > (22 + 44 * 10)) x -= 2 * 44;   // skip mid section
            if ((x > 22) & (y > 17))
            {
                xn = (x - 22) / 44;
                yn = (y - 17) / 35;
            }

            if ((xn < 20) & (xn >= 0) & (yn < 8) & (yn >= 0))
            {
                n = xn * 8 + yn;
            }
            else
            {
                n = -1;
            }

            return n;
        }

        private void DrawMarkRect( object sender, int num, Pen p)
        {
            int xn = num / 8;
            int yn = num % 8;
            int x, y;

            PictureBox box = (PictureBox)sender;
            Graphics gF = box.CreateGraphics();

            x = 22 + xn * 44;
            y = 17 + yn * 35;
            if (num >= 79) x += 2 * 44;
            if (IsPixelOnShades(num)) gF.DrawRectangle(p, x, y, 41, 33);

        }

        private void DrawGrid()
        {
            for (int i = 0; i < 160; i++)
            {
                DrawMarkRect(pictureBoxShades, i, Pens.Gray);
            }

        }

        private void DrawPixel(object sender, int num, Pen p)
        {
            int xn = num / 8;
            int yn = num % 8;
            int x, y;

            PictureBox box = (PictureBox)sender;
            Graphics gF = box.CreateGraphics();

            x = 24 + xn * 44;
            y = 19 + yn * 35;
            if (num >= 79) x += 2 * 44;

            SolidBrush b = new SolidBrush(p.Color);
            if (IsPixelOnShades(num)) gF.FillRectangle(b, x, y, 38, 30);

        }


        private void MarkPixel(object sender, int num, Pen p)
        {
            int xn = num / 8;
            int yn = num % 8;
            int x, y;

            PictureBox box = (PictureBox)sender;
            Graphics gF = box.CreateGraphics();

            x = 23 + xn * 44;
            y = 18 + yn * 35;
            if (num >= 79) x += 2 * 44;

            if (IsPixelOnShades(num)) gF.DrawRectangle(p, x, y, 39, 31);

        }


        void InitPixels()
        {
            for (int i = 0; i < PixelArray.Length; i++)
            {
                PixelActive[i] = 0;
                PixelMarked[i] = 0;
                PixelOn[i] = 0;
            }

        }

        private void Pixel_MouseMove_1(object sender, MouseEventArgs e)
        {
            PictureBox pixel = (PictureBox)sender;
            int num;                     

            if (pixel != null)
            {
                num = coord2num(e.X, e.Y);
                label1.Text = "Pix#" + num;
                if (num!=lastnum)
                {
                    DrawGrid();
                    if (num >= 0) DrawMarkRect(sender, num, Pens.White);
                    lastnum = num;
                }

                if ((e.Button == MouseButtons.Left) & (num >= 0))
                {
                    PixelOn[num] = 1;
                    DrawPixel(sender, num, Pens.Yellow);
                }

                if ((e.Button == MouseButtons.Right) & (num >= 0))
                {
                    PixelOn[num] = 0;
                    DrawPixel(sender, num, Pens.Black);
                }
                UpdateValues();
            }
        }

        private void pictureBoxShades_Refresh()
        {
            DrawGrid();
            for (int i=0; i<160; i++)
            {
                if (PixelMarked[i] == 1)
                {
                    MarkPixel(pictureBoxShades, i, Pens.Beige);
                }
                else
                {
                    MarkPixel(pictureBoxShades, i, Pens.Black);
                }
                if (PixelOn[i] == 1)
                {
                    DrawPixel(pictureBoxShades, i, Pens.Yellow);
                }
                else
                {
                    DrawPixel(pictureBoxShades, i, Pens.Black);
                }
            }
        }

        private void pictureBoxShades_Paint(object sender, PaintEventArgs e)
        {
            // Refresh graphics
            timer1.Enabled = true;
        }

        private void Form1_Activated(object sender, EventArgs e)
        {
            // Refresh graphics
            timer1.Enabled = true;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            // Refresh graphics
            pictureBoxShades_Refresh();
            timer1.Enabled = false;
        }
    }
}
