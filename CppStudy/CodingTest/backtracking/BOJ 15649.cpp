// 0x0C 백트래킹
// boj 15649 N과 M(1)

#include <iostream>
using namespace std;

int arr[10] = { 0 };
int isused[10] = { 0 };
int n, m;

void func(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1; // 사용함을 바꿔줌
			func(k + 1); // 다음 자리 탐색
			isused[i] = 0; // 함수를 빠져나왔을 경우 사용을 false로 바꿈
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);

	return 0;
}


// array 는 std 에 있는 자료형이므로 배열 이름으로 사용하지 말 것!
// if (isused[i]) 에서 배열[i] 을 안주는 실수 했다..
// if(isused) 라고 썼을 때는 어떻게 결과가 나오냐? 
// -> 배열의 이름은 배열의 "포인터 주소" 이다. 즉 유효한 포인터 주소 이므로 항상 true 라는 결과가 나온다.
// 값을 가지고 참/거짓을 판별하고 싶을 경우 [] 를 꼭 사용해주도록 하자
