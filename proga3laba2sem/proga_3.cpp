#include <iostream>
#include "proga_3.h"

Triangle::Triangle(std::pair<float, float> a, std::pair<float, float> b, std::pair<float, float> c) {
	A = a;
	B = b;
	C = c;
	AB = sqrt(pow((B.first - A.first), 2) + pow((B.second - A.second), 2)); // Длина ребра
	BC = sqrt(pow((C.first - B.first), 2) + pow((C.second - B.second), 2));
	AC = sqrt(pow((C.first - A.first), 2) + pow((C.second - A.second), 2));
	p = (AB + BC + AC) / 2;
	S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
}
void Triangle::print() {
	printf("A: %f %f\nB: %f %f\nC: %f %f\n", A.first, A.second, B.first, B.second, C.first, C.second);
	printf("AB, BC, AC: %f %f %f\n", AB, BC, AC);
	printf("Area: %f\n", S);
}
bool operator == (Triangle t1, Triangle t2) {
	return t1.S == t2.S;
}
bool operator != (Triangle t1, Triangle t2) {
	return t1.S != t2.S;
}
bool operator < (Triangle t1, Triangle t2) {
	return t1.S < t2.S;
}
bool operator > (Triangle t1, Triangle t2) {
	return t1.S > t2.S;
}
Triangle operator + (Triangle t1, std::pair<float, float> v) { // сдвиг треугольника на вектор
	Triangle t2(make_pair(t1.A.first + v.first, t1.A.second + v.second),
		make_pair(t1.B.first + v.first, t1.B.second + v.second),
		make_pair(t1.C.first + v.first, t1.C.second + v.second));
	return t2;
}

Steck::Steck(vector <float> _s) {
	s = _s;
}
Steck::Steck() {
}
void Steck::print() {
	for (size_t i = 0; i < s.size(); i++) {
		printf("%f ", s[i]);
	}
	printf("\n");
}
void operator << (Steck& S, float x) { // пушим
    S.s.push_back(x);
}
void operator >> (Steck& S, float x) { // вытаскиваем
    //S.s.pop_back()
    for (size_t i = 0; i < S.s.size(); i++) {
        if (S.s[i] == x) {
            S.s.erase(S.s.begin() + i);
        }

	}
}