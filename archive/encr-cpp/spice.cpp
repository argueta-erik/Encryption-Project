#include <iostream>
using namespace std;

int main() {
	int total{};
	string pwd;

	getline(cin, pwd);

	for (char c : pwd) {
		total += c;
	}
	cout << total << endl;
	return 0;
}
