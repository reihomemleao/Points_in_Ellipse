#include "Image.h"
#include<iostream>
#include<fstream>

Color::Color() :r(0), g(0), b(0)
{

}

Color::Color(float r, float g, float b) : r(r), g(g), b(b)
{
}

Color::~Color() {

}

Image::Image(int width, int height) : m_width(width), m_height(height), m_colors(std::vector<Color>(width* height))
{

}

Image::~Image() {

}

Color Image::GetColor(int x, int y) const
{
	return m_colors[y * m_width + x];
}

void Image::setColor(const Color& color, int x, int y)
{
	m_colors[y * m_width + x].r = color.r;
	m_colors[y * m_width + x].g = color.g;
	m_colors[y * m_width + x].b = color.b;
}
//0.992187500
void Image::Export(const char* path) const
{
	std::ofstream f;
	//out means we gonna be writting a file 
	//and binary means we gonna be writting a binary
	f.open(path, std::ios::out | std::ios::binary);

	if (!f.is_open()) {
		std::cout << "File could not be openned\n";
		return;
	}

	unsigned char bmPad[3] = { 0,0,0 };
	const int paddingAmount = ((4 - (m_width * 3) % 4) % 4);

	const int fileHeaderSize = 14;
	const int informationHeaderSize = 40;
	const int fileSize = fileHeaderSize + informationHeaderSize + m_width * m_height * 3 + paddingAmount * m_width;

	unsigned char fileHeader[fileHeaderSize];

	//File type
	fileHeader[0] = 'B';
	fileHeader[1] = 'M';
	//File size
	fileHeader[2] = fileSize;
	fileHeader[3] = fileSize >> 8;
	fileHeader[4] = fileSize >> 16;
	fileHeader[5] = fileSize >> 24;
	//Reserved 1 (Not used)
	fileHeader[6] = 0;
	fileHeader[7] = 0;
	//Reserved 2 (not used)
	fileHeader[8] = 0;
	fileHeader[9] = 0;
	//Pixel data offset
	fileHeader[10] = fileHeaderSize + informationHeaderSize;
	fileHeader[11] = 0;
	fileHeader[12] = 0;
	fileHeader[13] = 0;


	unsigned char informationsHeader[informationHeaderSize];

	//Header size
	informationsHeader[0] = informationHeaderSize;
	informationsHeader[1] = 0;
	informationsHeader[2] = 0;
	informationsHeader[3] = 0;

	//Image width 
	informationsHeader[4] = m_width;
	informationsHeader[5] = m_width >> 8;
	informationsHeader[6] = m_width >> 16;
	informationsHeader[7] = m_width >> 24;
	//Image height
	informationsHeader[8] = m_height;
	informationsHeader[9] = m_height >> 8;
	informationsHeader[10] = m_height >> 16;
	informationsHeader[11] = m_height >> 24;
	//Planes
	informationsHeader[12] = 1;
	informationsHeader[13] = 0;
	//Bits per pixel (RGB)
	informationsHeader[14] = 24;
	informationsHeader[15] = 0;
	//Compression (No compression)
	informationsHeader[16] = 0;
	informationsHeader[17] = 0;
	informationsHeader[18] = 0;
	informationsHeader[19] = 0;
	//Image size (No compression)
	informationsHeader[20] = 0;
	informationsHeader[21] = 0;
	informationsHeader[22] = 0;
	informationsHeader[23] = 0;
	//x pixels per meter (Not specified)
	informationsHeader[24] = 0;
	informationsHeader[25] = 0;
	informationsHeader[26] = 0;
	informationsHeader[27] = 0;
	//Y pixels per meter (Not specified)
	informationsHeader[28] = 0;
	informationsHeader[29] = 0;
	informationsHeader[30] = 0;
	informationsHeader[31] = 0;
	//Total colors (color palette not used)
	informationsHeader[32] = 0;
	informationsHeader[33] = 0;
	informationsHeader[34] = 0;
	informationsHeader[35] = 0;
	//Transport colors (Generally ignored)
	informationsHeader[36] = 0;
	informationsHeader[37] = 0;
	informationsHeader[38] = 0;
	informationsHeader[39] = 0;

	f.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
	//erro aqui
	f.write(reinterpret_cast<char*>(informationsHeader), informationHeaderSize);

	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			unsigned char r = static_cast<unsigned char>(GetColor(x, y).r * 255.0f);
			unsigned char g = static_cast<unsigned char>(GetColor(x, y).g * 255.0f);
			unsigned char b = static_cast<unsigned char>(GetColor(x, y).b * 255.0f);

			unsigned char color[] = { b, g, r };

			//3 because the color has 3 bytes
			f.write(reinterpret_cast<char*>(color), 3);
		}
		f.write(reinterpret_cast<char*>(bmPad), paddingAmount);
	}
	f.close();
	std::cout << "File created\n";
}


//Link from the Video
//https://www.youtube.com/watch?v=vqT5j38bWGg&t=161s