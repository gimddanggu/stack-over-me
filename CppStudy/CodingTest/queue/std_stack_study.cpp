#include <iostream>
#include <queue>
using namespace std;

// queue �� ����ִµ� front, back, pop ȣ���ϸ� ��Ÿ�ӿ����� �߻��� �� ����
// ���ð� �����ϰ� �����̳ʸ� ���δ� wrapper ������ ����� �����̳�
// ������ ���ʸ� Ȯ�� �����ѵ� queue �� �� ���� Ȯ�ΰ���??
// > ������ `�� ��`�� ���丸 �ֱ� ������ �ݴ� ������ �ǹ̴� ����
// > �ݸ� queue�� �������� �Է� �� ������ ��� �ϴ� �����̱� ������ front()�� ������ ���� ��, back()�� ���������� ���� ��. ����ǹ̰� �ִ�
// ���ð� �ٸ� ������ ���� (iterator ����, at, [] �ε��� ���� �Ұ�..)
// std::stack<int, std::vector<int>> �� ����Ͽ� vector ������� �����ϰ� �� �� �ִ� (�⺻ dequeue)

int main(void) {
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	cout << q.size() << '\n';
	if (q.empty()) cout << "Q is empty\n";
	else cout << "Q is not empty\n";
	q.pop();
	// front, back�� ���Ȯ������ �����ϴ� ���� �ƴϴ�
	cout << q.front() << '\n';
	cout << q.back() << '\n';
	cout << q.front() << '\n';
	cout << q.back() << '\n';
	q.pop();
	q.pop();
	if (q.empty()) cout << "Q is empty\n";
	else cout << "Q is not empty\n";

	return 0;
}