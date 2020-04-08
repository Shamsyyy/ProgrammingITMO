#ifndef SETTINGS_H
#define SETTINGS_H

typedef struct tagSettings
{
	char* inputFile;
	char* ouputDirectory;
	int maxGenCount;
	int fixationFrequency;
} Settings;

Settings* setSettings(int argc, char* argv[]);

#endif
