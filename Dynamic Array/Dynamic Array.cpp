#include <iostream>
#include <conio.h>
using namespace std;


void arrayDynamic(int);
void addToArray();
void reduceArraySize();

int *dynamicArray = NULL;
int testArraySize = 0;

void main() {
	
	do {
		cout << "1. Array Size"		<< endl
			 << "2. Add to array"	<< endl
			 << "3. Display array"	<< endl
			 << "4. Reduce array" << endl
			 << "5. Exit" << endl
			 << "Choose #: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Array size: ";
			cin >> testArraySize;
			arrayDynamic(testArraySize);
			break;
		case 2:
			system("cls");
			addToArray();
			break;
		case 3:
			system("cls");
			for (int i = 0; i < testArraySize+10; i++) {
				cout << "index " << i << ": " << dynamicArray[i] << endl;
			}
			break;
		case 4:
			reduceArraySize();
			break;
		default:
			break;
		}
		if (choice == 5) {
			break;
		}
	} while (true);

	delete[] dynamicArray;
	dynamicArray = NULL;

}

void arrayDynamic(int arraySize) {

	dynamicArray = new int[arraySize];

	for (int i = 0; i < arraySize; i++) {
		dynamicArray[i] = i;
	}

	for (int i = 0; i < arraySize; i++) {
		cout << "index " << i << ": " << dynamicArray[i] << ", Memory Location: " << &dynamicArray[i] << endl;
	}
	

}

void addToArray() {
	testArraySize++;
	int *tempArray = new int[testArraySize];
	int temp;
	cout << " number to add: ";
	cin >> temp;
	tempArray[testArraySize - 1] = temp;

	for (size_t i = 0; i < testArraySize - 1; i++) {
		tempArray[i] = dynamicArray[i];
	}

	delete[] dynamicArray;
	dynamicArray = tempArray;
}

void reduceArraySize() {
	
	system("cls");
	int newSize;
	do {
		cout << "Reduce to what size: ";
		
		cin >> newSize;
	} while (newSize > testArraySize);

	int *tempArray = new int[newSize];

	if (newSize != 0) {
		for (int i = 0; i < newSize; i++) {
			tempArray[i] = dynamicArray[i];
		}

		delete[] dynamicArray;
		dynamicArray = tempArray;

	}
	else {
		delete[] dynamicArray;
	}
	testArraySize = newSize;

}
