/*
File: main.cpp
Date: 16 april 2019
Author: Paul Clas
Descripion:
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <locale>
#include <sstream>
#include <string> 

using namespace std;

int main() {

	cout << "Hi" << endl;

	int mul1, mul2;
	int test = 0;
	int compteur = 0;
	string s;
	int final;
	int plusGrandPalindrome =0;
	//bool estPalindrome = false;
	bool successif = false;
	for (int i = 999; i > 900; i--) {
		for (int j = 999; j > 900; j--) {
			test = i*j;
			cout << test;
			s = static_cast<ostringstream*>(&(ostringstream() << test))->str();
			final = s.length();
			//cout << s.length();
			int l = 0;
			if (final % 2 == 0) {
				//cout << final << endl;
				//cout << "nombre pair";
				while (l <= final - 1) {
					cout << s[l] << endl;
					cout << s[final - 1] << endl;
					if (s[l] == s[final - 1]) {
						//cout << s << endl;
						successif = true;
						l++;
						final--;
					}
					else {
						successif = false;
						break;
					}
				}
			}
			else {
				while (l < final / 2) {
					if (s[l] == s[final - 1]) {
						//cout << s << endl;
						successif = true;
						l++;
						final--;
					}
					else {
						successif = false;
						break;
					}
				}

			}
			if (successif == true) {
				if (plusGrandPalindrome < test) {
					plusGrandPalindrome = test;
					mul1 = i;
					mul2 = j;
				}

				
			}
			else {
				cout << test << " n'est pas un palyndrome." << endl;
			}
		}
	}
	
	cout << "Le plus grand Palindrome est " << plusGrandPalindrome << " = "<< mul1 << "*"<< mul2<<" ." << endl;

	

	system("pause");

	return 0;
}