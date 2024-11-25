#include <iostream>
#include <cmath>
using namespace std;

int sumTwoNumbers(int a, int b) {
	return a + b;
}

int productTwoNumbers(int a, int b) {
	return a * b;
}

void circleProperties(double radius, double &circumference, double &area) {
	circumference = 2 * M_PI * radius;
	area = M_PI * radius * radius;
}

int maximumOfThree(int a, int b, int c) {
	return max(a, max(b, c));	
}

int minimumOfThree(int a, int b, int c) {
	return min(a, min(b, c));
}

string isEvenOrOdd(int number) {
	return (number % 2 == 0) ? "Even" : "Odd";
}

bool isEligibleToVote(int age) {
	return age >= 18;
}

int main() {
	int a, b;
	cout << "Enter two numbers to find their sum: ";
	cin >> a >> b;
	cout << "Sum: " << sumTwoNumbers(a, b) << endl;
	
	cout << "Enter two numbers to find their product: ";
	cin >> a >> b;
	cout << "Product: " << productTwoNumbers(a, b) << endl;
	
	double radius, circumference, area;
	cout << "Enter the radius of the circle: ";
	cin >> radius;
	circleProperties(radius, circumference, area);
	cout << "Circumference: " << circumference << ", Area: " << area << endl;
	
	int x, y, z;
	cout << "Enter three numbers to find the maximum and minimum: ";
	cin >> x >> y >> z;
	cout << "Maximum: " << maximumOfThree(x, y, z) << endl;
	cout << "Minimum: " << minimumOfThree(x, y, z) << endl;
	
	int number;
	cout << "Enter a number to check if it is even or odd: ";
	cin >> number;
	cout << "The number is " << isEvenOrOdd(number) << endl;
	
	int age;
	cout << "Enter your age to check voting eligibility: ";
	cin >> age;
	if (isEligibleToVote(age)) {
		cout << "You are eligible to vote." << endl;
	} else {
		cout << "You are not eligible to vote." << endl;
	}
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
