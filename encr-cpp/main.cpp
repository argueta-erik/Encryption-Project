#include <iostream>
#include <queue>

using namespace std;


void insertQueue();

int main() {


	//cout << "Hello World" << endl;
	insertQueue();
	return 0;


}


void insertQueue() {

	string input = "Hello World";
	queue<int> asciiQ;
	queue<char> strQ;

	int parse;
	for (char c : input) {
		//strQ.push(c);
		parse = c;
		asciiQ.push(parse);
	}

	while (!asciiQ.empty()) {
		cout << asciiQ.front() << endl;
		asciiQ.pop();
	}

	//cout << input << endl;

	

}
