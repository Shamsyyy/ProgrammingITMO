#include <stdio.h>
int main() {
int a;
printf ("1. a=");
scanf ("%o",&a);
printf ("2. a=%x\n",a);
printf ("3.1. a=%o\n",a);
printf ("3.2. a=%o\n", a << 3);
printf ("4.1. a=%o\n",a);
printf ("4.2. a=%o\n",~a);
printf ("5.1. a=%o\n",a);
int b;
printf ("b=");
scanf ("%o",&b);
printf ("\n 5.2 a & b=%o\n", b & a);
return 0;
}
