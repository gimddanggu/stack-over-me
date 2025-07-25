#include<iostream>
#include<list>
using namespace std;

int main(void) {
	// 입력 빠르게 받기
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
				//l.erase(cursor); erase() 의 반환값은 삭제된 원소의 다음 위치의 이터레이터
				//반드시 cursor = l.erase() 를 이용해서 다음 위치를 가리키도록 해야한다
				//insert 또한 삽입된 원소의 다음 위치를 반환하긴 하지만 문제에서는 이용할 필요가 없다.
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