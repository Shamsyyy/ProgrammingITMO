#ifndef ARGTOOLS_H
#define ARGTOOLS_H

typedef struct tagSETTINGS
{
    char create;
    char list;
    char extract;
    unsigned long filesCount;
    char* fileNames[1000];
    char* archName;
} SETTINGS;

SETTINGS* setSettings(int argc, char** argv);
void printSettings(SETTINGS* settings);

#endif