#include <iostream>
#include <queue>

using namespace std;

void extractInput(queue<int>* ciphPtr,string& inp);
void transposeQueue(queue<int>* ciphPtr);

// Debug Function Prototypes
void printCiphQ(queue<int>* ciphPtr);
void intToChar(queue<int>* ciphPtr);	// Used for initial char to int conversion


int main() {
	string input = "Hello World!";
	queue<int> cipherQ{};
	queue<int>* cipherPtr = &cipherQ;

	extractInput(cipherPtr, input);
	transposeQueue(cipherPtr);

	//decipher(cipherPtr);
	cout << endl;
	return 0;


}

void extractInput(queue<int>* ciphPtr, string& input) {
	int parse{0};
	for (char c : input) {		// implicit conversion of char to its ASCII value
		ciphPtr->push(c);
	}
}

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


// Debugger Functions

void printCiphQ(queue<int>* ciphPtr) {
	while(!ciphPtr->empty()) {
		cout << ciphPtr->front() << " ";
		ciphPtr->pop();
	}
}


// Used for initial char to int conversion
void decipherintToChar(queue<int>* ciphPtr) {
	char letter;
	while(!ciphPtr->empty()) {
		letter = ciphPtr->front();
		cout << letter;
		//cout << ciphPtr->front();
		ciphPtr->pop();
	}
}
