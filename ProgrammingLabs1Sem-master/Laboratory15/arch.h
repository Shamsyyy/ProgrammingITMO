#ifndef ARCH_H
#define ARCH_H

#include "afile.h"

#pragma pack(push, 1)
typedef struct tagARCH
{
    unsigned long filesCount;
    AFILE** files;
} ARCH;
#pragma pack(pop)

ARCH* packArch(unsigned long filesCount, char** fileNames);
ARCH* packArchA(unsigned long filesCount, AFILE** afiles);
void writeArch(char* archName, ARCH* arch);
ARCH* createArch(char* archName, unsigned long filesCount, char** fileNames);
ARCH* readArch(char* archName);
void outArch(ARCH* arch);
void printFileListA(ARCH* arch);
void printFileList(char* archName);
void extractArchA(ARCH* arch);
void extractArch(char* archName);
#endif