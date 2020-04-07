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

    //4
    int maxn;
    printf("Введите число, до которого нужно ввести простые ");
    scanf("%d", &maxn);
    int arr[1001]; // решето Эратосфена
    memset(arr, 0, 1001);
    for (int i = 2; i <= maxn; i++) {
        if (!arr[i]) {  //Если наше число простое
            printf("%d ", i); //То выводим его
            for (int j = i * i; j <= maxn; j += i) {
                arr[j] = 1;
            }
        }
    }
    return 0;
}
