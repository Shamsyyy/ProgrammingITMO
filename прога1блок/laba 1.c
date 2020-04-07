#include <stdio.h>
int main(void) {
int a,b;
scanf ("%d", &a);
printf ("%d", ((a>-50) && (a<50)));
scanf ("%d", &b);
int bit;
for (int i=0;i<18;i++){
    bit=b%2;
    b=b/2;
}
printf("%d",b);
return 0;
}
