// генератор стереокартинок с++.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"

#include "Source.h"

/*int *v;
int *loadBMP(const char *fname, int &mx, int &my)
{
	mx = my = -1;
	FILE *f = fopen(fname, "rb");
	if (f == nullptr)
	{
		cout << "Error open file:" << fname;
		return NULL;
	}
	BMPheader bh;    // File header sizeof(BMPheader) = 56
	size_t res;

	// читаем заголовок
	res = fread(&bh, 1, sizeof(BMPheader), f);
	if (res != sizeof(BMPheader)) { fclose(f); return NULL; }

	// провер€ем сигнатуру
	if (bh.bfType != 0x4d42 && bh.bfType != 0x4349 && bh.bfType != 0x5450) { fclose(f); return NULL; }

	// проверка размера файла
	fseek(f, 0, SEEK_END);
	int filesize = ftell(f);
	// восстановим указатель в файле:
	fseek(f, sizeof(BMPheader), SEEK_SET);
	// проверим услови€
	if (bh.bfSize != filesize ||
		bh.bfReserved != 0 ||
		bh.biPlanes != 1 ||
		(bh.biSize != 40 && bh.biSize != 108 && bh.biSize != 124) ||
		bh.bfOffBits != 14 + bh.biSize ||

		bh.biWidth <1 || bh.biWidth >10000 ||
		bh.biHeight<1 || bh.biHeight>10000 ||
		bh.biBitCount != 24 ||             // пока рассматриваем только полноцветные изображени€
		bh.biCompression != 0                // пока рассматриваем только несжатие изображени€
		)
	{
		fclose(f);
		cout << "Error, file is not bmp!"
			<< bh.bfSize << endl << filesize<<endl
			<<bh.bfReserved << endl
			<<bh.biPlanes << endl
			<<bh.biSize << endl
			<<bh.bfOffBits << endl

			<<bh.biWidth << endl
			<<bh.biHeight << endl
			<<bh.biBitCount << endl// пока рассматриваем только полноцветные изображени€
			<<bh.biCompression << endl
			;
		return NULL;
	}
	// «аголовок прочитан и проверен, тип - верный (BGR-24), размеры (mx,my) найдены
	mx = bh.biWidth;
	my = bh.biHeight;
	int mx3 = (3 * mx + 3) & (-4);    // Compute row width in file, including padding to 4-byte boundary
	unsigned char *tmp_buf = new unsigned  char[mx3*my];    // читаем данные
	res = fread(tmp_buf, 1, mx3*my, f);
	if ((int)res != mx3*my) { delete[]tmp_buf; fclose(f); return NULL; }
	// данные прочитаны
	fclose(f);

	// выделим пам€ть дл€ результата
	v = new int[mx*my];

	// ѕеренос данных (не забудем про BGR->RGB)
	unsigned char *ptr = (unsigned char *)v;
	for (int y = my - 1; y >= 0; y--) {
		unsigned char *pRow = tmp_buf + mx3*y;
		for (int x = 0; x< mx; x++) {
			*ptr++ = *(pRow + 2);
			*ptr++ = *(pRow + 1);
			*ptr++ = *pRow;
			pRow += 3;
			ptr++;
		}
	}
	delete[]tmp_buf;
	return v;    // OK
}


int saveBMP(const char *fname, int *v, int mx, int  my)	// ¬ каждом элементе упаковано все три RGB-байта
{
	BMPheader bh;	// «аголовок файла, sizeof(BMPheader) = 56
	memset(&bh, 0, sizeof(bh));
	bh.bfType = 0x4d42;	// 'BM'
						// Ќайдем длину строки в файле, включа€ округление вверх до кратного 4:
	int mx3 = (3 * mx + 3) & (-4);
	int filesize = 54 + my*mx3;
	bh.bfSize = filesize;
	bh.bfReserved = 0;
	bh.biPlanes = 1;
	bh.biSize = 40;
	bh.bfOffBits = 14 + bh.biSize;
	bh.biWidth = mx;
	bh.biHeight = my;
	bh.biBitCount = 24;
	bh.biCompression = 0;

	FILE *f = fopen(fname, "wb");
	if (!f) return -1;
	size_t res;

	// пишем заголовок
	res = fwrite(&bh, 1, sizeof(BMPheader), f);
	if (res != sizeof(BMPheader)) { fclose(f); return -1; }

	// приготовим временный буфер
	unsigned char *tmp_buf = new unsigned char[mx3*my];
	// ѕеренос данных (не забудем про RGB->BGR)
	unsigned char *ptr = (unsigned char *)v;
	for (int y = my - 1; y >= 0; y--) {
		unsigned char *pRow = tmp_buf + mx3*y;
		for (int x = 0; x< mx; x++) {
			*(pRow + 2) = *ptr++;
			*(pRow + 1) = *ptr++;
			*pRow = *ptr++;
			pRow += 3;
			ptr++;
		}
	}
	// сбросим в файл
	fwrite(tmp_buf, 1, mx3*my, f);
	fclose(f);
	delete[]tmp_buf;
	return 0;	// OK
}

*/

