#include <iostream>
#include "proga_3.h"

int main() {
    //#3
	Triangle t1(make_pair(0, 0), make_pair(0, 5), make_pair(3, 0));
	Triangle t2(make_pair(1, 1), make_pair(2, 5), make_pair(3, 4));
	pair <float, float> vec(1, 2);
	t1.print();
	t1 = t1 + vec;
	t1.print();
	t2.print();
	cout << (t1 == t2) << endl;
	cout << (t1 > t2) << endl;
	cout << (t1 < t2) << endl;
	vector <float> v = { 1, 3, 5 };
	Steck S1(v);
    //#5	Steck S1;
	S1.print();
	S1 << 2.0;
	S1.print();
	S1 >> 5.0;
	S1.print();
	return 0;
}