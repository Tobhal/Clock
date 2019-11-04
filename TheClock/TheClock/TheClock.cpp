﻿// TheClock.cpp : Defines the entry point for the console application.
//
/*
Block clock

How the board is going to look:

Hours			Minutes
_________   |   ___________
@ | @ @ @		@ @ | @ @ @
@ | @ @ @		@ @ | @ @ @
@ | @ @ @		@ @ | @ @ @

The 3X3 grid in hours and minutes is the 1-9 in the back part of the number
The 1X3 (in houres) and 2X3 (in minutes) is the front part of the number

The grids light up randomly.
*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <chrono>
#include <Windows.h>

using namespace std;
using namespace std::chrono;

//Just to end while loops
int done = 0;

int arrayPlaceH;
int arrayPlaceL;

//How many times it wil add lights to the array for the coresponding houres or minutes
int printAmount;

//Stores the houres in its correct int.
int hourHoal;
int hourFront;
int hourBack;

//Stores the minutes in its correct int.
int minutesHoal;
int minutesFront;
int minutesBack;

//test
int stop = 0;

//Define the light array (F = Front | B = Back | A = Array	| H = Height | L = Lenght)
const int hoursFAH = 3;
const int hoursFAL = 1;

const int hoursBAH = 3;
const int hoursBAL = 3;

const int minutesFAH = 3;
const int minutesFAL = 2;

const int minutesBAH = 3;
const int minutesBAL = 3;

//Sets the board with multiple array ( [height] | [lenght] ) (F = Front | B = Back)
int hoursFA[hoursFAH][hoursFAL] = {
	{ 0 },
	{ 0 },
	{ 0 }
};

int hoursBA[hoursBAH][hoursBAL] = {
	{ 0,0,0 },
	{ 0,0,0 },
	{ 0,0,0 }
};

int minutesFA[minutesFAH][minutesFAL] = {
	{ 0,0 },
	{ 0,0 },
	{ 0,0 }
};

int minutesBA[minutesBAH][minutesBAL] = {
	{ 0,0,0 },
	{ 0,0,0 },
	{ 0,0,0 }
};

void settClock() {

	cout << "Hours" << endl;

	//prints hoursF to consol 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			cout << hoursFA[i][j];
		}
		cout << endl;
	}

	cout << endl;

	//prints hoursB to consol
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << hoursBA[i][j];
		}
		cout << endl;
	}

	cout << endl << endl << "Minutes" << endl;

	//prints minutesF to consol 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << minutesFA[i][j];
		}
		cout << endl;
	}

	cout << endl;

	//prints minutesB to consol
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			cout << minutesBA[x][y];
		}
		cout << endl;
	}

}

//Setts up the variables for so the code knows what time is is
void timeNow() {

	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	hourHoal = newtime.tm_hour;
	hourBack = (hourHoal / 1) % 10;
	hourFront = (hourHoal / 10) % 10;

	minutesHoal = newtime.tm_min;
	minutesBack = (minutesHoal / 1) % 10;
	minutesFront = (minutesHoal / 10) % 10;

}

void updateClock() {

	timeNow();

	arrayPlaceH = 0;
	arrayPlaceL = 0;
	printAmount = 0;

	//Edit hoursF
	while (true)
	{
		
		if (arrayPlaceH == hoursFAH) 
		{
			break;
		}
		else if (printAmount == hourFront) {
			break;
		}

		++hoursFA[arrayPlaceH][arrayPlaceL];

		++arrayPlaceL;

		if (arrayPlaceL >= hoursFAL)
		{
			++arrayPlaceH;
			arrayPlaceL = 0;
		} 

		++printAmount;
	}

	//----------------------------------------

	arrayPlaceH = 0;
	arrayPlaceL = 0;
	printAmount = 0;

	//Edit hoursB
	while (true)
	{

		if (arrayPlaceH == hoursBAH)
		{
			break;
		}
		else if (printAmount == hourBack) {
			break;
		}

		++hoursBA[arrayPlaceH][arrayPlaceL];

		++arrayPlaceL;

		if (arrayPlaceL >= hoursBAL)
		{
			++arrayPlaceH;
			arrayPlaceL = 0;
		}

		++printAmount;
	}

	//----------------------------------------
	//----------------------------------------

	arrayPlaceH = 0;
	arrayPlaceL = 0;
	printAmount = 0;

	//Edit minutesF
	while (true)
	{

		if (arrayPlaceH == minutesFAH)
		{
			break;
		}
		else if (printAmount == minutesFront) {
			break;
		}

		++minutesFA[arrayPlaceH][arrayPlaceL];

		++arrayPlaceL;

		if (arrayPlaceL >= minutesFAL)
		{
			++arrayPlaceH;
			arrayPlaceL = 0;
		}

		++printAmount;
	}

	//----------------------------------------

	arrayPlaceH = 0;
	arrayPlaceL = 0;
	printAmount = 0;

	//Edit minutesF
	while (true)
	{

		if (arrayPlaceH == minutesBAH)
		{
			break;
		}
		else if (printAmount == minutesBack) {
			break;
		}

		++minutesBA[arrayPlaceH][arrayPlaceL];

		++arrayPlaceL;

		if (arrayPlaceL >= minutesBAL)
		{
			++arrayPlaceH;
			arrayPlaceL = 0;
		}

		++printAmount;
	}

}

void randomNumber() {



}

int main()
{

	updateClock();


	while (stop < 3)
	{

		updateClock();

		settClock();

		//Sleep(600);

		Sleep(60000);

		++stop;

	}

	cout << endl << "Code done!" << endl;
	cout << "Press enter to exit" << endl;
	getchar();
    return 0;
}