int main(int argc, char** argv)
{
	/*Bitmap mask("mask.bmp");
	Bitmap image1("mask.bmp");
	stereo image;
	image1 = image.GenerateStereoPicture(image1);
	image1.save("1.bmp");*/
	//////////////////////////////
	/*
	//if (argc < 2) {
	//	std::cout << "Usage: " << argv[0] << " file_name" << std::endl;
	//	return 0;
	//}

	//char *fileName = argv[1];

	//// открываем файл
	//std::ifstream fileStream(fileName, std::ifstream::binary);
	//if (!fileStream) {
	//	std::cout << "Error opening file '" << fileName << "'." << std::endl;
	//	return 0;
	//}

	//// заголовк изображени€
	//BITMAPFILEHEADER fileHeader;
	//read(fileStream, fileHeader.bfType, sizeof(fileHeader.bfType));
	//read(fileStream, fileHeader.bfSize, sizeof(fileHeader.bfSize));
	//read(fileStream, fileHeader.bfReserved1, sizeof(fileHeader.bfReserved1));
	//read(fileStream, fileHeader.bfReserved2, sizeof(fileHeader.bfReserved2));
	//read(fileStream, fileHeader.bfOffBits, sizeof(fileHeader.bfOffBits));

	//if (fileHeader.bfType != 0x4D42) {
	//	std::cout << "Error: '" << fileName << "' is not BMP file." << std::endl;
	//	return 0;
	//}

	//// информаци€ изображени€
	//BITMAPINFOHEADER fileInfoHeader;
	//read(fileStream, fileInfoHeader.biSize, sizeof(fileInfoHeader.biSize));

	//// bmp core
	//if (fileInfoHeader.biSize >= 12) {
	//	read(fileStream, fileInfoHeader.biWidth, sizeof(fileInfoHeader.biWidth));
	//	read(fileStream, fileInfoHeader.biHeight, sizeof(fileInfoHeader.biHeight));
	//	read(fileStream, fileInfoHeader.biPlanes, sizeof(fileInfoHeader.biPlanes));
	//	read(fileStream, fileInfoHeader.biBitCount, sizeof(fileInfoHeader.biBitCount));
	//}

	//// получаем информацию о битности
	//int colorsCount = fileInfoHeader.biBitCount >> 3;
	//if (colorsCount < 3) {
	//	colorsCount = 3;
	//}

	//int bitsOnColor = fileInfoHeader.biBitCount / colorsCount;
	//int maskValue = (1 << bitsOnColor) - 1;

	//// bmp v1
	//if (fileInfoHeader.biSize >= 40) {
	//	read(fileStream, fileInfoHeader.biCompression, sizeof(fileInfoHeader.biCompression));
	//	read(fileStream, fileInfoHeader.biSizeImage, sizeof(fileInfoHeader.biSizeImage));
	//	read(fileStream, fileInfoHeader.biXPelsPerMeter, sizeof(fileInfoHeader.biXPelsPerMeter));
	//	read(fileStream, fileInfoHeader.biYPelsPerMeter, sizeof(fileInfoHeader.biYPelsPerMeter));
	//	read(fileStream, fileInfoHeader.biClrUsed, sizeof(fileInfoHeader.biClrUsed));
	//	read(fileStream, fileInfoHeader.biClrImportant, sizeof(fileInfoHeader.biClrImportant));
	//}

	//// bmp v2
	//fileInfoHeader.biRedMask = 0;
	//fileInfoHeader.biGreenMask = 0;
	//fileInfoHeader.biBlueMask = 0;

	//if (fileInfoHeader.biSize >= 52) {
	//	read(fileStream, fileInfoHeader.biRedMask, sizeof(fileInfoHeader.biRedMask));
	//	read(fileStream, fileInfoHeader.biGreenMask, sizeof(fileInfoHeader.biGreenMask));
	//	read(fileStream, fileInfoHeader.biBlueMask, sizeof(fileInfoHeader.biBlueMask));
	//}

	//// если маска не задана, то ставим маску по умолчанию
	//if (fileInfoHeader.biRedMask == 0 || fileInfoHeader.biGreenMask == 0 || fileInfoHeader.biBlueMask == 0) {
	//	fileInfoHeader.biRedMask = maskValue << (bitsOnColor * 2);
	//	fileInfoHeader.biGreenMask = maskValue << bitsOnColor;
	//	fileInfoHeader.biBlueMask = maskValue;
	//}

	//// bmp v3
	//if (fileInfoHeader.biSize >= 56) {
	//	read(fileStream, fileInfoHeader.biAlphaMask, sizeof(fileInfoHeader.biAlphaMask));
	//}
	//else {
	//	fileInfoHeader.biAlphaMask = maskValue << (bitsOnColor * 3);
	//}

	//// bmp v4
	//if (fileInfoHeader.biSize >= 108) {
	//	read(fileStream, fileInfoHeader.biCSType, sizeof(fileInfoHeader.biCSType));
	//	read(fileStream, fileInfoHeader.biEndpoints, sizeof(fileInfoHeader.biEndpoints));
	//	read(fileStream, fileInfoHeader.biGammaRed, sizeof(fileInfoHeader.biGammaRed));
	//	read(fileStream, fileInfoHeader.biGammaGreen, sizeof(fileInfoHeader.biGammaGreen));
	//	read(fileStream, fileInfoHeader.biGammaBlue, sizeof(fileInfoHeader.biGammaBlue));
	//}

	//// bmp v5
	//if (fileInfoHeader.biSize >= 124) {
	//	read(fileStream, fileInfoHeader.biIntent, sizeof(fileInfoHeader.biIntent));
	//	read(fileStream, fileInfoHeader.biProfileData, sizeof(fileInfoHeader.biProfileData));
	//	read(fileStream, fileInfoHeader.biProfileSize, sizeof(fileInfoHeader.biProfileSize));
	//	read(fileStream, fileInfoHeader.biReserved, sizeof(fileInfoHeader.biReserved));
	//}

	//// проверка на поддерку этой версии формата
	//if (fileInfoHeader.biSize != 12 && fileInfoHeader.biSize != 40 && fileInfoHeader.biSize != 52 &&
	//	fileInfoHeader.biSize != 56 && fileInfoHeader.biSize != 108 && fileInfoHeader.biSize != 124) {
	//	std::cout << "Error: Unsupported BMP format." << std::endl;
	//	return 0;
	//}

	//if (fileInfoHeader.biBitCount != 16 && fileInfoHeader.biBitCount != 24 && fileInfoHeader.biBitCount != 32) {
	//	std::cout << "Error: Unsupported BMP bit count." << std::endl;
	//	return 0;
	//}

	//if (fileInfoHeader.biCompression != 0 && fileInfoHeader.biCompression != 3) {
	//	std::cout << "Error: Unsupported BMP compression." << std::endl;
	//	return 0;
	//}

	//// rgb info
	//RGBQUAD **rgbInfo = new RGBQUAD*[fileInfoHeader.biHeight];

	//for (unsigned int i = 0; i < fileInfoHeader.biHeight; i++) {
	//	rgbInfo[i] = new RGBQUAD[fileInfoHeader.biWidth];
	//}

	//// определение размера отступа в конце каждой строки
	//int linePadding = ((fileInfoHeader.biWidth * (fileInfoHeader.biBitCount / 8)) % 4) & 3;

	//// чтение
	//unsigned int bufer;
	////char* bufferpixel = new char[fileInfoHeader.biHeight*fileInfoHeader.biWidth*fileInfoHeader.biBitCount / 8];

	//for (unsigned int i = 0; i < fileInfoHeader.biHeight; i++) {
	//	for (unsigned int j = 0; j < fileInfoHeader.biWidth; j++) {
	//		read(fileStream, bufer, fileInfoHeader.biBitCount / 8);

	//		rgbInfo[i][j].rgbRed = bitextract(bufer, fileInfoHeader.biRedMask);
	//		rgbInfo[i][j].rgbGreen = bitextract(bufer, fileInfoHeader.biGreenMask);
	//		rgbInfo[i][j].rgbBlue = bitextract(bufer, fileInfoHeader.biBlueMask);
	//		rgbInfo[i][j].rgbReserved = bitextract(bufer, fileInfoHeader.biAlphaMask);
	//	}
	//	fileStream.seekg(linePadding, std::ios_base::cur);
	//}

	////переписываем все структуры
	////сначало заголовок файла
	//char* text1 = new char[sizeof(fileHeader)];
	//memcpy(text1, &fileHeader, sizeof(fileHeader));

	////потом информаци€ о файле
	//char* text2 = new char[sizeof(fileInfoHeader)];
	//memcpy(text2, &fileInfoHeader,sizeof(fileInfoHeader));
	//
	//
	//int otstupByte = (((fileInfoHeader.biWidth * (fileInfoHeader.biBitCount / 8)) % 4) & 3);

	////потом массив пикселей:количество пикселей * биты/8 + кол-во бит отступа в каждой строке * количество строк
	//char* text3 = new char[fileInfoHeader.biHeight*fileInfoHeader.biWidth*fileInfoHeader.biBitCount / 8 + otstupByte*fileInfoHeader.biHeight];
	////memcpy(text3, &bufer, sizeof(bufer));
	//

	//int pixel;
	//int otstup= 0;
	//for (unsigned int i = 0; i < fileInfoHeader.biHeight; i++) {
	//	for (unsigned int j = 0; j < fileInfoHeader.biWidth; j++) {
	//		//записываем со смещением каждый пиксель размером fileInfoHeader.biBitCount который делаем из структуры
	//		pixel = rgbInfo[i][j].rgbBlue*pow(2, fileInfoHeader.biBitCount/4*0) + rgbInfo[i][j].rgbGreen*pow(2, fileInfoHeader.biBitCount / 4 * 1) + rgbInfo[i][j].rgbRed *pow(2, fileInfoHeader.biBitCount / 4 * 2) + rgbInfo[i][j].rgbReserved*pow(2, fileInfoHeader.biBitCount / 4 * 3);
	//		memcpy((text3 +( (i + j)*fileInfoHeader.biBitCount)), &pixel , fileInfoHeader.biBitCount);
	//	}
	//	//в конце строки должен быть отступ
	//	memcpy((text3 + (i + fileInfoHeader.biWidth)), &otstup, otstupByte);
	//}


	*/
	//ofstream fileout("out.bmp", /*std::fstream::app|*/ std::fstream::binary);

	//
	//fileout.write(text1, sizeof(fileHeader));
	//fileout.write(text2, sizeof(fileInfoHeader));
	//fileout.write(text3, sizeof(text3));
	//
	//cout << text3;
	// вывод
	/*for (unsigned int i = 0; i < fileInfoHeader.biHeight; i++) {
		for (unsigned int j = 0; j < fileInfoHeader.biWidth; j++) {
			std::cout << std::hex
				<< +rgbInfo[i][j].rgbRed << " "
				<< +rgbInfo[i][j].rgbGreen << " "
				<< +rgbInfo[i][j].rgbBlue << " "
				//<< +rgbInfo[i][j].rgbReserved
				/*<< std::endl*/;
	/*	}
		std::cout << std::endl;
	}*/
/*
int x = 20, y = 20;
int* massivbmp = loadBMP("C:\\Users\\Igor\\Desktop\\programms\\visual studio projects\\генератор стереокартинок полный с++\\Debug\\1.bmp",x,y);
if (massivbmp == NULL) cout << "Error";
else
{
cout << v[1];
saveBMP("2.bmp", massivbmp, x, y);
}*/

//cout << "CBitmap file();"<<endl;
CBitmap file("1.bmp");
//cout << "Bitmap mask(&file);" << endl;
Bitmap mask(&file);
//cout << "stereo stereoimage;" << endl;
int i = 0;
while (i++ < 100)
{


stereo stereoimage;


Bitmap* stereo =  stereoimage.GenerateStereoPicture(&mask);


CBitmap* out = new CBitmap("3.bmp");

stereo->GetCBitmap(out);
char* text = new char[20];
itoa(i, text, 10);
strcat(text, "out.bmp");
out->Save(text);
}

	system("pause");
	return 0;
}
