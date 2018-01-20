// Reid_Nolan_HW1_[Right_On].cpp : Defines the entry point for the console application.
// C++ Program that prompts the user to enter the lengths of three sides of a triangle and then outputs a message indicating whether the triangle is a right triangle or not.
//Also determines if triangle is equilateral, isosceles, or scalene.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <utility>
#include <cmath>

using namespace std;

int main()
{
	while(true)
	{		
		const float minValue = 0.1;
		const float epsilon = 0.00001;
		const int arrayLength = 3;
		float sideArray[arrayLength] = { 0 };
		float aSqrd = 0.0;
		float bSqrd = 0.0;
		float cSqrd1 = 0.0;
		float cSqrd2 = 0.0;
		bool goodValueOne = false;
		bool goodValueTwo = false;
		bool goodValueThree = false;
		
		//display program header
		cout << "Reid_Nolan_HW1_[Right_On]" << endl << endl;
		cout << "     This program provides data regarding a triangle" << endl << "      after inputting the length of the three sides." << endl << endl;

		//side one input loop
		while (!goodValueOne)
		{
			cout << "[0 to exit] Enter a value for side one: ";
			cin >> sideArray[0];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(512, '\n');
			}
			//trapdoor for program exit
			else if(sideArray[0] == 0)
			{
				cout << endl << endl << "exiting program...";
				exit(1);
			}
			else
			{
				//no else needed
			}
			while (sideArray[0] >= minValue)
			{
				goodValueOne = true;
				break;
			}
		}

		//side two input loop
		while (!goodValueTwo)
		{
			cout << "Enter a value for side two: ";
			cin >> sideArray[1];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(512, '\n');
			}
			else
			{
				//no else needed
			}
			while (sideArray[1] >= minValue)
			{
				goodValueTwo = true;
				break;
			}
		}

		//side three input loop
		while (!goodValueThree)
		{
			cout << "Enter a value for side three: ";
			cin >> sideArray[2];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(512, '\n');
			}
			else
			{
				//no else needed
			}
			while (sideArray[2] >= minValue)
			{
				goodValueThree = true;
				break;
			}
		}

		//display input values
		cout << endl << "Values entered: ";
		for (int i = 0; i < arrayLength; i++)
		{
			cout << sideArray[i] << " ";
		}

		//selection-sort loop
		for (int startIndex = 0; startIndex < arrayLength; startIndex++)
		{			
			int smallestIndex = startIndex;

			for (int currentIndex = startIndex + 1; currentIndex < arrayLength; currentIndex++)
			{
				if (sideArray[currentIndex] < sideArray[smallestIndex])
				{
					smallestIndex = currentIndex;
				}
				std::swap(sideArray[startIndex], sideArray[smallestIndex]);
			}
		}	

		//store array elemnts into variables for pythagorean theorem calculation
		aSqrd = pow(sideArray[0], 2);
		bSqrd = pow(sideArray[1], 2);
		cSqrd1 = pow(sideArray[2], 2);
		cSqrd2 = aSqrd + bSqrd;
		
		//determination of right triangle
		if (cSqrd1 == cSqrd2)
		{
			cout << endl << "Triangle IS right-angle." << endl;
		}
		else
		{
			cout << endl << "Triangle IS NOT right-angle." << endl;
		}		
		
		//display apparent hypotenuse (largest input value)
		cout << "Based on your input, the hypotenuse appears to be: " << sideArray[2] << endl;

		//calculate actual hypotenuse
		cout  << "Calculated hypotenuse for right-angle triangle: " << sqrt(cSqrd2) << endl;

		//comparison of floating-point hypotenuse values
		if (fabs(cSqrd2 - cSqrd1) <= epsilon * fabs(cSqrd2))
		{
			cout << "Hypotenuse has been verified!" << endl;
		}		
		else
		{
			cout << "Hypotenuse could not be verified!" << endl;
		}

		//bonus check (equilateral, isoscles, or scalene)
		//all sides equal
		if (sideArray[0] == sideArray[1] && sideArray[0] == sideArray[2])
		{
			cout << "Triangle is equilateral." << endl;
		}
		//two sides equal
		else if (sideArray[0] == sideArray[1] || sideArray[0] == sideArray[2] || sideArray[1] == sideArray[2])
		{
			cout << "Triangle is isosceles." << endl;
		}
		//no sides equal
		else if (sideArray[0] != sideArray[1] && sideArray[0] != sideArray[2] && sideArray[1] != sideArray[2])
		{
			cout << "Triangle is scalene." << endl;
		}

		//repeat program
		cout << endl << endl << "Press ENTER to go again...";
		cin.ignore();
		cin.get();
		system("cls");
	}
}
