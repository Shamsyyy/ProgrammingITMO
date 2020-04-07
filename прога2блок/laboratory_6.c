#include <stdio.h>
#include <malloc.h>

int main(int argc, int **agrv)
{

    int array[4];
    int* pointer_to_array = array;

    array[0] = '0';
    array[1] = '3';
    array[2] = '5';
    array[3] = '7';

    for (int i = 0; i < 4; ++i)
    {
        printf("%c ", *(pointer_to_array + i));
    }
    printf("\n");


    int* dinamic_array = (int*)malloc(4 * sizeof(int));
    dinamic_array[0] = '0';
    dinamic_array[1] = '3';
    dinamic_array[2] = '5';
    dinamic_array[3] = '7';
    for (int i = 0; i < 4; ++i)
    {
        printf("%c ", dinamic_array[i]);
    }
    printf("\n");
    free(dinamic_array);
}
