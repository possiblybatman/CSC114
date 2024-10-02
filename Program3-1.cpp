// This program asks for the length and width of a rectangle to find the area
#include <iostream>
using namespace std;

int main()
{
	int length, width, area;
	
	cout << "This program calculates the area of a rectanlge.\n";
	cout << "What is the length of the rectangle? ";
	cin >> length;
	cout << "What is the width of the rectangle? ";
	cin >> width;
	area = length * width;
	cout << "The area of the rectangle is " << area << ".\n";
	return 0;
}
