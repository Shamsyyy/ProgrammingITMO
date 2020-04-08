#ifndef BMP_H
#define BMP_H
#pragma pack(push, 1)

typedef unsigned short  WORD;
typedef unsigned long   DWORD;
typedef unsigned char   BYTE;
typedef long            LONG;


typedef struct tagBITMAPFILEHEADER
{
	WORD     Type;
	DWORD    Size;
	WORD     Reserved1;
	WORD     Reserved2;
	DWORD    Offset;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
	DWORD    Size;
	LONG     Width;
	LONG     Height;
	WORD     Planes;
	WORD     BitCount;
	DWORD    Compression;
	DWORD    SizeImage;
	LONG     XPelsPerMeter;
	LONG     YPelsPerMeter;
	DWORD    ClrUsed;
	DWORD    ClrImportant;
} BITMAPINFOHEADER;

typedef struct tagBMP
{
	BITMAPFILEHEADER* fileHeader;
	BITMAPINFOHEADER* infoHeader;
	BYTE* none;
	BYTE* pixelData;
} BMP;
#pragma pack(pop)
BMP* readBMP(char* fileDirectory);
void writeBMP(BMP* image, char* fileDirectory);
void outData(BMP* image);
#endif 