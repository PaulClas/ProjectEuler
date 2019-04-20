/*
File: main.cpp
Author: Paul Clas
Date: 19 avril 2019
Description:
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;


bool isPrime(int num) {
	bool flag = true;
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	auto start = chrono::steady_clock::now();
	vector<long long> primeNumberTable;
	bool numbTrouver = false;
	int i = 2;
	while (numbTrouver == false) {
		if (isPrime(i)) {
			primeNumberTable.push_back(i);
		}
		i++;
		if (primeNumberTable.size() == 10001) {
			numbTrouver = true;
		}
	}
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << primeNumberTable[10000]<< endl;
	cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
	
	/*for (auto it = primeNumberTable.begin(); it != primeNumberTable.end(); ++it) {
		cout << ' ' << *it;
	}*/
	

	system("pause");


	return 0;
}
