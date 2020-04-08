// Laboratory work #3
// Option 11

#include <stdio.h>

int main(int argc, char **agrv) 
{
    // Task #1
    // Read decimal number
    int number;
    scanf("%d", &number);

    // Task #2
    // Print hex number
    printf("%x\n", number);

    // Task #3
    // Print octal number, and octal number with 3-bit left shift
    printf("%o\n", number);
    printf("%o\n", number << 3);

    // Task #4
    // Print octal number, and octal number with bit negation
    printf("%o\n", number);
    printf("%o\n", ~number);

    // Task #5
    // Read octal number, and print bit-and of this number and number from Task #1
    int another_number;
    scanf("%o", &another_number);
    printf("%o\n", number & another_number);
}   