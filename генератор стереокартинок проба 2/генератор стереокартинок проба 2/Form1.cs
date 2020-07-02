using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace генератор_стереокартинок_проба_2
{
    public partial class Form1 : Form
    {
        Graphics g;
        stereo gen = new stereo();
        Bitmap myBitmap ;
        myImage maskBitmap ;
        int x_image = 20;
        int y_image = 20;
        int i = 0;
        public Form1()
        {
            InitializeComponent();
            myBitmap = new Bitmap("1.png");
            maskBitmap = new myImage(myBitmap);
            //BackgroundImage = gen.GenerateStereoPicture(maskBitmap);
            //BackgroundImage.Save("out.png");
            Graphics g = CreateGraphics();
            g.DrawImage(myBitmap, 1, 1);
            //int i = 1;
            //while (true)
            //{
            //    BackgroundImage = gen.GenerateStereoPicture(maskBitmap);
            //    BackgroundImage.Save("out" + i + ".png");
            //    if (i++ > 1000) return;
            //}
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            //this.components.Add(g);
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            //чистим кадр в белый цвет

            //e.Graphics.DrawImage(gen.GenerateStereoPicture(drawFrame(maskBitmap, x_image, y_image, 40, 40)),0,0);
            BackgroundImage = gen.GenerateStereoPicture(drawFrame(maskBitmap, x_image, y_image, 40, 40));
            myColor colorClear;
            colorClear.R = 255;
            colorClear.B = 255;
            colorClear.G = 255;
            maskBitmap.clearImage(colorClear);
            Text = "frame " + i++;
        }

        private myImage drawFrame(myImage maskBitmap,int x, int y, int w, int h)
        {
            myColor colorPixel;
            colorPixel.R = 32;
            colorPixel.B = 32;
            colorPixel.G = 32;
            //maskBitmap.massiv[x][y] = colorPixel;
            for(int k = 0; k < h; k++)
            {
                for (int i = 0; i < w; i++)
                {
                    maskBitmap.massiv[x+k][y + i] = colorPixel;
                }
            }
            
            return maskBitmap;
        }

        private void Form1_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (e.KeyData == Keys.A)
            {
                x_image-=2;
                Refresh();
            }
            if (e.KeyData == Keys.S)
            {
                y_image+=2;
                Refresh();
            }
            if (e.KeyData == Keys.D)
            {
                x_image+=2;
                Refresh();
            }
            if (e.KeyData == Keys.W)
            {
                y_image-=2;
                Refresh();
            }

        }
    }
}
