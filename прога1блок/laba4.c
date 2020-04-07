#include <stdio.h>
    int check_bit(int b, int n){
    int bit;
    for(int i=0; i<n; i++){
    bit = b%2;
    b = b/2;
    }
    return bit;
}
int main(void) {
int a,b;
scanf ("%d", &a);
printf ("%d", ((a>-50) && (a<50)));
scanf ("%d", &b);
b = check_bit (b,18);
printf ("%d",&b);

return 0;
}
