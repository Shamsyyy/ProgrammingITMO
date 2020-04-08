// Laboratory work #10
// Option 11

#include <stdio.h>
#include <malloc.h>
#include <math.h>

int getGcd(int a, int b)
{
    if (a == 0) return b;
    return getGcd(b % a, a);
}

int getLcm(int a, int b)
{
    int gcd = getGcd(a, b);
    return a * b / gcd;
}

struct Point
{
    float x;
    float y;
};

float** getMatrixOfDistances(struct Point* points, int n)
{
    float** pointerToMatrix = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < n; ++i)
    {
        int lineIterator = 0;
        pointerToMatrix[i] = (float*)malloc((n - 1) * sizeof(float*));
        for (int j = 0; j < n; ++j)
        {
            if (i == j) continue;
            float dist = sqrt(pow((points[i].x - points[j].x), 2) + pow((points[i].y - points[j].y), 2));
            pointerToMatrix[i][lineIterator++] = dist;
        }
    }
    return pointerToMatrix;
}

int main(int argc, char **agrv) 
{
    // Task #1
    // Get gcd and lcm of two numbers
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int gcd = getGcd(a, b);
    int lcm = getLcm(a, b);
    printf("GCD: %d\n", gcd);
    printf("LCM: %d\n", lcm);

    // Task #2
    // Get matrix of distances between n points 
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);

    struct Point points[1000];
    for (int i = 0; i < n; ++i)
    {
        printf("Enter %d point coordinates ", (i + 1));
        scanf("%f %f", &points[i].x, &points[i].y);
    }

    float** matrix = getMatrixOfDistances(points, n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }
}   