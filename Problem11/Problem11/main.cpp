/*
File: main.cpp
Author: Paul Clas
Date: 21 avril 2019
Description: In the 20×20 grid below, four numbers along a diagonal line have been marked in red.

08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
*/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>

using namespace std;

int main() {
	auto start = chrono::steady_clock::now();
	//Initial Declerations
	string line;// line frome file
	int table[20][20];//table to store values
	int integer;//used to store converted string to integer
	string str = "";//used to store string from line
	fstream file;//file to open

	//Read File input.txt
	file.open("input.txt");
	if (file.is_open()) {
		int r = 0;
		while (file.eof() != true) {
			getline(file, line);
			//cout << line << endl;
			int c = 0;
			for (int i = 0; i < line.size(); i+=3) {
				int j = 0;
				while (j < 2) {
					str += line[i + j];
					j++;
				}
				integer = stoi(str);
				//cout << integer<<" ";
				table[r][c] = integer;
				c++;
				//cout << str;
				integer = 0;
				str = "";
			}
			r++;
			//cout << endl;
			
		}
		file.close();
	}
	else { cout << "Probleme d'ouverture de fichier" << endl; }

	/////////////////////////////////////////////////////////////////////////////////////////////

	//Print out all values of the table
	/*cout << endl << endl;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	*/

	////////////////////////////////////////////////////////////////////////////////////////////
	//initial Declaration
	long long totalD = 1;
	long long totalG = 1;
	long long totalBas = 1;
	long long totalHaut = 1;
	long long totalDiagGaucheHaut = 1;
	long long totalDiagGaucheBas = 1;
	long long totalDiagDroiteHaut = 1;
	long long totalDiagDroiteBas = 1;
	long long maxDDB = 0;
	long long maxDDH = 0;
	long long maxDGB = 0;
	long long maxDGH = 0;
	long long maxHaut = 0;
	long long maxBas = 0;
	long long maxG = 0;
	long long maxD =0;
	long long maxFinal = 0;
	//Algortihtm to pass throught table
	/*
	NOTE: clearly we can make a better a more clear programm by making if statements imbricked into each other
	For instance, reading to the left and top at the same time gives also the diagonal top left sum. Also we see that
	going by symmetry the max number doesn't change because of the table symetry but this algorithm should work if the table
	is bigger than 4x4 included.
	*/
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			//cout << table[i][j] << " ";
			if (j < 17) {//totalGauche
				int colonne = 0;
				while (colonne < 4) {
					totalD *= table[i][j + colonne];
					colonne++;
				}
				//cout << totalGauche << " ";
				/*if (maxD < totalD) {
					maxD = totalD;
				}*/
				if (maxFinal < totalD) {
					maxFinal = totalD;
				}
				totalD = 1;
				colonne = 0;
			}
			if (j > 2) {//TotalDroite
				int colonne = 0;
				while (colonne < 4) {
					totalG *= table[i][j - colonne];
					colonne++;
				}
				//cout << totalDroite << " ";
				/*if (maxG < totalG) {
					maxG = totalG;
				}*/
				if (maxFinal < totalG) {
					maxFinal = totalG;
				}
				totalG = 1;
				
			}
			if (i < 17) {//TotalBas
				int rang = 0;
				while (rang < 4) {
					totalBas*= table[i + rang][j];
					rang++;
				}
				//cout << totalBas << " ";
				/*if (maxBas < totalBas) {
					maxBas = totalBas;
				}*/
				if (maxFinal < totalBas) {
					maxFinal = totalBas;
				}
				totalBas = 1;
				rang = 0;
			}
			if (i > 2) {//totalHaut
				int rang = 0;
				while (rang < 4) {
					totalHaut *= table[i-rang][j];
					rang++;
				}
				//cout << totalHaut << " ";
				/*if (maxHaut < totalHaut) {
					maxHaut = totalHaut;
				}*/
				if (maxFinal < totalHaut) {
					maxFinal = totalHaut;
				}

				totalHaut = 1;
				rang = 0;

			}
			if(i<17 && j<17){//Total Diag Droite Haut
				int rang = 0;
				int colonne = 0;
				while (colonne < 4 && rang < 4) {
					totalDiagDroiteBas *= table[i + rang][j + colonne];
					rang++;
					colonne++;
				}
				//cout << totalDiagDroiteBas << " ";
				/*if (maxDDB < totalDiagDroiteBas) {
					maxDDB = totalDiagDroiteBas;
				}*/
				if (maxFinal < totalDiagDroiteBas) {
					maxFinal = totalDiagDroiteBas;
				}
				totalDiagDroiteBas = 1;
				rang = 0;
				colonne = 0;
			}
			if (i > 2 && j < 17) {//Total Diag Droite et Haut
				int rang = 0;
				int colonne = 0;
				while (colonne < 4 && rang < 4) {
					totalDiagDroiteHaut *= table[i -rang][j + colonne];
					rang++;
					colonne++;
				}
				//cout << totalDiagDroiteHaut << " ";
				/*if (maxDDH < totalDiagDroiteHaut) {
					maxDDH = totalDiagDroiteHaut;
				}*/
				if (maxFinal < totalDiagDroiteHaut) {
					maxFinal = totalDiagDroiteHaut;
				}
				totalDiagDroiteHaut = 1;
				rang = 0;
				colonne = 0;
			}
			if (i <17 && j >2) {//Total Diag Gauche et bas
				int rang = 0;
				int colonne = 0;
				while (colonne < 4 && rang < 4) {
					totalDiagGaucheBas *= table[i + rang][j - colonne];
					rang++;
					colonne++;
				}
				//cout << totalDiagGaucheBas << " ";
				/*if (maxDGB < totalDiagGaucheBas) {
					maxDGB = totalDiagGaucheBas;
				}*/
				if (maxFinal < totalDiagGaucheBas) {
					maxFinal = totalDiagGaucheBas;
				}
				totalDiagGaucheBas = 1;
				rang = 0;
				colonne = 0;
			}
			if (i >2 && j >2) {//Total Diag gauche et haut
				int rang = 0;
				int colonne = 0;
				while (colonne < 4 && rang < 4) {
					totalDiagGaucheHaut *= table[i - rang][j - colonne];
					rang++;
					colonne++;
				}
				//cout << totalDiagGaucheHaut << " ";
				/*if (maxDGH < totalDiagGaucheHaut) {
					maxDGH = totalDiagGaucheHaut;
				}*/
				if (maxFinal < totalDiagGaucheHaut) {
					maxFinal = totalDiagGaucheHaut;
				}
				totalDiagGaucheHaut = 1;
				rang = 0;
				colonne = 0;
			}
		}
		//cout << endl;
	}
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	/*cout << "MaxGauche: " << maxD << endl;
	cout << "MaxDroite: " << maxG << endl;
	cout << "MaxBas: " << maxBas << endl;
	cout << "MaxHaut: " << maxHaut << endl;
	cout << "MaxDDB: " << maxDDB << endl;
	cout << "MaxDDH: " << maxDDH << endl;
	cout << "MaxDGH: " << maxDGH << endl;
	cout << "MaxDGB: " << maxDGB << endl;

	*/
	cout << "//////////////////////////////////////////////////" << endl;
	cout << "MaxFinal: " << maxFinal << endl;
	cout << "//////////////////////////////////////////////////" << endl;
	cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;

	
	/*
	vector <long long> sum;
	sum.push_back(maxD);
	sum.push_back(maxG);
	sum.push_back(maxBas);
	sum.push_back(maxHaut);
	sum.push_back(maxDDB);
	sum.push_back(maxDDH);
	sum.push_back(maxDGH);
	sum.push_back(maxDGB);
	long long final;
	for (auto it = sum.begin(); it != sum.end(); it++) {
		if()
	}*/




	system("pause");
	

	return 0;
}