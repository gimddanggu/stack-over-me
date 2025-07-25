#include <iostream>
#include <stack>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

// 스택에 값 삽입
void push(int x)
{
	dat[pos] = x;
	pos++;
	// 위의 두 줄을 후위표기식을 사용하면 한 줄로 코드 작성이 가능하다
	// dat[pos++] = x
}
// 스택에서 값 꺼내기
void pop()
{
	dat[pos] = 0;
	pos--;
	// 이 코드 또한 후위표기식 사용, 0으로 굳이 초기화 할 필요 없으므로
	// pos--;
}
// 스택에서 맨 위의 값 확인
// pos는 다음 원소 추가될 때 삽입될 위치!!!
int top()
{
	return dat[pos-1];
}

void test() {
	push(5); push(4); push(3);
	cout << top() << '\n'; // 3
	pop(); pop();
	cout << top() << '\n'; // 5
	push(10); push(12);
	cout << top() << '\n'; // 12
	pop();
	cout << top() << '\n'; // 10
}

int main(void)
{
	test();
}