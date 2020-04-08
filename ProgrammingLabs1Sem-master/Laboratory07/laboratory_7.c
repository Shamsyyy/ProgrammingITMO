// Laboratory work #7
// Option 11

#include <stdio.h>

// Task #2
// Create a structure of square
struct Square
{
    int a; // length of side
};

struct Square CreateSquare(int a)
{
    struct Square sq;
    sq.a = a;
}

int GetSquareArea(struct Square sq)
{
    return sq.a * sq.a;
}

int main(int argc, char **agrv) 
{
    // Task #1
    // Create enum of day of week and print a Monday number
    enum Day
    {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };
    printf("Monday = %d\n", Monday);

    // Creating square and pritindg its area
    struct Square sq = CreateSquare(10);
    printf("Area of square with side %d equal %d\n", sq.a, GetSquareArea(sq));

    // Task #3
    // Create a bit-field for buttons
    struct Buttons
    {
        unsigned NumLock: 1;
        unsigned CapsLock: 1;
        unsigned ScrollLock: 1;
    };
    union Checker
    {
        unsigned number;
        struct Buttons Status;
    };
    // Read hex number
    union Checker CheckStatus;
    scanf("%x", &CheckStatus.number);
    printf("NumLock = %d\n", CheckStatus.Status.NumLock);
    printf("CapsLock = %d\n", CheckStatus.Status.CapsLock);
    printf("ScrollLock = %d\n", CheckStatus.Status.ScrollLock);

}   