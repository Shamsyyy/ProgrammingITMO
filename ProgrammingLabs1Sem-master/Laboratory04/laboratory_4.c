// Laboratory work #4
// Option 11

#include <stdio.h>

int main(int argc, char **agrv) 
{
    // Task #1
    // Read number and check for range 11-12
    int number;
    scanf("%d", &number);
    printf("%d\n", number >= 11 && number <= 12);

    // Task #2
    // Read number and check the 11 bit
    int another_number;
    scanf("%d", &another_number);
    printf("%d", (another_number >> 10) & 1);
}   