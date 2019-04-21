/*
File: main.cpp
Author: Paul Clas
Date: 20 avril 2019
Description:
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/
#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

int main() {
	auto start = chrono::steady_clock::now();
	int a, b, c;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if ((1000 * i) + (1000 * j) - (i*j) == 500000 && i != 0 && j != 0) {
				if (i > j) {
					b = i;
					a = j;
				}
				else {
					a = i;
					b = j;
				}
				break;
			}
		}
	}
	c = sqrt(pow(a, 2) + pow(b, 2));
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "a: " << a << endl << "b: " << b<< endl << "c: " << c << endl;
	cout << "a+b+c = " << a + b + c << endl;
	cout << "a^2 + b^2 = c^2 -> " << pow(a,2) << " + " << pow(b,2) << " = " << pow(c,2) << endl;
	cout << "abc = " << a*b*c << endl;
	cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
	
	system("pause");


	return 0;
}


