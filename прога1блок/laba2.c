#include <stdio.h>
#include <math.h>

int main(void) {
    float z1;
    float a;
    scanf ("%f",&a);
    z1=pow((((1+a+pow (a,2))/(2*a+pow(a,2)))+2-((1-a+pow(a,2))/(2*a-pow(a,2)))),-1)*(5-2*pow (a,2));
    printf ("z1=%f \n",z1);
    float z2;
    z2=((4-a*a)/2);
    printf ("z2=%f",z2);
    return 0;
    }
