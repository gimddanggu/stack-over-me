#include <iostream>
using namespace std;

// 원형 큐를 구현하기 위해서는 모듈러 연산(%) 필요
// Python 을 제외한 언어는 % 연산시 음수값이 나올 수 있기 때문에 (값 + MAX) % MAX 와 같은 방식으로 보정해주기
// 원형 큐 구현에서는 반드시 한 칸을 비워둬야 한다
// > 비어있음과 가득 참 상태를 구분하기 위해
// >> 비어있음: tail == head
// >> 가득참: (tail+1) % MX == head
// >> 따라서 원형 큐의 경우 실제 사용할 수 있는 공간은 MAX-1 개 이다.
const int MX = 4;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
	dat[tail] = x;
	// 선형 큐
	//tail++;
	//dat[tail++] 도 가능
	
	// 원형큐
	tail = (tail + 1) % MX;
}

void pop() {
	//선형 큐
	//head++;
	//원형 큐
	head = (head + 1) % MX;
}

int front() {
	//선형 큐, 원형 큐 동일
	return dat[head];
}

int back() {
	//선형 큐
	//return dat[tail-1];

	// 원형 큐
	return dat[(tail - 1 + MX) % MX]; 
}

int size() {
	//return (tail - head) % MX;			// 선형큐의 경우 
	return (tail - head + MX) % MX;			// 원형큐인 경우에 
}

bool isEmpty() {
	return tail == head;
}

bool isFull() {
	return (tail + 1) % MX == head;
}

void test() {
	push(10); push(20); push(30);
	cout << front() << '\n'; // 10
	cout << back() << '\n'; // 30
	pop(); pop();
	push(15); push(25);
	cout << front() << '\n'; // 30
	cout << back() << '\n'; // 25
	cout << size() << '\n'; // 3
	pop(); pop(); pop();
	cout << isEmpty() << '\n';
	push(100); push(200); push(300);
	cout << isFull() << '\n';



}

int main(void) {
	test();
}

