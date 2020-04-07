#include <stdio.h>
#include <string.h>

int main(int argc, char **agrv)
{   //1
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
    printf(" Enter the number to which you want to enter simple ");
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


