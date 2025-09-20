﻿// 0x0B 재귀
// boj 1074 z

#include <iostream>
using namespace std;
int func(int n, int r, int c);
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
	
	return 0;
}

int func(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1 << (n - 1);
	if (r < half && c < half) return func(n - 1, r, c); // 1 
	if (r < half && c >= half) return half * half + func(n - 1, r, c-half); // 2
	if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c); // 4
	return 3 * half * half + func(n - 1, r - half, c - half); // 3
}


