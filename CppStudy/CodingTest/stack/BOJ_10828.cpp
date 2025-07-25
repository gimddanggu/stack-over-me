#include <iostream>
#include <stack>
#include <string>	// getline()/ istringstream()
#include <sstream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	int poss = 0;
	
	int c_num;
	cin >> c_num;
	//cout << c_num << '\n';
	cin.ignore();
	while (c_num--) {
		string line;
		getline(cin, line);
		istringstream iss(line); // 문자열 스트림 생성 
		string cmd;
		iss >> cmd;

		if (cmd == "push")
		{
			int n;
			iss >> n;
			s.push(n);
		}
		else if (cmd == "pop")
			if (s.empty()) cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}

		else if (cmd == "top")
			if (s.empty()) cout << -1 << '\n';
			else cout << s.top() << '\n';

		else if (cmd == "size") cout << s.size() << '\n';

		else if (cmd == "empty")
			if (s.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';

	}

	return 0;
}
