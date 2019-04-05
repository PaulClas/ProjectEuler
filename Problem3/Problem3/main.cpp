/*
File: main.cpp
Date: 5 avril 2019
Author: Paul Clas
Description:
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/


#include <iostream>
#include <cmath>

using namespace std;

// A function to print all prime factors of a given number n 
double primeFactors(double n)
{
	double highestNumber = 0;
	// Print the number of 2s that divide n 
	while (fmod(n,2) == 0)
	{
		printf("%d ", 2);
		cout << n;
		n = n / 2;
	}

	// n must be odd at this point.  So we can skip  
	// one element (Note i = i +2) 
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		// While i divides n, print i and divide n 
		if (fmod(n,i) == 0)
		{
			printf("%d ", i);
			highestNumber = i;
			n = n / i;
		}
	}

	// This condition is to handle the case when n  
	// is a prime number greater than 2 
	if (n > 2 && n!=0) {
		highestNumber = n;
		cout << "" << highestNumber;
	}

	cout << endl << "The biggest prime factor of this sequence is ";

	return highestNumber;
}


int main() {
	double upperBorder;
	cout << "Entrer le nombre pour lequel vous desirez savoir le plus grand" << endl;
	cin >> upperBorder;
	cout << "The prime factors of " << upperBorder << " are ";
	cout << primeFactors(upperBorder);
	system("Pause");
	return 0;

}