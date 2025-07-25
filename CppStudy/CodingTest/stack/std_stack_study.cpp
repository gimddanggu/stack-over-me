// std::stack 익히기
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// stack 은 container_adapter 로 내부에 deque나 vector 같은 컨테이너를 감싸는 어댑터
// 따라서 초기화 리스트 생성자를 지원하지 않는다 {} 형태로 초기화 불가
// 초기화방법: (1) 직접.push() / (2) vector or deque로 먼저 초기화 한 후 stack 생성
// LIFO 구조이므로 제일 위의 값만 확인할 수 있다. (top)
// pop() 함수는 스택에서 값을 꺼내는 역할일 뿐 값을 반환하지 않는다.
// iterator 사용불가
// [], at() 연산자가 존재하지 않으므로 직접 인덱스 접근이 불가하다.
// empty() 로 스택이 비어있는지 확인 가능

int main(void) {
	stack<int> s;
	//stack<int> s1 = { 1, 2, 4, 5 }; 초기화 불가
	//vector<int> v = { 1, 2, 3, 4, 5 }; 초기화(2)
	//stack<int, vector<int>> s2(v);	 초기화(2)
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