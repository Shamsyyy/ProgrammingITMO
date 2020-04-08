#include "argtools.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

SETTINGS* setSettings(int argc, char** argv)
{
    SETTINGS* settings;
    settings = malloc(sizeof(SETTINGS));
    settings->create = 0;
    settings->extract = 0;
    settings->list = 0;
    settings->filesCount = 0;

    for (int i = 1; i < argc; ++i)
    {
        if (strcmp("--create", argv[i]) == 0)
        {
            settings->create = 1;
        } 
        else if (strcmp("--extract", argv[i]) == 0)
        {
            settings->extract = 1;
        } 
        else if (strcmp("--list", argv[i]) == 0)
        {
            settings->list = 1;
        } 
        else if (strcmp("--file", argv[i]) == 0)
        {
            settings->archName = malloc(sizeof(char) * (strlen(argv[++i]) + 1));
            strcpy(settings->archName, argv[i]);
            settings->archName[strlen(argv[i])] = '\0';
        }
        else
        {
            printf("%s\n", argv[i]);
            settings->fileNames[settings->filesCount] = malloc(sizeof(char) * (strlen(argv[i]) + 1));
            strcpy(settings->fileNames[settings->filesCount], argv[i]);
            settings->fileNames[settings->filesCount++][strlen(argv[i])] = '\0';
        }  
        
    }
    return settings;
}

void printSettings(SETTINGS* settings)
{
    printf("Create: %d\n", settings->create);
    printf("Extract: %d\n", settings->extract);
    printf("List: %d\n", settings->list);
    printf("Arch name: %s\n", settings->archName);
    printf("Files count: %d\n", settings->filesCount);
}