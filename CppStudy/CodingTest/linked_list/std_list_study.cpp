// std::list 익히기
#include <iostream>
#include <list>
using namespace std;

// insert(iter, num) : iter 위치에 num 값을 삽입 -> l.end() 위치에서도 삽입가능함
// erase(iter) : iter 위치에 있는 값을 삭제하하라 -> l.end() 위치에는 값이 없으니까 불가능
// list 에서 iterator는 -- ++ 연산이 가능하다
// 맨 앞의 값을 추가/삭제 할 때는 push_front(), push_back(), 사용하기

int main(void) {
	list<int> l = { 1, 2, 3, 4 };
	list<int>::iterator cursor;

	l.push_front(1);
	l.push_back(50);
	cursor = l.end();
	//l.erase(cursor); 불가능
	//cursor--;
	//l.erase(cursor); 가능
	//l.insert(cursor, 55);

	for (auto a : l) cout << a << ' ';
	//cout << *cursor << endl;
	return 0;
}