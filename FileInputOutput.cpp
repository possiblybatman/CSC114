#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

const int SQ_FT_PER_GALLON = 110;
const int HOURS_PER_GALLON = 8;
const double LABOR_COST_PER_HOUR = 25.00;

void createInputFile();
void readInputFromFile(string fileName, int &rooms, double &paintPrice, vector<double> &roomSizes);
void calculateEstimate(int rooms, double paintPrice, const vector<double> &roomSizes, 
			double &gallonsRequired, double &hoursRequired, 
			double &paintCost, double &laborCost, double &totalCost);
void displayEstimate(double gallonsRequired, double hoursRequired, double paintCost, double laborCost, double totalCost);
void saveEstimateToFile(string fileName, double gallonsRequired, double hoursRequired, double paintCost, double laborCost, double totalCost);

int main() {
	char createFile;
	cout << "Would you like to create a new input file? (Y/N): ";
	cin >> createFile;

	if (tolower(createFile) == 'y') {
		createInputFile();
	}

	string inputFileName;
	cout << "Enter the input file name: ";
	cin >> inputFileName;

	int rooms;
	double paintPrice;
	vector<double> roomSizes;

	readInputFromFile(inputFileName, rooms, paintPrice, roomSizes);

	double gallonsRequired, hoursRequired, paintCost, laborCost, totalCost;
	calculateEstimate(rooms, paintPrice, roomSizes, gallonsRequired, hoursRequired, paintCost, laborCost, totalCost);

	displayEstimate(gallonsRequired, hoursRequired, paintCost, laborCost, totalCost);

	char saveToFile;
	cout << "Would you like to save the estimate to a file? (Y/N): ";
	cin >> saveToFile;

	if (tolower(saveToFile) == 'y') {
		string outputFileName;
		cout << "Enter the output file name: ";
		cin >> outputFileName;
		saveEstimateToFile(outputFileName, gallonsRequired, hoursRequired, paintCost, laborCost, totalCost);
		cout << "Estimate saved to " << outputFileName << endl;
	}

	return 0;
}

void createInputFile() {
	string fileName;
	cout << "Enter the name of the file to create: ";
	cin >> fileName;

	ofstream outFile(fileName);
	if (!outFile) {
		cerr << "Error creating file." << endl;
		return;
	}

	int rooms;
	double paintPrice;
	cout << "Enter the number of rooms: ";
	cin >> rooms;
	cout << "Enter the price of the paint per gallon: ";
	cin >> paintPrice;

	outFile << rooms << endl;
	outFile << paintPrice << endl;

	for (int i = 0; i < rooms; ++i) {
		double roomSize;
		cout << "Enter the wall space (in square feet) for room " << (i + 1) << ": ";
		cin >> roomSize;
		outFile << roomSize << endl;
	}

	outFile.close();
	cout << "Input file created successfully." << endl;
}

void readInputFromFile(string fileName, int &rooms, double &paintPrice, vector<double> &roomSizes) {
	ifstream inFile(fileName);
	if (!inFile) {
		cerr << "Error: Could not open file " << fileName << endl;
		exit(1);
    }

	inFile >> rooms >> paintPrice;
	roomSizes.resize(rooms);

	for (int i = 0; i < rooms; ++i) {
		inFile >> roomSizes[i];
	}

	inFile.close();
}

void calculateEstimate(int rooms, double paintPrice, const vector<double> &roomSizes, 
			double &gallonsRequired, double &hoursRequired, 
			double &paintCost, double &laborCost, double &totalCost) {
	double totalWallSpace = 0;

	for (double size : roomSizes) {
		totalWallSpace += size;
	}

	gallonsRequired = totalWallSpace / SQ_FT_PER_GALLON;
	hoursRequired = gallonsRequired * HOURS_PER_GALLON;
	paintCost = gallonsRequired * paintPrice;
	laborCost = hoursRequired * LABOR_COST_PER_HOUR;
	totalCost = paintCost + laborCost;
}

void displayEstimate(double gallonsRequired, double hoursRequired, double paintCost, double laborCost, double totalCost) {
	cout << fixed << setprecision(2);
	cout << "Paint Job Estimate:" << endl;
	cout << "Gallons of paint required: " << gallonsRequired << endl;
	cout << "Hours of labor required: " << hoursRequired << endl;
	cout << "Cost of paint: $" << paintCost << endl;
	cout << "Labor charges: $" << laborCost << endl;
	cout << "Total cost: $" << totalCost << endl;
}

void saveEstimateToFile(string fileName, double gallonsRequired, double hoursRequired, double paintCost, double laborCost, double totalCost) {
	ofstream outFile(fileName);
	if (!outFile) {
		cerr << "Error: Could not open file " << fileName << endl;
		return;
	}

	outFile << fixed << setprecision(2);
	outFile << "Paint Job Estimate:" << endl;
	outFile << "Gallons of paint required: " << gallonsRequired << endl;
	outFile << "Hours of labor required: " << hoursRequired << endl;
	outFile << "Cost of paint: $" << paintCost << endl;
	outFile << "Labor charges: $" << laborCost << endl;
	outFile << "Total cost: $" << totalCost << endl;

	outFile.close();
}

