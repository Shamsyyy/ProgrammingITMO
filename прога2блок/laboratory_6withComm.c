// Laboratory work #6
// Option 11

#include <stdio.h>
#include <malloc.h>

int main(int argc, int **agrv)
{
    // Task #1
    // Create array and pointer to it, set elments using array index and print using pointer
    int array[4];
    int* pointer_to_array = array;
    // Set
    array[0] = '0';
    array[1] = '3';
    array[2] = '5';
    array[3] = '7';
    // Print
    for (int i = 0; i < 4; ++i)
    {
        printf("%c ", *(pointer_to_array + i));
    }
    printf("\n");

    // Task #2
    // Create a array in dinamic memory
    int* dinamic_array = (int*)malloc(4 * sizeof(int));
    dinamic_array[0] = '0';
    dinamic_array[1] = '3';
    dinamic_array[2] = '5';
    dinamic_array[3] = '7';
    // int* dinamic_array = calloc(4, sizeof(int));
    for (int i = 0; i < 4; ++i)
    {
        printf("%c ", dinamic_array[i]);
    }
    printf("\n");
    free(dinamic_array);
}
