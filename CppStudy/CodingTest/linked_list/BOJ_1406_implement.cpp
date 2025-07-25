#include <iostream>
#include <list>
using namespace std;

const int MX = 1000005;
int pre[MX], nxt[MX];
char dat[MX];
int unused = 1;

void traverse()
{
	int cur = nxt[0];
	// 끝이 아니면
	while (cur != -1) {
		cout << dat[cur];
		cur = nxt[cur];
	}
	cout << "\n\n";
}

void insert(int addr, char val)
{
	dat[unused] = val;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];

	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;

	unused++;
}

void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);

	string st;
	cin >> st;
	int cursor = 0;
	for (char a : st) {
		insert(cursor, a);
		cursor=nxt[cursor];
	}

	int c_num;
	cin >> c_num;

	while (c_num--)
	{
		char op;
		cin >> op;
		if (op == 'L') {
			if (pre[cursor] != -1) cursor = pre[cursor];
		}
		else if (op == 'D') { if (nxt[cursor] != -1) cursor = nxt[cursor]; }
		else if (op == 'B') {
			if (pre[cursor] != -1) {
				erase(cursor);
				cursor = pre[cursor];
			}
		}
		else if (op == 'P') {
			char v;
			cin >> v;
			insert(cursor, v);
			cursor = nxt[cursor];
		}
	}
	traverse();
	return 0;
}





