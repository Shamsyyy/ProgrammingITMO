#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "isosceles_triangle.h"

int main() {
	int x1, x2, x3, y1, y2, y3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	struct IsoscelesTriangle tr = newIsoscelesTriangle(x1, y1, x2, y2, x3, y3);
	printf("Perimetr is %lf\nSize is %lf", isoscelesTrianglePerimetr(tr), isoscelesTriangleSize(tr));
	return 0;
}
