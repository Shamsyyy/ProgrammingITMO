#include "bmp.h"
#include "gameoflife.h"
#include "settings.h"
#include "stdio.h"

#define _CRT_SECURE_NO_WARNINGS

int main(int argc, char* argv[])
{
	Settings* settings = setSettings(argc, argv);
	BMP* image;
	image = readBMP(settings->inputFile);
	// printf("%dx%d\n", image->infoHeader->Height, image->infoHeader->Width);
	GameObject* game = newGame(image, settings->maxGenCount, settings->fixationFrequency, settings->ouputDirectory);
	play(game, image);
	return 0;
}