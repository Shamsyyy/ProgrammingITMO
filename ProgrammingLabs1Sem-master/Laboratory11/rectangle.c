#include "rectangle.h"

float rectanglePerimeter(struct Rectangle rect)
{
    float perimeter = 2 * ((rect.x2 - rect.x1) + (rect.y2 - rect.y1));
    return perimeter;
}

float rectangleArea(struct Rectangle rect)
{
    float area = (rect.x2 - rect.x1) * (rect.y2 - rect.y1);
    return area;
}