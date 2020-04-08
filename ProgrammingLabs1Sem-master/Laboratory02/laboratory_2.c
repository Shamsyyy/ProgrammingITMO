// Laboratory work #2
// Option 11

#include <stdio.h>
#include <math.h>

int main(int argc, char **agrv) 
{
    // Task
    // Evaluate expressions
    const char ERROR_MESSAGE[] = "Error!";
    float a;
    scanf("%f", &a);
    // Negative under root exception
    if (a < 0) 
    {
        printf("%s", ERROR_MESSAGE);
    }
    else
    {
        // Zero division exception
        if (a == 0 || a == -sqrt(2) || a == -2)
        {
            printf("%s", ERROR_MESSAGE);    
        }
        else
        {
                // First expression
                float z1 = ((a + 2) / (a * sqrt(2)) - a / (a - sqrt(2) * a)) * (sqrt(a) - sqrt(2)) / (a + 2);
                printf("z1 = %f\n", z1);
        }
        // Second expression
        float z2 = 1 / (sqrt(a) + sqrt(2));
        printf("z2 = %f\n", z2);
    }
    
    
   
}