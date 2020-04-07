#pragma once
#include <utility>
#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std;
class Triangle {
public:
	Triangle(std::pair<float, float> a, std::pair<float, float> b, std::pair<float, float> c);
	void print();
	friend bool operator == (Triangle t1, Triangle t2);
	friend bool operator != (Triangle t1, Triangle t2);
	friend bool operator < (Triangle t1, Triangle t2);
	friend bool operator > (Triangle t1, Triangle t2);
	friend Triangle operator + (Triangle t1, std::pair<float, float> v);
private:
	std::pair <float, float> A;
	std::pair <float, float> B;
	std::pair <float, float> C;
	double AB, BC, AC;
	double p, S;
};

class Steck {
public:
	Steck(vector <float> _s);
	Steck();
	void print();
	friend void operator << (Steck& S, float x);
	friend void operator >> (Steck& S, float x);
private:
	vector <float> s;
};