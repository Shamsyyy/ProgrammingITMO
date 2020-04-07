
#include <stdio.h>
#include <malloc.h>
#include <math.h>

int getGcd(int a, int b) //Наибольший общий делитель
{
    if (a == 0) return b;
    return getGcd(b % a, a);
}

int getLcm(int a, int b) //Наименьшее общее кратное
{
    int gcd = getGcd(a, b);
    return a * b / gcd;

}

int naturial (int c) //Сумма цифр натурального числа
{
    if(!c)
        return 0;
    return (c % 10) + naturial(c / 10);
}



int main(int argc, char **agrv)
{
    //1
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int gcd = getGcd(a, b);
    int lcm = getLcm(a, b);
    printf("GCD: %d\n", gcd);
    printf("LCM: %d\n", lcm);
    //4
    int c;
    printf("Enter a natural number: ");
    scanf("%d", &c);
    int nat = naturial(c);
    printf("Sum of digits natural number: %d\n", nat);

}
