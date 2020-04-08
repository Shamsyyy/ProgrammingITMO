#include "stdlib.h"
#include "settings.h"
#include "stdio.h"
#include "string.h"

Settings* setSettings(int argc, char* argv[])
{
	Settings* settings;
	settings = malloc(sizeof(Settings));
	settings->maxGenCount = 0;
	settings->fixationFrequency = 1;

	for (int i = 1; i < argc; ++i)
	{
		if (strcmp(argv[i], "--input") == 0)
		{
			if (i + 1 < argc)
			{
				settings->inputFile = argv[i + 1];
			}
		}
		else if (strcmp(argv[i], "--output") == 0)
		{
			if (i + 1 < argc)
			{
				settings->ouputDirectory = argv[i + 1];
			}
		}
		else if (strcmp(argv[i], "--max_iter") == 0)
		{
			if (i + 1 < argc)
			{
				settings->maxGenCount = atoi(argv[i + 1]);
			}
		}
		else if (strcmp(argv[i], "--dump_freq") == 0)
		{
			if (i + 1 < argc)
			{
				settings->fixationFrequency = atoi(argv[i + 1]);
			}
		}
	}
	return settings;
}