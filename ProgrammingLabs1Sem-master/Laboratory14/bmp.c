#include "stdio.h"
#include "stdlib.h"
#include "bmp.h"

#define _CRT_SECURE_NO_WARNINGS

BMP* readBMP(char* fileDirectory)
{
	// printf("\nReading from %s started!\n", fileDirectory);

	FILE* fin;
	fin = fopen(fileDirectory, "rb");
	if (fin == NULL)
	{
		printf("Read from file error ocured!");
		exit(404);
	}

	BMP* image = malloc(sizeof(BMP));
	image->fileHeader = malloc(sizeof(BITMAPFILEHEADER));
	fread(image->fileHeader, sizeof(BITMAPFILEHEADER), 1, fin);
	image->infoHeader = malloc(sizeof(BITMAPINFOHEADER));
	fread(image->infoHeader, sizeof(BITMAPINFOHEADER), 1, fin);

	int sizeOfNone = image->fileHeader->Offset - (sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER));
	image->none = malloc(sizeOfNone);
	fread(image->none, sizeOfNone, 1, fin);

	int endOffset = (4 - (sizeof(BYTE) * image->infoHeader->Width) % 4) % 4;
	int sizeOfPixelData = sizeof(BYTE) * image->infoHeader->Height * image->infoHeader->Width
		+ image->infoHeader->Height * endOffset;
	image->pixelData = malloc(sizeOfPixelData);
	fread(image->pixelData, sizeOfPixelData, 1, fin);

	fclose(fin);
	// printf("Reading from %s finished!\n", fileDirectory);

	// printf("!%d\n", sizeOfPixelData);

	return image;
}

void writeBMP(BMP* image, char* fileDirectory)
{
	// printf("\nWriting to %s started!\n", fileDirectory);
	FILE* fout;
	fout = fopen(fileDirectory, "wb+");
	if (fout == NULL)
	{
		printf("Write to file error ocured!");
		exit(404);
	}

	int sizeOfNone = image->fileHeader->Offset - (sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER));
	int endOffset = (4 - (sizeof(BYTE) * image->infoHeader->Width) % 4) % 4;
	int sizeOfPixelData = sizeof(BYTE) * image->infoHeader->Height * image->infoHeader->Width
		+ image->infoHeader->Height * endOffset;

	fwrite(image->fileHeader, sizeof(BITMAPFILEHEADER), 1, fout);
	fwrite(image->infoHeader, sizeof(BITMAPINFOHEADER), 1, fout);
	fwrite(image->none, sizeOfNone, 1, fout);
	fwrite(image->pixelData, sizeOfPixelData, 1, fout);

	fclose(fout);
	// printf("Writing to %s finished successfuly!\n", fileDirectory);
}

void outData(BMP* image)
{
	for (int i = 0; i < image->infoHeader->Height; ++i)
	{
		for (int j = 0; j < image->infoHeader->Width; ++j)
		{
			printf("%d ", image->pixelData[i * image->infoHeader->Width + j]);
		}
		printf("\n");
	}
}