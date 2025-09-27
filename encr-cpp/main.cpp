#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int menu();

// Encryption Process
void extractInput(queue<int>* ciphPtr,string& inp);
void transposeQueue(queue<int>* ciphPtr);
void shifElems(queue<int>* ciphPtr, int key);

// Decryption Process
void deTransposeQueue(queue<int>* subPtr);
//void unshiftElems(queue<int>* subPtr);

// Debug Function Prototypes
void printCiphQ(queue<int>* ciphPtr);
void intToChar(queue<int>* ciphPtr);	// Used for initial char to int conversion


int main() {

	int menuSelect{menu()};
	int key = 12;

	string input = "Hello World";
	string cipherText {"t9<$?129L<9"};

	// Queues
	queue<int> subjectQ{};
	queue<int>* subjectPtr = &subjectQ;


	//for (char c : cipherText) {subjectQ.push(c);}


	// ENCRYPTION ROUTE
	if (menuSelect == 1) {
		cout << "Encryption..." << endl;

		extractInput(subjectPtr, input);
		transposeQueue(subjectPtr);
		shifElems(subjectPtr, key);
		intToChar(subjectPtr);
		//printCiphQ(subjectPtr);
	}

	// DECRYPTION
	else if (menuSelect == 2) {
		cout << "Decryption..." << endl;
		extractInput(subjectPtr, cipherText);
		deTransposeQueue(subjectPtr);
		//printCiphQ(subjectPtr);
		intToChar(subjectPtr);

	}

	else {}
	return 0;
}


// MENU
int menu() {
	int selection{};
	cout << "Hello! Please enter a enter a number for your selection: " << endl;
	cout << "[1] Encryption\n";
	cout << "[2] Decryption\n\n> ";

	cin >> selection;
	if (selection == 1) { return 1; }
	else if (selection == 2) { return 2; }

	else { return 0; }

}


void extractInput(queue<int>* ciphPtr, string& input) {
	int parse{0};
	for (char c : input) {		// implicit conversion of char to its ASCII value
		ciphPtr->push(c);
	}
}


// ENCRYPTION PROCESS
void transposeQueue(queue<int>* ciphPtr) {
	queue<int> transpose1{};
	queue<int> transpose2{};
	queue<int> mix{};

	bool switchQ = false;
	while (!ciphPtr->empty()) {
		if (!switchQ) {
			transpose1.push(ciphPtr->front());
			ciphPtr->pop();
			switchQ = true;
		}
		else {
			transpose2.push(ciphPtr->front());
			ciphPtr->pop();
			switchQ = false;
		}
	}

	while (!transpose1.empty()) {
		ciphPtr->push(transpose1.front());
		transpose1.pop();
	}

	while (!transpose2.empty()) {
		ciphPtr->push(transpose2.front());
		transpose2.pop();
	}
}

void shifElems(queue<int>* ciphPtr, int key) {
	queue<int> shub{};
	int elem;
	while (!ciphPtr->empty()) {
		elem = ciphPtr->front();
		elem = ((elem + key) % 95) + 32;
		shub.push(elem);
		ciphPtr->pop();
	}

	while (!shub.empty()) {
		ciphPtr->push(shub.front());
		shub.pop();
	}
}

// DECRYPTION
void deTransposeQueue(queue<int>* subPtr) {
	int ptrSize = subPtr->size();
	bool switchQ = false;
	queue<int> split1 {};
	queue<int> split2 {};

	queue<int>* s1 = &split1;
	queue<int>* s2 = &split2;

	cout << "ptrSize: " << ptrSize << endl; // size = 11

	// Suppose the string is odd numebered:
	// we need ceil of split string on first split
	double splitSize{};
	if (ptrSize % 2 == 1) {splitSize = 1 + (ptrSize / 2); }
	else {splitSize = ptrSize / 2; }
	cout << "splitSize: " << splitSize << endl;

	// insert by split size and then rest of ptrQ
	for (int i{}; i < splitSize; i++) {
		split1.push(subPtr->front());
		subPtr->pop();
	}

	// To ensure the ptrQ is emptied
	while (!subPtr->empty()) {
		split2.push(subPtr->front());
		subPtr->pop();
	}


	for (int i{0}; i < ptrSize; i++) {
		if (!switchQ) {
			subPtr->push(split1.front());
			split1.pop();
			switchQ = true;
		}
		else {
			subPtr->push(split2.front());
			split2.pop();
			switchQ = false;
		}
	}

	//printCiphQ(subPtr);
	intToChar(subPtr);
/*
	printCiphQ(s1);
	cout << endl;
	printCiphQ(s2);
*/
}


// Debugger Functions

void printCiphQ(queue<int>* ciphPtr) {
	while(!ciphPtr->empty()) {
		cout << ciphPtr->front() << " ";
		ciphPtr->pop();
	}
}


// Used for initial char to int conversion
void intToChar(queue<int>* ciphPtr) {
	char letter;
	while(!ciphPtr->empty()) {
		letter = ciphPtr->front();
		cout << letter;
		//cout << ciphPtr->front();
		ciphPtr->pop();
	}
}
