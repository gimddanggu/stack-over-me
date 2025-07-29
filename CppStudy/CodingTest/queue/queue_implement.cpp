#include <iostream>
using namespace std;

// ���� ť�� �����ϱ� ���ؼ��� ��ⷯ ����(%) �ʿ�
// Python �� ������ ���� % ����� �������� ���� �� �ֱ� ������ (�� + MAX) % MAX �� ���� ������� �������ֱ�
// ���� ť ���������� �ݵ�� �� ĭ�� ����־� �Ѵ�
// > ��������� ���� �� ���¸� �����ϱ� ����
// >> �������: tail == head
// >> ������: (tail+1) % MX == head
// >> ���� ���� ť�� ��� ���� ����� �� �ִ� ������ MAX-1 �� �̴�.
const int MX = 4;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
	dat[tail] = x;
	// ���� ť
	//tail++;
	//dat[tail++] �� ����
	
	// ����ť
	tail = (tail + 1) % MX;
}

void pop() {
	//���� ť
	//head++;
	//���� ť
	head = (head + 1) % MX;
}

int front() {
	//���� ť, ���� ť ����
	return dat[head];
}

int back() {
	//���� ť
	//return dat[tail-1];

	// ���� ť
	return dat[(tail - 1 + MX) % MX]; 
}

int size() {
	//return (tail - head) % MX;			// ����ť�� ��� 
	return (tail - head + MX) % MX;			// ����ť�� ��쿡 
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

