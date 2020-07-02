using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Diagnostics;

namespace генератор_стереокартинок_проба_2
{
    static class Program
    {
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        { 
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());     
        }
        
    }
}
    
struct myColor
{
    public int R;
    public int G;
    public int B;

    public void setDrawColor(Color c2)
    {
        R = c2.R;
        G = c2.G;
        B = c2.B;       
    }
   
    public Color getDrawColor()
    {         
        return  Color.FromArgb(R, G, B);
    }

}

class myImage
{
        public myColor[][] massiv;
        public int h, w;

        public myImage(Bitmap image)
        {
            h = image.Height;
            w = image.Width;
            massiv = new myColor[w][];
            for (int x = 0; x < w; x++)
            {
                massiv[x] = new myColor[h];
            }
            for (int i = 0; i < w; i++)
            {
                for(int k = 0; k < h; k++ )
                {
                massiv[i][k].setDrawColor(image.GetPixel(i, k));
                }
            }
        }

        public myImage(myColor[][] _massiv )
        {
            h = _massiv.Rank;
            w = _massiv[0].Length;
            massiv = new myColor[w][];
            for (int x = 0; x < w; x++)
            {
                massiv[x] = new myColor[h];
            }
            for (int i = 0; i < w; i++)
            {
                for (int k = 0; k < h; k++)
                {
                    massiv[i][k] = _massiv[i][k];
                }
            }
        }

        public myImage(myImage image)
        {
            h = image.h;
            w = image.w;
            massiv = new myColor[w][];
            for (int x = 0; x < w; x++)
            {
                massiv[x] = new myColor[h];
            }
            for (int i = 0; i < w; i++)
            {  
                for (int k = 0; k < h; k++)
                {
                    massiv[i][k] = image.massiv[i][k];
                }
            }
        }
        
        public myImage(int width, int height)
        {
            massiv = new myColor[width][];
            for (int x = 0; x < width; x++)
            {
                massiv[x] = new myColor[height];
            }
            h = height;
            w = width;
        }

        public Bitmap getBitmap()
            {
                Bitmap image = new Bitmap(w,h);
                for (int i = 0; i < w; i++)
                {
                    for (int k = 0; k < h; k++)
                    {
                        image.SetPixel(i, k, massiv[i][k].getDrawColor());
                    }
                }
                return image;
            }
    public void clearImage(myColor colorClear)
    {
        for (int i = 0; i < w; i++)
        {
            for (int k = 0; k < h; k++)
            {
                massiv[i][k] = colorClear;
            }
        }
    }
}

class stereo
{
    static myImage sterePictureMyImage;
    //создать изображение шириной , высотой, шириной повторяющейся части
    public myImage GetNewStereoPicture(int w, int s, int h)
    {
        Bitmap mask = new Bitmap("back.png");
        if (sterePictureMyImage == null)
        {
            Random rnd = new Random();
            for (int i = 0; i < w; i++)
            {
                for (int k = 0; k < h; k++)
                {
                    int tempcolor = rnd.Next(0, 255);
                    mask.SetPixel(i, k, Color.FromArgb(tempcolor, tempcolor, tempcolor));
                }
            }
            myImage imagemask = new myImage(mask);
            //конечная картинка из повторяющихся картинок
            myImage stereoImg = new myImage(w,s);

            for (int i = 0; i < w; i++)
            {
                for (int k = 0; k < s; k++)
                {
                    stereoImg.massiv[i][k] = imagemask.massiv[i][k % h];
                }
            }
            sterePictureMyImage = stereoImg;
        }
        return sterePictureMyImage;
    }

    public  Bitmap GenerateStereoPicture(Bitmap bitmapMask)
    {
        // Переводим маску в массив сдвигов
        int w = bitmapMask.Width;
        int h = bitmapMask.Height;
        int[][] mask = new int[w][];
        for (int x = 0; x < w; x++)
        {
            mask[x] = new int[h];
            for (int y = 0; y < h; y++)
                mask[x][y] = bitmapMask.GetPixel(x, y).R / 32;
        }

        // Cоздаем фон
        int s = 100;
        myImage stereoImg = GetNewStereoPicture(w + s, h, s);
        myColor pixel;
        myImage image1 = new myImage(stereoImg);
        // Сдвигаем нужные пикселы по маски 
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (mask[x][y] > 0)
                {
                    //pixel = stereoImg.GetPixel(x + mask[x][y], y);
                    pixel = image1.massiv[x + mask[x][y] ][y];
                    for (int i = x + s; i < w + s; i += s)
                        image1.massiv[i][y] =  pixel;
                }
        return image1.getBitmap();
    }

    public Bitmap GenerateStereoPicture(myImage bitmapMask)
    {
        // Переводим маску в массив сдвигов
        int w = bitmapMask.w;
        int h = bitmapMask.h;
        int[][] mask = new int[w][];
        for (int x = 0; x < w; x++)
        {
            mask[x] = new int[h];
            for (int y = 0; y < h; y++)
                mask[x][y] = bitmapMask.massiv[x][y].R / 32;
        }

        // Cоздаем фон
        int s = 100;
        myImage stereoImg = GetNewStereoPicture(w + s, h, s);
        myColor pixel;
        myImage image1 = new myImage(stereoImg);
        // Сдвигаем нужные пикселы по маски 
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (mask[x][y] > 0)
                {
                    //pixel = stereoImg.GetPixel(x + mask[x][y], y);
                    pixel = image1.massiv[x + mask[x][y]][y];
                    for (int i = x + s; i < w + s; i += s)
                        image1.massiv[i][y] = pixel;
                }
        return image1.getBitmap();
    }
}
