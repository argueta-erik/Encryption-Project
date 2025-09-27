#include <iostream>
using namespace std;

int main() {
	cout << "The initial letter: \'H\': 72" << endl;
	int oof = (72 + 7) % 126;
	cout << "72 turns into: " << oof << endl;
	char translate = oof;
	cout << oof << "is: " << translate << endl;
	int revert{ (oof - 7) % 126 };
	cout << revert << endl;
	int oof2 = revert;
	cout << oof2 << endl;
	return 0;
}
