/*
File: main.cpp
Author: Paul Clas
Date: 20 avril 2019
Descrition:
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.

*/

#include <iostream>
#include <chrono>

using namespace std;

bool isPrime(int n) {
	bool flag = true;
	for (int i = 2; i <= n / 2; i++) {
		if (n%i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	auto start = chrono::steady_clock::now();
	long long total =0;
	long long n = 2;
	const int DEFAULT_CAPACITY = 2000000;
	
	while (n<DEFAULT_CAPACITY){
		if (isPrime(n)) {
			cout << n<< " ";
			total += n;
		}
		n++;
	}
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << total<< endl;
	cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;


	system("pause");
	return 0;
}