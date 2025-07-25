#include <iostream>
#include <list>
using namespace std;

// �����ܿ� ���� �� ������ �ʱⰪ�� �ִ�. int => 0; char=>''
const int MX = 10000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void traverse()
{
	int cur = nxt[0];
	// ���� �ƴϸ�
	while (cur != -1) {
		cout << dat[cur] << ' ';
		cur = nxt[cur];
	}
	cout << "\n\n";
}
//���� ����Ʈ �߰�
//arr=> ���� ���� �ּ�, num=> ���� ��
void insert(int addr, int num)
{
	//���ο� ��� ����
	dat[unused] = num;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];

	// ���� �����̶� ����
	// ������ ����� ��� ���� ��尡 ����.
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;

	unused++;
}
// ���� ����Ʈ ����
// addr=> ������ �ּ�
void erase(int addr)
{
	//���� ��带 ����
	//������ ��带 ������ ��� nxt[addr] == -1 �� ��Ȳ�� ���� �� �ֱ� ����
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];

	//��� ����
	dat[addr] = 0;
	pre[addr] = 0;
	nxt[addr] = 0;
}


void insert_test() {
	cout << "****** insert_test *****\n";
	insert(0, 10); // 10(address=1)
	traverse();
	insert(0, 30); // 30(address=2) 10
	traverse();
	insert(2, 40); // 30 40(address=3) 10
	traverse();
	insert(1, 20); // 30 40 10 20(address=4)
	traverse();
	insert(4, 70); // 30 40 10 20 70(address=5)
	traverse();
}

void erase_test() {
	cout << "****** erase_test *****\n";
	erase(1); // 30 40 20 70
	traverse();
	erase(2); // 40 20 70
	traverse();
	erase(4); // 40 70
	traverse();
	erase(5); // 40
	traverse();
}

int main(void) {
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);
	insert_test();
	erase_test();

	return 0;
}