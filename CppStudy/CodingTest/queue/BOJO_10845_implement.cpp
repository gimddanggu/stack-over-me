#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int* front = dat;
	int* rear = dat;

	string command;
	int q;
	int num;
	bool isEmpty;
	cin >> q;

	while (q--) {
		cin >> command;
		isEmpty = rear == front; // 큐가 비어있는지 확인

		if (command == "push") {
			cin >> num;
			*rear = num;
			rear++;
		}
		else if (command == "pop") {
			if (isEmpty) cout << -1 << '\n';
			else
			{
				cout << *front << '\n';
				front++;
			}
		}
		else if (command == "size") {
			cout << rear-front << '\n';
		}
		else if (command == "empty") {
			cout << isEmpty << '\n';
		}
		else if (command == "front") {
			if (isEmpty) cout << -1 << '\n';
			else {
				cout << *front << '\n';
			}
		}
		else if (command == "back") {
			if (isEmpty) cout << -1 << '\n';
			else {
				cout << *(rear - 1) << '\n';
			}
		}
	}


	return 0;
}