// Laboratory work #5
// Option 11

#include <stdio.h>

int main(int argc, char **agrv) 
{
    // Task #1
    // Create array and print it
    int array[7] = {10, 20, 30, 40, 50, 60, 70};
    printf("array = [");
    int i;
    for (i = 0; i < 7; ++i)
    {
        if (i < 7 - 1)
            printf("%d, ", array[i]);
        else
            printf("%d", array[i]);
    }
    printf("]\n");

    // Task #2
    // Multiply two square matrixs and print result
    int matrix_1[2][2] = {{1, 2}, {3, 1}};
    int matrix_2[2][2] = {{1, 1}, {0, 2}};
    int result_matrix[2][2] = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                result_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
    printf("%d,\t%d\n", result_matrix[0][0], result_matrix[0][1]);
    printf("%d,\t%d\n", result_matrix[1][0], result_matrix[1][1]);
}   