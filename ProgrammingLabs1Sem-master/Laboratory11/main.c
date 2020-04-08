// Laboratory work #11
// Option 11

#include "stdio.h"
#include "rectangle.h"

int main()
{
    struct Rectangle rect;
    scanf("%f %f", &rect.x1, &rect.y1);
    scanf("%f %f", &rect.x2, &rect.y2);
    printf("Perimeter: %f\n", rectanglePerimeter(rect));
    printf("Area: %f\n", rectangleArea(rect));
    return 0;
}