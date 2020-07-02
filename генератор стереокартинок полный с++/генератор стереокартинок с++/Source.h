
#include "bmp.h"

struct myColor
{
public: int R;
public: int G;
public: int B;

public: void setDrawColor(myColor c2)
	{
		R = c2.R;
		G = c2.G;
		B = c2.B;
	}

public: myColor getDrawColor()
	{
		myColor* temp = new myColor;
		return *temp->FromArgb(R, G, B);
	}

public: myColor* FromArgb(int r, int g, int b)
{
	R = r;
	B = b;
	G = g;
	return this;
}

};


class myImage
{
public: myColor** massiv;
public: int h, w;
		

		void clearImage(myColor colorClear)
		{
			for (int i = 0; i < w; i++)
			{
				for (int k = 0; k < h; k++)
				{
					massiv[i][k] = colorClear;
				}
			}
		}

		myImage(int width, int height)
		{
			massiv = new myColor*[width];
			for (int x = 0; x < width; x++)
			{
				massiv[x] = new myColor[height];
			}
			h = height;
			w = width;
		}
};

class Bitmap
{
public:
	int Height;
	int Width;
	myImage* image;


Bitmap(Bitmap* bitmap)
	{
		Width = bitmap->Width;
		Height = bitmap->Height;
		initialize();
		image = bitmap->image;
		
	}
Bitmap(CBitmap* bitmap)
{
	OpenCBitmap(bitmap);
}

void OpenCBitmap(CBitmap* bitmap)
{
	cout << "OpenCBitmap(CBitmap* bitmap)\n ";
	Width = bitmap->GetHeight();
	Height = bitmap->GetWidth();
	//здесь надо реализовать переписывание пикселей в мои пискли
	//image = bitmap->image;
	initialize();
	for (int i = 0; i < Height; i++)
	{
		for (int k = 0; k < Width; k++)
		{
			//cout <<"#"<< (int)bitmap->m_BitmapData[i*Height + k].Red << endl;
			image->massiv[i][k].setDrawColor( *image->massiv[i][k].FromArgb(((int)bitmap->m_BitmapData[i*Height + k].Red), ((int)bitmap->m_BitmapData[i*Height + k].Green),( (int)bitmap->m_BitmapData[i*Height + k].Blue)));
			//cout << image->massiv[i][k].R <<endl;
		}
	}
}

void GetCBitmap(CBitmap* bitmap)
{
	cout << "GetCBitmap(CBitmap* bitmap)";
	cout << Width << Height;
	int sizestruct = 0;
	/*Height = 400;
	Width = 500;*/
	for (int i = 0; i < Width ; i++)
	{
		for (int k = 0; k < Height; k++)
		{
			//cout << (int)image->massiv[i][k].R <<endl;
			(bitmap->m_BitmapData + (i  + k*(Width)+ sizestruct))->Red = (int)image->massiv[i][k].R;
			(bitmap->m_BitmapData + (i + k*(Width)+sizestruct))->Green =(int)image->massiv[i][k].G;
			(bitmap->m_BitmapData + (i + k*(Width)+sizestruct))->Blue = (int)image->massiv[i][k].B;
			(bitmap->m_BitmapData + (i + k*(Width)+ sizestruct))->Alpha = 0;
		}
	}

}
	myColor GetPixel(int x, int y)
	{
		return image->massiv[x][y];
	}

	void SetPixel(int x, int y, myColor c)
	{
		image->massiv[x][y] = c;
	}

	Bitmap open(char* filename)
	{
		CBitmap file(filename);
		OpenCBitmap(&file);
		return this;
	}

	void save(char*)
	{

	}

	void initialize()
	{
		image = new myImage(Width, Height);
	}

	Bitmap(int w, int h)
	{
		//cout << "Bitmap(int w, int h)\n";
		Width = w;
		Height = h;
		initialize();
	}

	Bitmap(char* filename)
	{
		CBitmap file(filename);
		OpenCBitmap(&file);
		initialize();
	}
};




//myImage::myImage(Bitmap* image)
//	{
//		h = image->Height;
//		w = image->Width;
//		massiv = new myColor*[w];
//		for (int x = 0; x < w; x++)
//		{
//			massiv[x] = new myColor[h];
//		}
//		for (int i = 0; i < w; i++)
//		{
//			for (int k = 0; k < h; k++)
//			{
//				massiv[i][k].setDrawColor(image->GetPixel(i, k));
//			}
//		}
//	}

//public: myImage(myColor** _massiv)
//	{
//		h = _massiv.Rank;
//		w = _massiv[0].Length;
//		massiv = new myColor[w][];
//		for (int x = 0; x < w; x++)
//		{
//			massiv[x] = new myColor[h];
//		}
//		for (int i = 0; i < w; i++)
//		{
//			for (int k = 0; k < h; k++)
//			{
//				massiv[i][k] = _massiv[i][k];
//			}
//		}
//	}

