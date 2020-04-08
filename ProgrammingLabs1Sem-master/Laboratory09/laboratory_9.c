// Laboratory work #9
// Option 11

#include <stdio.h>
#include <string.h>

int main(int argc, char **agrv) 
{
    // Task #1
    // Get string with console and count number of numbers and letters
    char string[100];
    printf("Enter string: ");
    scanf("%s", string);

    int numbersCnt = 0;
    int lettersCnt = 0;
    for (int i = 0; i < strlen(string); ++i)
    {
        if ('0' <= string[i] && string[i] <= '9')
        {
            numbersCnt++;
        }
        else if ('a' <= string[i] && string[i] <= 'z' || 'A' <= string[i] && string[i] <= 'Z')
        {
            lettersCnt++;
        }
    }

    printf("Numbers count: %d\n", numbersCnt);
    printf("Letters count: %d\n", lettersCnt);

    // Task #2
    // Calculate the cost of mobile communication
    int minutes;
    int monthly;
    int rate;
    printf("Enter minutes count: ");
    scanf("%d", &minutes);
    printf("Enter monthly free: ");
    scanf("%d", &monthly);
    printf("Enter increased rate: ");
    scanf("%d", &rate);

    int payment = monthly;
    if (minutes - 499 > 0)
    {
        payment += rate * (minutes - 499);
    }

    printf("Payment: %d\n", payment);
}   