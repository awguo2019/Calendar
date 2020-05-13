// Calendar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
using namespace std;

void SetColor(int value){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

int dayNumber(int m, int d, int y);

void display(int m, int d, int h);

int leapyear(int year);

void getinfo(int m, int d, int y);


int main()
{
	int ans1;

	
	int y;
	int d;
	int m;
	char ans;
	int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int dayone;
	int holliday[12] = { 1, 14, 17, 1, 5, 14, 4, 24, 0, 31, 21, 25 };
	
	int labday;
	

	int thanksday;
	



	do{

		cout << "Which format? (1=separate numbers, 2=mm/dd/yyyy) ";
		cin >> ans1;

		cout << "Enter month day year: ";
		if (ans1 == 1){
			cin >> m >> d >> y;
		}
		else{
			scanf_s("%d/%d/%d", &m, &d, &y);
		}

		


		mdays[1] += leapyear(y);

		dayone = dayNumber(m, 1, y);

		labday = dayNumber(9, 1, y);

		holliday[8] = 0;
		if (labday == 7){
			labday = 0;
		}
		if (labday < 2){
			for (int i = labday; i <= 2; i++){
				holliday[8]++;
			}
		}
		if (labday > 2){
			for (int i = labday; i <= 9; i++){
				holliday[8]++;
			}
		}
		if (labday == 2){
			holliday[8] = 1;
		}



		thanksday = dayNumber(11, 22, y);
		holliday[10] = 21;
		if (thanksday == 7){
			thanksday = 0;
		}

		if (thanksday < 5){
			for (int i = thanksday; i <= 5; i++){
				holliday[10]++;
			}
		}
		if (thanksday > 5){
			for (int i = thanksday; i <= 12; i++){
				holliday[10]++;
			}
		}
		if (thanksday == 5){
			holliday[10] = 22;
		}

		cout << endl;


		getinfo(m, dayone, y);
		
		m = m - 1;


		
		display(mdays[m], dayone, holliday[m]);

		
		switch (m + 1) {

		case 1: cout << "***New Year's Day " << y << endl;
			break;
		case 2: cout << "***Valentine's Day " << y << endl;
			break;
		case 3: cout << "***St. Patricks Day " << y << endl;
			break;
		case 4: cout << "***April Fool's " << y << endl;
			break;
		case 5: cout << "***Cinco de Mayo " << y << endl;
			break;
		case 6: cout << "***Flag Day " << y << endl;
			break;
		case 7: cout << "***Independence Day " << y << endl;
			break;
		case 8: cout << "***Anniversary of Mt. Vesuvius Eruption " << y << endl;
			break;
		case 9: cout << "***Labor Day " << y << endl;
			break;
		case 10: cout << "***Halloween " << y << endl;
			break;
		case 11: cout << "***Thanksgiving " << y << endl;
			break;
		case 12: cout << "***Christmas " << y << endl;
			break;
		}

		cout << setfill(' ')<<""<<endl;



		cout << "continue? ";
		cin >> ans;

	} while (ans == 'y' | ans == 'Y');

	return 0;
}

int dayNumber(int m, int d, int y) {
	if (m == 1 || m == 2) {
		m = m + 12;
		y = y - 1;
	}
	return (d + (int)floor((13 * (m + 1)) / 5) + y % 100 + (int)floor((y % 100) / 4) + (int)floor(((int)floor(y / 100)) / 4) + 5 * (int)floor(y / 100)) % 7;
}

int leapyear(int year){
	int leapyear;
	if (year % 4 == 0){
		leapyear = 1;
	}
	if (year % 100 == 0){
		leapyear = 0;
	}
	if (year % 400 == 0){
		leapyear = 1;

		
	}
	return leapyear;
}

void getinfo(int m, int d, int y){
	cout << setiosflags(ios::right);
	switch (m) {

	case 1: cout << setw(27) << "January " << y << endl;
		break;
	case 2: cout << setw(27) << "Feburary " << y << endl;
		break;
	case 3: cout << setw(27) << "March " << y << endl;
		break;
	case 4: cout << setw(27) << "April " << y << endl;
		break;
	case 5: cout << setw(27) << "May " << y << endl;
		break;
	case 6: cout << setw(27) << "June " << y << endl;
		break;
	case 7: cout << setw(27) << "July " << y << endl;
		break;
	case 8: cout << setw(27) << "August " << y << endl;
		break;
	case 9: cout << setw(27) << "September " << y << endl;
		break;
	case 10: cout << setw(27) << "October " << y << endl;
		break;
	case 11: cout << setw(27) << "November " << y << endl;
		break;
	case 12: cout << setw(27) << "December " << y << endl;
		break;

	}
	cout << setfill('~') << setw(50) << "" << endl;

	cout << resetiosflags(ios::right);
	cout << "|  Su  |  Mo  |  Tu  |  We  |  Th  |  Fr  |  Sa  |" << endl;
	cout << setfill('-') << setw(50) << "" << endl;

	if (d == 0){
		for (int i = 0; i < (d - 1 + 7); i++){
			cout << "|      ";
		}
	}
	else{
		for (int i = 0; i < (d - 1); i++){
			cout << "|      ";
		}
	}
	cout << "|";


	
}



void display(int m, int d, int h){
	for (int i = 0; i < m; i++){
		if (d == 0){
			if (i == (h - 1)){
				cout << setfill('*') << setw(6) << (i + 1);
				cout << "|" << endl;
			}
			else{

				cout << setfill(' ') << setw(6) << (i + 1) << "|" << endl;

			}

			cout << setfill('-') << setw(50) << "" << endl << "|";
			d = (d + 1) % 7;
		}
		else{

			if (i == (h - 1)){
				cout << setfill('*') << setw(6) << (i + 1) << "|";
			}
			else{

				cout << setfill(' ') << setw(6) << (i + 1) << "|";

			}
			d = (d + 1) % 7;
		}

	}
	for (int i = 0; i < ((7 - d) % 7); i++){
		cout << "      |";

	}
	cout << "      |" << endl;
	cout << setfill('-') << setw(50) << "" << endl;

}