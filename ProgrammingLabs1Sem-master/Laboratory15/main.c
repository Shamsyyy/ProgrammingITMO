#include "afile.h"
#include "arch.h"
#include "stdlib.h"
#include "argtools.h"

int main(int argc, char** argv)
{
    SETTINGS* settings = setSettings(argc, argv);
    // printSettings(settings);
    if (settings->create)
    {
        createArch(settings->archName, settings->filesCount, settings->fileNames);
    }
    if (settings->extract)
    {
        extractArch(settings->archName);
    }
    if (settings->list)
    {
        printFileList(settings->archName);
    }
    return 0;
}