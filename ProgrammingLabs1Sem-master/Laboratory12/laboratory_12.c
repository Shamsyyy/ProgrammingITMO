// Laboratory work #12
// Option 11

#include "stdio.h"
#include "time.h"

int main(int argc, char* argv[])
{
    char* fileName = argv[1];
    freopen(fileName, "w", stdout);
    
    time_t timer = time(NULL);
    for (int i = 0; i < 10; ++i)
    {
        struct tm* dateTime = localtime(&timer);
        char strDate[40] = {0};
        strftime(strDate, 40, "%d.%m.%Y", dateTime);
        printf("%s\n", strDate);
        timer += 24 * 60 * 60;
    }
}