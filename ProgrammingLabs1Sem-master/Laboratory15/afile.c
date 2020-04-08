#include "afile.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

AFILE* readFile(char* fileName)
{
    FILE* inputFile = fopen(fileName, "rb");
    AFILE* afile;
    afile = malloc(sizeof(AFILE));

    afile->nameSize = strlen(fileName) + 1;
    afile->fileName = malloc(sizeof(char) * afile->nameSize);
    strcpy(afile->fileName, fileName);
    afile->fileName[afile->nameSize - 1] = '\0';
    fseek(inputFile, 0, SEEK_END);
    afile->dataSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);
    afile->fileData = malloc(sizeof(char) * afile->dataSize);
    fread(afile->fileData, afile->dataSize, 1, inputFile);

    // printFileData(afile);

    fclose(inputFile);
    return afile;
}

void writeFile(AFILE* afile)
{
    printf("%s\n", afile->fileName);
    FILE* outputFile = fopen(afile->fileName, "wb");
    fwrite(afile->fileData, afile->dataSize, 1, outputFile);
    fclose(outputFile);
}

void printFileData(AFILE* afile)
{
    printf("%d\n", afile->dataSize);
    for (int i = 0; i < afile->dataSize; ++i)
    {
        printf("%x ", afile->fileData[i]);
    }
    printf("\n");
}