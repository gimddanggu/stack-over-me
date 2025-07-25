// std::list ������
#include <iostream>
#include <list>
using namespace std;

// insert(iter, num) : iter ��ġ�� num ���� ���� -> l.end() ��ġ������ ���԰�����
// erase(iter) : iter ��ġ�� �ִ� ���� �������϶� -> l.end() ��ġ���� ���� �����ϱ� �Ұ���
// list ���� iterator�� -- ++ ������ �����ϴ�
// �� ���� ���� �߰�/���� �� ���� push_front(), push_back(), ����ϱ�

int main(void) {
	list<int> l = { 1, 2, 3, 4 };
	list<int>::iterator cursor;

	l.push_front(1);
	l.push_back(50);
	cursor = l.end();
	//l.erase(cursor); �Ұ���
	//cursor--;
	//l.erase(cursor); ����
	//l.insert(cursor, 55);

	for (auto a : l) cout << a << ' ';
	//cout << *cursor << endl;
	return 0;
}