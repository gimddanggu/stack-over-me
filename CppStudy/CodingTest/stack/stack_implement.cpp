#include <iostream>
#include <stack>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

// ���ÿ� �� ����
void push(int x)
{
	dat[pos] = x;
	pos++;
	// ���� �� ���� ����ǥ����� ����ϸ� �� �ٷ� �ڵ� �ۼ��� �����ϴ�
	// dat[pos++] = x
}
// ���ÿ��� �� ������
void pop()
{
	dat[pos] = 0;
	pos--;
	// �� �ڵ� ���� ����ǥ��� ���, 0���� ���� �ʱ�ȭ �� �ʿ� �����Ƿ�
	// pos--;
}
// ���ÿ��� �� ���� �� Ȯ��
// pos�� ���� ���� �߰��� �� ���Ե� ��ġ!!!
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