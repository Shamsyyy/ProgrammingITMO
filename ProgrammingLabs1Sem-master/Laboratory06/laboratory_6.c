// Laboratory work #6
// Option 11

#include <stdio.h>
#include <malloc.h>

int main(int argc, char **agrv) 
{
    // Task #1
    // Create array and pointer to it, set elments using array index and print using pointer
    char array[4];
    char* pointer_to_array = array; 
    // Set 
    array[0] = 'a';
    array[1] = 'b';
    array[2] = 'c';
    array[3] = 'd';
    // Print
    for (int i = 0; i < 4; ++i)
    {
        printf("%c ", *(pointer_to_array + i));
    }
    printf("\n");

    // Task #2
    // Create a array in dinamic memory
    char* dinamic_array = (char*)malloc(4 * sizeof(char));
    dinamic_array[0] = 'a';
    dinamic_array[1] = 'b';
    dinamic_array[2] = 'c';
    dinamic_array[3] = 'd';
    // char* dinamic_array = calloc(4, sizeof(char));
    for (int i = 0; i < 4; ++i)
    {
        printf("%c ", dinamic_array[i]);
    }
    printf("\n");
    free(dinamic_array);
}   