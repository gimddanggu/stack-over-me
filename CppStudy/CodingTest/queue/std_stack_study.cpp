#include <iostream>
#include <queue>
using namespace std;

// queue 가 비어있는데 front, back, pop 호출하면 런타임에러가 발생할 수 있음
// 스택과 동일하게 컨테이너를 감싸는 wrapper 형태의 어댑터 컨테이너
// 스택은 한쪽만 확인 가능한데 queue 는 왜 양쪽 확인가능??
// > 스택은 `맨 위`의 개념만 있기 때문에 반대 방향의 의미는 없다
// > 반면 queue는 한쪽으로 입력 한 쪽으로 출력 하는 구조이기 때문에 front()는 다음에 나갈 값, back()은 마지막으로 들어온 값. 모두의미가 있다
// 스택과 다른 성질은 같다 (iterator 없음, at, [] 인덱스 접근 불가..)
// std::stack<int, std::vector<int>> 를 사용하여 vector 기반으로 동작하게 할 수 있다 (기본 dequeue)

int main(void) {
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	cout << q.size() << '\n';
	if (q.empty()) cout << "Q is empty\n";
	else cout << "Q is not empty\n";
	q.pop();
	// front, back은 요소확인이지 추출하는 것은 아니다
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