#include "gameoflife.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#define _CRT_SECURE_NO_WARNINGS

GameObject* newGame(BMP* image, int maxGenCount, int fixationFrequency, char* dir)
{
	GameObject* game = malloc(sizeof(GameObject));
	game->width = image->infoHeader->Width;
	game->height = image->infoHeader->Height;

	game->maxGenCount = maxGenCount;
	game->fixationFrequency = fixationFrequency;
	game->gen = 0;
	game->dir = dir;

	game->field = malloc(game->height * sizeof(char*));
	int endOffset = (4 - (sizeof(BYTE) * image->infoHeader->Width) % 4) % 4;
	for (int i = 0; i < game->height; ++i)
	{
		game->field[i] = malloc(game->width * sizeof(char));
		for (int j = 0; j < game->width; ++j)
		{
			game->field[i][j] = image->pixelData[i * game->width + j + i * endOffset] != 255 ? 1 : 0;
		}
	}

	return game;
}

char checkCell(GameObject* game, int x, int y)
{
	if (x < 0 || x >= game->height)
		return 0;
	if (y < 0 || y >= game->width)
		return 0;
	else
		return game->field[x][y];
}

char neighborsCount(GameObject* game, int x, int y)
{
	char cnt = 0;
	cnt += checkCell(game, x - 1, y);
	cnt += checkCell(game, x - 1, y - 1);
	cnt += checkCell(game, x - 1, y + 1);
	cnt += checkCell(game, x, y - 1);
	cnt += checkCell(game, x, y + 1);
	cnt += checkCell(game, x + 1, y);
	cnt += checkCell(game, x + 1, y - 1);
	cnt += checkCell(game, x + 1, y + 1);
	return cnt;
}

char newState(GameObject* game, int x, int y)
{
	int nghCnt = neighborsCount(game, x, y);
	if (game->field[x][y])
	{
		if (nghCnt == 2 || nghCnt == 3)
			return 1;
		else
			return 0;
	}
	else
	{
		if (nghCnt == 3)
			return 1;
		else
			return 0;
	}
}

char changes(GameObject* game)
{
	char changed = 0;
	for (int i = 0; i < game->height; ++i)
	{
		for (int j = 0; j < game->width; ++j)
		{
			if (game->field[i][j] != game->nextGenField[i][j])
				changed = 1;
		}
	}
	return changed;
}

char nextGeneration(GameObject* game)
{
	game->nextGenField = malloc(sizeof(char*) * game->height);
	for (int i = 0; i < game->height; ++i)
	{
		game->nextGenField[i] = malloc(sizeof(char) * game->width);
		for (int j = 0; j < game->width; ++j)
		{
			game->nextGenField[i][j] = newState(game, i, j);
		}
	}
	game->gen++;
	char changed = changes(game);
	game->field = game->nextGenField;
	return changed;
}

void outGeneration(GameObject* game, BMP* image)
{
	int width = game->width;
	int height = game->height;

	int endOffset = (4 - (sizeof(BYTE) * image->infoHeader->Width) % 4) % 4;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			image->pixelData[i * width + j + i * endOffset] = game->field[i][j] ? 0 : 255;
		}
	}

	char fileName[100];
	sprintf(fileName, "%d", game->gen);
	int i = 0;
	while (fileName[i] >= '0' && fileName[i] <= '9') i++;

	fileName[i++] = '.';
	fileName[i++] = 'b';
	fileName[i++] = 'm';
	fileName[i++] = 'p';
	fileName[i++] = '\0';
	// outData(image);
	char* dir = malloc(sizeof(char)*100);
	dir = strcpy(dir, game->dir);
	mkdir(dir);
	dir = strcat(dir, fileName);

	//printf("%s\n", dir);
	writeBMP(image, dir);
}

void play(GameObject* game, BMP* image)
{
	while (1)
	{
		if (game->gen % game->fixationFrequency == 0)
			outGeneration(game, image);
		if (game->maxGenCount && game->gen == game->maxGenCount)
			break;
		if (!nextGeneration(game))
			break;
	}
}