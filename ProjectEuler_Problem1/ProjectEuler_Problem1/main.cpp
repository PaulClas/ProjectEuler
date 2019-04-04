/*
File: main.cpp
Project Euler: Problem 1
Date: 4 avril 2019
Author: Paul Clas
Description:
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
Return sum
*/
#include <iostream>
#include <conio.h>

using namespace std;

const int THREE = 3;
const int FIVE = 5;

// returns true if multiple of 3
bool multipleOf3(int n){
	if (n%THREE==0) {
		return true;
	}
	else {
		return false;
	}
}

// returns true if multiple of 5
bool multipleOf5(int n){
	if (n%FIVE==0) {
		return true;
	}
	else {
		return false;
	}
}
// returns sum of multiples of 3 and 5
int sumMultiples(int upperBorder) {
	int sum = 0;
	for (int i = 0; i < upperBorder; i++) {
		if (multipleOf5(i) || multipleOf3(i)) {
			sum += i;
			//cout << i; // Returns the mutiples of 3 and 5
		}

	}
	return sum;

}

int main() {
	int upperBorder;

	cout << "Enter the upper border number to calculate the sum of all the multiples of 3 or 5 below it:" << endl;
	cin >> upperBorder;
	cout << "The sum of all multiples between 3 or 5 below " << upperBorder << " is " << sumMultiples(upperBorder);

	_getch();
	return 0;
}