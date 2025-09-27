#include <iostream>
#include <queue>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;


// Misc
int menu();
void extractInput(queue<int>* ciphPtr,string& inp);
void checklist();

// Streams
void inStream(ifstream& inputFile, queue<int>* subPtr);

// Encryption Process
void transposeQueue(queue<int>* ciphPtr);
int shiftElems(queue<int>* ciphPtr, int key);

// Decryption Process
void deTransposeQueue(queue<int>* subPtr);
void unshiftElems(queue<int>* subPtr, int key);

// Debug Function Prototypes
void printCiphQ(queue<int>* ciphPtr);
void intToChar(queue<int>* ciphPtr);


int main() {
	ifstream inFile("plaintext.txt", ios::in);

	int menuSelect{menu()};
	int key = 4;

	string input{};
	string cipherText {"Lps[vhip$sp"};

	// Queues
	queue<int> subjectQ{};
	queue<int>* subjectPtr = &subjectQ;


	// ENCRYPTION ROUTE
	if (menuSelect == 1) {
		cout << "Encryption..." << endl;

		inStream(inFile, subjectPtr);
		//extractInput(subjectPtr, input);
		//transposeQueue(subjectPtr);
		//shiftElems(subjectPtr, key);
		//intToChar(subjectPtr);
	}

	// DECRYPTION
	else if (menuSelect == 2) {
		cout << "Decryption..." << endl;
		extractInput(subjectPtr, cipherText);
		deTransposeQueue(subjectPtr);
		unshiftElems(subjectPtr, key);
		intToChar(subjectPtr);

	}

	else {}
	return 0;
}


// MENU
int menu() {
	char selection{};
	cout << "Hello! Welcome to my basic Encryptor/Decryptor program!" << endl;
	cout << "Before proceeding, Please ensure there is a text file within the same directory "
			"as this executable." << endl;
	cout << "The title of the text file should be name \"plaintext.txt\"" << endl;
	cout << "\n[1] Encryption\n";
	cout << "[2] Decryption\n";
	cout << "[3] Exit\n\n> ";
	while(cin >> selection) {
		if (selection == 49) { return 1; }
		else if (selection == 50) { return 2; }
		else if (selection == 51) { cout << "Thank you for using my program!\n"; exit(0); }
		else {cout << "\n\nPlease enter a valid selection.\n> ";}
	}
	return 0;
}


void extractInput(queue<int>* ciphPtr, string& input) {
	int parse{0};
	for (char c : input) {		// implicit conversion of char to its ASCII value
		ciphPtr->push(c);
	}
}

void inStream(ifstream& inputFile, queue<int>* subPtr) {
	if (!inputFile) { cerr << "Error: Could not open file." << endl; exit(1); }
	string inputText{};
	while (!inputFile.eof()) {getline(inputFile, inputText);}
	cout << inputText << endl;
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

int shiftElems(queue<int>* ciphPtr, int key) {
	queue<int> shub{};
	int elem;
	while (!ciphPtr->empty()) {
		elem = ciphPtr->front();
		elem = ((elem - 32) + key % 95) + 32;
		shub.push(elem);
		ciphPtr->pop();
	}

	while (!shub.empty()) {
		ciphPtr->push(shub.front());
		shub.pop();
	}

	return 1;
}

// DECRYPTION
void deTransposeQueue(queue<int>* subPtr) {
	int ptrSize = subPtr->size();
	bool switchQ = false;
	queue<int> split1 {};
	queue<int> split2 {};

	queue<int>* s1 = &split1;
	queue<int>* s2 = &split2;

	// Suppose the string is odd numebered:
	// we need ceil of split string on first split
	double splitSize{};
	if (ptrSize % 2 == 1) {splitSize = 1 + (ptrSize / 2); }
	else {splitSize = ptrSize / 2; }

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
}


void unshiftElems(queue<int>* subPtr, int key) {

	queue<int> shub{};
        int elem;
        while (!subPtr->empty()) {
                elem = subPtr->front();
                elem = ((elem - 32 - key) % 95) + 32;
                shub.push(elem);
                subPtr->pop();
        }

        while (!shub.empty()) {
                subPtr->push(shub.front());
                shub.pop();
        }
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
