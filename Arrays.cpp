#include <iostream>
#include <string>
using namespace std;

int main() {
    
	int intArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	string stringArray[] = {"Sword", "Shield", "Wand", "Potion", "Scroll"};

	int intArraySize = sizeof(intArray) / sizeof(intArray[0]);
	int floatArraySize = sizeof(floatArray) / sizeof(floatArray[0]);
	int stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);
	
	int n;
	cout << "Enter a number between 1 and 10: ";
	cin >> n;

	if (n < 1 || n > 10) {
		cout << "Invalid input. Please enter a number between 1 and 10." << endl;
		return 1;
	}

	string suffix;
	if (n == 1) suffix = "st";
	else if (n == 2) suffix = "nd";
	else if (n == 3) suffix = "rd";
	else suffix = "th";

	cout << "Every " << n << suffix << " item in the integer array: ";
	for (int i = 0; i < intArraySize; i += n) {
		cout << intArray[i];
		if (i + n < intArraySize) cout << ", ";
	}
	cout << endl;

	cout << "Every " << n << suffix << " item in the float array: ";
	for (int i = 0; i < floatArraySize; i += n) {
		cout << floatArray[i];
		if (i + n < floatArraySize) cout << ", ";
	}
	cout << endl;

	cout << "Every " << n << suffix << " item in the string array: ";
	for (int i = 0; i < stringArraySize; i += n) {
		cout << stringArray[i];
		if (i + n < stringArraySize) cout << ", ";
	}
	cout << endl;

	return 0;
}

