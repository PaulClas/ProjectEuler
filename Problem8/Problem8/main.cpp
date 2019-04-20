/*

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

int main() {
	auto start = chrono::steady_clock::now();
	vector <int> table;
	ifstream file;
	int numb;
	
	string line;
	ifstream myfile("input.txt");
	if (myfile.is_open())
	{
		
		while (getline(myfile, line))
		{
			//cout << line << endl;
			for (int i = 0; i < line.size(); i++) {
				numb = line[i]-'0';
				table.push_back(numb);
			}
			//cout << endl;
		}
		myfile.close();
		//cout << endl << endl;
	}
	else cout << "Unable to open file";
	
	/*
	for (auto it = table.begin(); it != table.end(); ++it) {
		cout << *it;
		
	}
	*/
	long long total=1;
	long long mulMax = 0;
	for (int i = 0; i < table.size() - 13; i++) {
		int j = 0;
		while(j<13){
			total *= table[i+j];
			j++;
		}
		//cout << total << endl;
		if (mulMax < total) {
			mulMax = total;
		}
		total = 1;
	}
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "Le plus grand multiple des 13 nombres adjacents de la matrice donné est " << mulMax<< endl;
	cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
	system("pause");


	return 0;
}