//public: myImage(myImage image)
//	{
//		h = image.h;
//		w = image.w;
//		massiv = new myColor*[w];
//		for (int x = 0; x < w; x++)
//		{
//			massiv[x] = new myColor[h];
//		}
//		for (int i = 0; i < w; i++)
//		{
//			for (int k = 0; k < h; k++)
//			{
//				massiv[i][k] = image.massiv[i][k];
//			}
//		}
//	}



//Bitmap myImage::getBitmap()
//	{
//		Bitmap* image = new Bitmap(w, h);
//		for (int i = 0; i < w; i++)
//		{
//			for (int k = 0; k < h; k++)
//			{
//				image->SetPixel(i, k, massiv[i][k].getDrawColor());
//			}
//		}
//		return *image;
//	}







class stereo
{
public:

Bitmap* sterePictureMyImage = nullptr;
	//создать изображение шириной , высотой, шириной повтор€ющейс€ части
Bitmap GetNewStereoPicture(int w, int s, int h)
	{

		//cout << "GetNewStereoPicture\n";
		//cout << "w = " << w << "s = " << h << endl;
		
		if (sterePictureMyImage == nullptr)
		{
			/*Random rnd = new Random();
			for (int i = 0; i < w; i++)
			{
				for (int k = 0; k < h; k++)
				{
					int tempcolor = rnd.Next(0, 255);
					mask.SetPixel(i, k, Color.FromArgb(tempcolor, tempcolor, tempcolor));
				}
			}*/
			Bitmap* mask = new Bitmap("back.bmp");
			//Bitmap mask2("back.bmp");
			CBitmap mask2C("back.bmp");
			mask->OpenCBitmap(&mask2C);

			//cout << mask->Width<<mask->Height;

			sterePictureMyImage = new Bitmap(w,s);
			//cout << sterePictureMyImage->Width << sterePictureMyImage->Height;
			//Bitmap* imagemask = new Bitmap(mask);
			////конечна€ картинка из повтор€ющихс€ картинок
			//Bitmap* stereoImg = new Bitmap(w, s);
			//cout << "GetNewStereoPicture for (int i = 0; i < w; i++)\n";
			for (int i = 0; i < w; i++)
			{
				for (int k = 0; k < s; k++)
				{
					//cout << "$for i = " << i << " k = " << k<< " h = " << k % h <<endl;
					//cout << "#" << mask2.image->massiv[i][k % h].R<<endl;
					sterePictureMyImage->image->massiv[i][k] = mask->image->massiv[i][k % h];
				}
				//cout << "$for i = " << i << endl;
			}
			//sterePictureMyImage = stereoImg;
		}
		//cout << "#END GetNewStereoPicture\n";
		return *sterePictureMyImage;
	}

Bitmap* GenerateStereoPicture(Bitmap bitmapMask)
	{
		//cout << "GenerateStereoPicture\n";
		// ѕереводим маску в массив сдвигов
		int w = bitmapMask.Width;
		int h = bitmapMask.Height;
		cout << "w = " << w<< "h = " << h<< endl;
		int** mask = new int*[w];
		for (int x = 0; x < w; x++)
		{
			mask[x] = new int[h];
			for (int y = 0; y < h; y++)
				mask[x][y] = bitmapMask.GetPixel(x, y).R / 32;
		}

		// Cоздаем фон
		int s = 100;
		Bitmap stereoImg = GetNewStereoPicture(w + s, h, s);
		myColor pixel;
		Bitmap* image1 = new Bitmap(stereoImg);
		// —двигаем нужные пикселы по маски 
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				if (mask[x][y] > 0)
				{
					//pixel = stereoImg.GetPixel(x + mask[x][y], y);
					pixel = image1->image->massiv[x + mask[x][y]][y];
					for (int i = x + s; i < w + s; i += s)
						image1->image->massiv[i][y] = pixel;
				}
		//cout << "#END GenerateStereoPicture\n";
		return image1;
	}

//public: Bitmap GenerateStereoPicture(myImage bitmapMask)
//	{
//		// ѕереводим маску в массив сдвигов
//		int w = bitmapMask.w;
//		int h = bitmapMask.h;
//		int** mask = new int*[w];
//		for (int x = 0; x < w; x++)
//		{
//			mask[x] = new int[h];
//			for (int y = 0; y < h; y++)
//				mask[x][y] = bitmapMask.massiv[x][y].R / 32;
//		}
//
//		// Cоздаем фон
//		int s = 100;
//		myImage stereoImg = GetNewStereoPicture(w + s, h, s);
//		myColor pixel;
//		myImage* image1 = new myImage(stereoImg);
//		// —двигаем нужные пикселы по маски 
//		for (int y = 0; y < h; y++)
//			for (int x = 0; x < w; x++)
//				if (mask[x][y] > 0)
//				{
//					//pixel = stereoImg.GetPixel(x + mask[x][y], y);
//					pixel = image1->massiv[x + mask[x][y]][y];
//					for (int i = x + s; i < w + s; i += s)
//						image1->massiv[i][y] = pixel;
//				}
//		return image1->getBitmap();
//	}
};
