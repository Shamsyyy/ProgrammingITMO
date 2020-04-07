#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3


int main()
{
    int a [7] = {123, 123, 123, 123, 456, 321, 1};
    printf ("%d %d %d %d %d %d %d \n",a[0],a[1],a[2],a[3],a[4],a[5],a[6]); //вывожу массив на экран
    getchar();
    int i, j;
    int mas[N][N];
    printf("Vvelite 1 matricu 2x2 \n");
    for (i=0;i<2;i++)
      for (j=0;j<2;j++)
        {
             scanf("%d",&mas[i][j]);
        }
    for(i=0;i<2;i++)
       {
        for (j=0;j<2;j++)
        {
              printf("%d  ",mas[i][j]);
        }
        printf("\n");
       }
    getch();
        int q, p;
    int mas2[N][N];
    printf("Vvedite 2 matricu 2x2 \n");
    for (i=0;i<2;i++)
      for (j=0;j<2;j++)
        {
             scanf("%d",&mas2 [i][j]);
        }
    for(i=0;i<2;i++)
       {
        for (j=0;j<2;j++)
        {
              printf("%d  ",mas2 [i][j]);
        }
        printf("\n");
       }
    getch();
    int k,m,n;
    q=2;
    m=2;
    n=2;
    int mas3[i][j];
    for(i = 0; i < m; i++)
        for(j = 0; j < q; j++)
        {
            mas3[i][j] = 0;
            for(k = 0; k < n; k++)
                mas3[i][j] += mas[i][k] * mas2[k][j];
        }
    printf("peremnojenie matric:\n");
            for(i=0;i<2;i++)
       {

        for (j=0;j<2;j++)
        {
              printf("%d  ",mas3 [i][j]);
        }
        printf("\n");
       }

    return 0;
}
