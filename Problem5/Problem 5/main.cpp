/*File: main.cpp
Date: 19 avril 2019
Author: Paul Clas
Description: Problem 5: 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?



*/


#include <iostream>
#include <chrono>

using namespace std;

int main() {
	auto start = chrono::steady_clock::now();
	bool estTrouver = false;
	long long i = 1;
	long long numb = 0;
	while (estTrouver != true) {
		for (long long j = 1; j <= 20; j++) {
			if (i%j == 0) {
				estTrouver = true;
			}
			else {
				//cout << "numb " << i << " pas divisible par " << j << endl;
				j = 21;
				estTrouver = false;
			}
		}
		if (estTrouver == true) {
			numb = i;
		}
		else {
			estTrouver = false;
		}
		i++;
	}
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "Smallest number that can be divided by each number from 1 to 20 : " << numb<< endl;
	cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;

	system("pause");

	return 0;
}