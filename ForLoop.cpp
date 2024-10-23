#include <iostream>

using namespace std;

int main() {
	int sum = 0;
	
	cout << "Here are the numbers 1 - 10." << endl;
	
	for (int i = 1; i <= 10; i++) {
		cout << i << " ";
		sum += i;
	}
	
	cout << endl;
	cout << "The sum is: " << sum << endl;
	
	return 0;
}
