#include <math.h>

struct IsoscelesTriangle {
	int x1, x2, x3, y1, y2, y3;
};

struct IsoscelesTriangle newIsoscelesTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	struct IsoscelesTriangle result;
	result.x1 = x1;
	result.y1 = y1;
	result.x2 = x2;
	result.y2 = y2;
	result.x3 = x3;
	result.y3 = y3;
	return result;
}

double sqr(double a) {
	return a * a;
}

double isoscelesTriangleSize(struct IsoscelesTriangle tr) {
	double a = sqrt(sqr(tr.x1 - tr.x2) + sqr(tr.y1 - tr.y2));
	double b = sqrt(sqr(tr.x3 - tr.x2) + sqr(tr.y3 - tr.y2));
	double c = sqrt(sqr(tr.x1 - tr.x3) + sqr(tr.y1 - tr.y3));
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}


double isoscelesTrianglePerimetr(struct IsoscelesTriangle tr) {
	double a = sqrt(sqr(tr.x1 - tr.x2) + sqr(tr.y1 - tr.y2));
	double b = sqrt(sqr(tr.x3 - tr.x2) + sqr(tr.y3 - tr.y2));
	double c = sqrt(sqr(tr.x1 - tr.x3) + sqr(tr.y1 - tr.y3));
	return a + b + c;
}
