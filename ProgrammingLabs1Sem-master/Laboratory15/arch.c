#include "arch.h"
#include "afile.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

ARCH* packArch(unsigned long filesCount, char** fileNames)
{
    AFILE** afiles;
    afiles = malloc(sizeof(AFILE*) * filesCount);
    for (int i = 0; i < filesCount; ++i)
    {
        afiles[i] = malloc(sizeof(AFILE));
        afiles[i] = readFile(fileNames[i]);
    }
    return packArchA(filesCount, afiles);
}

ARCH* packArchA(unsigned long filesCount, AFILE** afiles)
{
    ARCH* arch;
    arch = malloc(sizeof(ARCH));
    arch->filesCount = filesCount;
    arch->files = malloc(sizeof(afiles));
    for (int i = 0 ; i < filesCount; ++i)
    {
        arch->files[i] = malloc(sizeof(afiles[i]));
        arch->files[i] = afiles[i];
    }
    return arch;
}

void writeArch(char* archName, ARCH* arch)
{
    FILE* outputFile = fopen(archName, "wb");

    fwrite(&arch->filesCount, sizeof(arch->filesCount), 1, outputFile);

    for (int i = 0; i < arch->filesCount; ++i)
    {
        fwrite(&arch->files[i]->nameSize, sizeof(arch->files[i]->nameSize), 1, outputFile);
        fwrite(arch->files[i]->fileName, arch->files[i]->nameSize, 1, outputFile);
        fwrite(&arch->files[i]->dataSize, sizeof(arch->files[i]->dataSize), 1, outputFile);
        fwrite(arch->files[i]->fileData, arch->files[i]->dataSize, 1, outputFile);
    } 
    
    fclose(outputFile);
}

ARCH* createArch(char* archName, unsigned long filesCount, char** fileNames)
{
    
    ARCH* arch = packArch(filesCount, fileNames);

    writeArch(archName, arch);

    return arch;
}

void printFileListA(ARCH* arch)
{
    for (int i = 0; i < arch->filesCount; ++i)
    {
        printf("%s ", arch->files[i]->fileName);
    }
    printf("\n");
}

ARCH* readArch(char* archName)
{
    FILE* inputFile = fopen(archName, "rb");

    ARCH* arch;
    arch = malloc(sizeof(ARCH));

    fread(&arch->filesCount, sizeof(&arch->filesCount), 1, inputFile);

    arch->files = malloc(sizeof(AFILE*) * arch->filesCount);
    for (int i = 0; i < arch->filesCount; ++i)
    {
        arch->files[i] = malloc(sizeof(AFILE));

        fread(&arch->files[i]->nameSize, sizeof(arch->files[i]->nameSize), 1, inputFile);
        arch->files[i]->fileName = malloc(arch->files[i]->nameSize);
        fread(arch->files[i]->fileName, arch->files[i]->nameSize, 1, inputFile);

        fread(&arch->files[i]->dataSize, sizeof(arch->files[i]->dataSize), 1, inputFile);
        arch->files[i]->fileData = malloc(arch->files[i]->dataSize);
        fread(arch->files[i]->fileData, arch->files[i]->dataSize, 1, inputFile);
    }

    return arch;
}

void printFileList(char* archName)
{
    ARCH* arch = readArch(archName);
    printFileListA(arch);
}

void extractArchA(ARCH* arch)
{
    for (int i = 0; i < arch->filesCount; ++i)
    {
        writeFile(arch->files[i]);
    }
}

void extractArch(char* archName)
{
    ARCH* arch = readArch(archName);
    extractArchA(arch);
}