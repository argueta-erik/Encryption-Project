#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

void receiveText(ifstream& inputF, queue<int>* charPtr);
void outputText(ofstream& outputF, queue<int>* charPtr);

int main() {
	queue<int> charQ{};
	queue<int>* charPtr { &charQ };
	ifstream inputFile("plaintext.txt", ios::in);
	ofstream outputFile("encrypted.txt", ios::out);

	receiveText(inputFile, charPtr);
	outputText(outputFile, charPtr);


	//while (!charQ.empty()) { cout << charQ.front() << " "; charQ.pop(); }
	cout << endl;
	return 0;
}


void receiveText(ifstream& inputF, queue<int>* charQ) {
	string word{};
	if (!inputF) { cerr << "File not found" << endl; exit(-1); }
	while(!inputF.eof()) {
		getline(inputF, word);
		//cout << word << endl;
		for (char c : word) { int ascii = c; charQ->push(ascii); }
	}
}

void outputText(ofstream& outputF, queue<int>* charPtr) {
	if (!outputF) { cerr << "File could not be created or opened" << endl; exit(-1); }
	while (!charPtr->empty()) {
		outputF << charPtr->front() << " ";
		charPtr->pop();
	}
}
