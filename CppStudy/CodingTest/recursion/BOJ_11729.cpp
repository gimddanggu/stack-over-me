// 0x0B 재귀
// boj 11729 하노이 탑

#include <iostream>
using namespace std;
void func(int a, int b, int n);

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	/*long long moves = (1LL << n) - 1;
	
	if (n > 20) {
		cout << moves << '\n';
		return 0;
	}*/

	cout << (1 << n) - 1 << '\n';
	func(1, 3, n);
}

void func(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}

	func(a, 6 - a - b, n-1);
	cout << a << ' ' << b << '\n';
	func(6 - a - b, b, n-1);
}