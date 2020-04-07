#if !defined H_ISOSCELES_TRIANGLE
#define H_ISOSCELES_TRIANGLE
struct IsoscelesTriangle {
	int x1, x2, x3, y1, y2, y3;
};

double sqr(double a);
struct IsoscelesTriangle newIsoscelesTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
double isoscelesTriangleSize(struct IsoscelesTriangle tr);
double isoscelesTrianglePerimetr(struct IsoscelesTriangle tr);
#endif