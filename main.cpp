#include <iostream>
#include <queue>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;


// Misc
int menu();
int keyValidation();

// Streams
void inStream(ifstream& inputFile, queue<int>* subPtr);
void outStream(ofstream& outputFile, queue<int>* subPtr);

// Encryption Process
void transposeQueue(queue<int>* ciphPtr);
void shiftElems(queue<int>* ciphPtr, int key);

// Decryption Process
void deTransposeQueue(queue<int>* subPtr);
void unshiftElems(queue<int>* subPtr, int key);

// Debug Function Prototypes
void printCiphQ(queue<int>* ciphPtr);
void intToChar(queue<int>* ciphPtr);


int main() {


	// QUEUES
	queue<int> subjectQ{};
	queue<int>* subjectPtr = &subjectQ;

	int menuSelect{menu()};
	int key{}; // (1728 / 96) = 18


	// ENCRYPTION ROUTE
	if (menuSelect == 1) {

		// INPUT STREAMS
		ifstream inFile("plaintext.txt", ios::in);
		ofstream outFile("encrypted.txt", ios::out);

		cout << "Encrypting..." << endl;
		inStream(inFile, subjectPtr);
		transposeQueue(subjectPtr);
		shiftElems(subjectPtr, 18);
		outStream(outFile, subjectPtr);
		inFile.close(); outFile.close();
		cout << "Encryption complete. Your encrypted message is located in \"encrypted.txt\"" << endl;

	}

	// DECRYPTION
	else if (menuSelect == 2) {

		//OUTPUT STREAMS
		ifstream decrInputFile("encrypted.txt", ios::in);
		ofstream decrOutputFile("decrypted.txt", ios::out);

		key = keyValidation();
		cout << "Decrypting..." << endl;
		inStream(decrInputFile, subjectPtr);
		deTransposeQueue(subjectPtr);
		unshiftElems(subjectPtr, key);
		outStream(decrOutputFile, subjectPtr);
		decrInputFile.close(); decrOutputFile.close();
		cout << "Decryption complete. Your decrypted message is located in \"decrypted.txt\"" << endl;

	}

	else if (menuSelect == -1) { cerr << "An error occurred somewhere at menu." << endl; }
	return 0;
}


// MENU
int menu() {
	char selection{};
	cout << "Hello! Welcome to my basic Encryptor/Decryptor program!" << endl;
	cout << "Before proceeding, Please ensure the following text files are in the same directory as this executable:" << endl;
	cout << "\"plaintext.txt\"\n\"encrypted.txt\"\n\"decrypted.txt\"" << endl;
	cout << "\n[1] Encryption\n";
	cout << "[2] Decryption\n";
	cout << "[3] Exit\n\n> ";
	while(cin >> selection) {
		if (selection == 49) { return 1; }
		else if (selection == 50) { return 2; }
		else if (selection == 51) { cout << "Thank you for using my program!\n"; exit(0); }
		else {cout << "\n\nPlease enter a valid selection.\n> ";}
	}
	return -1;
}

int keyValidation() {
	cin.ignore();
	string key{};
	cout << "Please enter the key:\n> ";
	getline(cin, key);
	int result{};
	for (char c : key) { result += c; }
	return (result / 96);
}

// STREAMS
void inStream(ifstream& inputFile, queue<int>* subPtr) {
	if (!inputFile) { cerr << "Error: Could not open file." << endl; exit(1); }
	string word{};
	while (!inputFile.eof()) {
		getline(inputFile, word);
		for (char c : word) { int ascii = c; subPtr->push(ascii); }
	}
}

void outStream(ofstream& outFile, queue<int>* subPtr) {
	if (!outFile) { cerr << "File could not be created or opened" << endl; exit(-1); }
	while (!subPtr->empty()) {
		char letter{};
		letter = subPtr->front();
		outFile << letter;
		subPtr->pop();
	}
}


// ENCRYPTION PROCESS
void transposeQueue(queue<int>* ciphPtr) {
	queue<int> transpose1{}; // inserts portion A of queue
	queue<int> transpose2{}; // inserts portion B of queue

	bool switchQ = false;	// gate that dictates A and B portion of the queue
	while (!ciphPtr->empty()) {
		if (!switchQ) {
			transpose1.push(ciphPtr->front());	// portion A
			ciphPtr->pop();
			switchQ = true;
		}
		else {
			transpose2.push(ciphPtr->front());	// portion B
			ciphPtr->pop();
			switchQ = false;
		}
	}

	while (!transpose1.empty()) {	// inserts all of portion A's into the original queue
		ciphPtr->push(transpose1.front());
		transpose1.pop();
	}

	while (!transpose2.empty()) {	// concatenates all of portion B to original queue
		ciphPtr->push(transpose2.front());
		transpose2.pop();
	}
}

void shiftElems(queue<int>* ciphPtr, int key) {
	queue<int> shub{}; //shift-sub queue
	int elem;

	// grabs ascii of queue elements and transforms to different ascii value using key
	while (!ciphPtr->empty()) {
		elem = ciphPtr->front();	// variable to hold ascii element
		elem = ((((elem - 32) + key) * 7) % 95) + 32;	// key serves as shifter, *7 to mix add layer, %95 maintain within the printable ascii conversion, +32 shift back up ascii table values
		shub.push(elem);
		ciphPtr->pop();
	}

	while (!shub.empty()) {
		ciphPtr->push(shub.front());
		shub.pop();
	}
}

// DECRYPTION PROCESS
void deTransposeQueue(queue<int>* subPtr) {
	int ptrSize = subPtr->size();
	bool switchQ = false;
	queue<int> split1 {};
	queue<int> split2 {};

	// Suppose the string is odd numebered:
	// we need ceil of split string on first split
	double splitSize{};
	if (ptrSize % 2 == 1) {splitSize = 1 + (ptrSize / 2); }
	else {splitSize = ptrSize / 2; }

	// insert by split size and then rest of subPtr
	for (int i{}; i < splitSize; i++) {
		split1.push(subPtr->front());
		subPtr->pop();
	}

	// To ensure the subPtr is emptied
	while (!subPtr->empty()) {
		split2.push(subPtr->front());
		subPtr->pop();
	}


	// similar, but reversed of the ENCRYPTION function(s)
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
                elem = ((((elem - 32)* 68) - key) % 95) + 32;
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


void intToChar(queue<int>* ciphPtr) { // Used for initial char to int conversion
	char letter;
	queue<char> temporaryHold;

	while(!ciphPtr->empty()) {
		cout << "Front of ciphPtr: " << ciphPtr->front() << endl;
		letter = ciphPtr->front();
		cout << "Letter conversion: " << letter << endl;
		temporaryHold.push(letter);
		ciphPtr->pop();
	}
	while (!temporaryHold.empty()) {
		ciphPtr->push(temporaryHold.front());
		temporaryHold.pop();
	}
}


