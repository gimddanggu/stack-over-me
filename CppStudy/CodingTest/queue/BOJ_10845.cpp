#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;

	int cNum;
	cin >> cNum;
	string command;
	int num;
	while (cNum--)
	{
		cin >> command;
		if (command == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (command == "front")
		{
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (command == "back")
		{
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
		else if (command == "pop")
		{
			if (q.empty()) cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (command == "size")
		{
			cout << q.size() << '\n';
		}
		else if (command == "empty")
		{
			if (q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
	return 0;
}