#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "bmp.h"

typedef struct tagGameObject {
	int     width;
	int     height;
	int     maxGenCount;
	int     fixationFrequency;
	int     gen;
	char** field;
	char** nextGenField;
	char* dir;
} GameObject;

GameObject* newGame(BMP* image, int maxGenCount, int fixationFrequency, char* dir);
char nextGeneration(GameObject* game);
char neighborsCount(GameObject* game, int x, int y);
char checkCell(GameObject* game, int x, int y);
char newState(GameObject* game, int x, int y);
void play(GameObject* game, BMP* image);
void outGeneration(GameObject* game, BMP* image);
char changes(GameObject* game);
#endif