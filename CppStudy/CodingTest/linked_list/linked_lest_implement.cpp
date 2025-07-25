#include <iostream>
#include <list>
using namespace std;

// 전역단에 선언 한 변수는 초기값이 있다. int => 0; char=>''
const int MX = 10000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void traverse()
{
	int cur = nxt[0];
	// 끝이 아니면
	while (cur != -1) {
		cout << dat[cur] << ' ';
		cur = nxt[cur];
	}
	cout << "\n\n";
}
//연결 리스트 추가
//arr=> 값을 넣을 주소, num=> 넣을 값
void insert(int addr, int num)
{
	//새로운 노드 생성
	dat[unused] = num;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];

	// 기존 노드들이랑 연결
	// 마지막 노드일 경우 다음 노드가 없다.
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;

	unused++;
}
// 연결 리스트 삭제
// addr=> 삭제될 주소
void erase(int addr)
{
	//기존 노드를 연결
	//마지막 노드를 삭제할 경우 nxt[addr] == -1 인 상황이 생길 수 있기 때문
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];

	//노드 삭제
	dat[addr] = 0;
	pre[addr] = 0;
	nxt[addr] = 0;
}


void insert_test() {
	cout << "****** insert_test *****\n";
	insert(0, 10); // 10(address=1)
	traverse();
	insert(0, 30); // 30(address=2) 10
	traverse();
	insert(2, 40); // 30 40(address=3) 10
	traverse();
	insert(1, 20); // 30 40 10 20(address=4)
	traverse();
	insert(4, 70); // 30 40 10 20 70(address=5)
	traverse();
}

void erase_test() {
	cout << "****** erase_test *****\n";
	erase(1); // 30 40 20 70
	traverse();
	erase(2); // 40 20 70
	traverse();
	erase(4); // 40 70
	traverse();
	erase(5); // 40
	traverse();
}

int main(void) {
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);
	insert_test();
	erase_test();

	return 0;
}