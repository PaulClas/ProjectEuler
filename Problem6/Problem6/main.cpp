/*
File: main.cpp
Author: Paul Clas
Date: 19 avril 2019
Description: The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

int main() {
	auto start = chrono::steady_clock::now();
	const int DEFAULT_SIZE = 100;


	long double sum = 0;// sum of all i squared
	long double sum2 = 0;// sum of all i up to DEFAULT_SIZE and the squares it
	long double sumFinal = 0;
	long long dif = 0;
	for (int i = 0; i<= DEFAULT_SIZE; i++) {
		sum += pow(i,2);
		sum2 += i;
	}
	sumFinal = pow(sum2,2);
	dif = sumFinal-sum;
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "La dif entre " << sumFinal << " et " << sum << " est " << dif << endl;
	cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;

	system("Pause");
	return 0;
}