#ifndef AFILE_H
#define AFILE_H

#pragma pack(push, 1)
typedef struct tagAFILE
{
    char nameSize;
    char* fileName;
    unsigned long dataSize;
    unsigned char* fileData;
} AFILE;
#pragma pack(pop)

AFILE* readFile(char* fileName);
void writeFile(AFILE* afile);
void printFileData(AFILE* afile);

#endif