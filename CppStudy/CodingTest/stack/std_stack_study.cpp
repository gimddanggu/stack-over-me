// std::stack ������
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// stack �� container_adapter �� ���ο� deque�� vector ���� �����̳ʸ� ���δ� �����
// ���� �ʱ�ȭ ����Ʈ �����ڸ� �������� �ʴ´� {} ���·� �ʱ�ȭ �Ұ�
// �ʱ�ȭ���: (1) ����.push() / (2) vector or deque�� ���� �ʱ�ȭ �� �� stack ����
// LIFO �����̹Ƿ� ���� ���� ���� Ȯ���� �� �ִ�. (top)
// pop() �Լ��� ���ÿ��� ���� ������ ������ �� ���� ��ȯ���� �ʴ´�.
// iterator ���Ұ�
// [], at() �����ڰ� �������� �����Ƿ� ���� �ε��� ������ �Ұ��ϴ�.
// empty() �� ������ ����ִ��� Ȯ�� ����

int main(void) {
	stack<int> s;
	//stack<int> s1 = { 1, 2, 4, 5 }; �ʱ�ȭ �Ұ�
	//vector<int> v = { 1, 2, 3, 4, 5 }; �ʱ�ȭ(2)
	//stack<int, vector<int>> s2(v);	 �ʱ�ȭ(2)
	//cout << s2.size() << '\n';
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.size() << '\n';
	if (s.empty()) cout << "s is empty\n";
	else cout << "s is not empty\n";
	s.pop();
	cout << s.size() << '\n';
	cout << s.top() << '\n';
	s.pop();
	// cout << s.pop() << '\n';
	s.pop();

	if (s.empty()) cout << "s is empty\n";
	//cout << s.top() << '\n';



}