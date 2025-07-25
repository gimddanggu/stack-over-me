#include<iostream>
#include<list>
using namespace std;

int main(void) {
	// �Է� ������ �ޱ�
	ios::sync_with_stdio(0);
	cin.tie(0);

	string st;
	list<char> l;
	list<char>::iterator cursor;
	
	cin >> st;
	for (auto a : st) l.push_back(a);
	cursor = l.end();

	int command_num;
	cin >> command_num;

	while (command_num--) {
		char op;
		cin >> op;
		if (op == 'L')
		{
			if (cursor != l.begin()) cursor--;
		}
		else if (op == 'D')
		{
			if (cursor != l.end()) cursor++;
		}
		else if (op == 'B')
		{
			if (cursor != l.begin())
			{
				cursor--;
				//l.erase(cursor); erase() �� ��ȯ���� ������ ������ ���� ��ġ�� ���ͷ�����
				//�ݵ�� cursor = l.erase() �� �̿��ؼ� ���� ��ġ�� ����Ű���� �ؾ��Ѵ�
				//insert ���� ���Ե� ������ ���� ��ġ�� ��ȯ�ϱ� ������ ���������� �̿��� �ʿ䰡 ����.
				cursor = l.erase(cursor);
			}
		}
		else if (op == 'P')
		{
			char v;
			cin >> v;
			l.insert(cursor, v);
		}

	}
	
	for (auto a : l) cout << a;

	return 0;
}