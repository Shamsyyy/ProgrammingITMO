#pragma once
#include "math.h"
#include "proga_2.h"
#include "stdio.h"

class Polinom {
public:
	Polinom(float a, float b, float c);
	Polinom();
	Polinom(const Polinom& p);
	void set_vars(float a, float b, float c);
	void print();
	void fx(float x);
	void howmuch();
	void solve();
	void dydx();
private:
	float a, b, c, d, x, f_x;
	int solutions;
	float sol_1, sol_2;
};