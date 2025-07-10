#include <iostream>
using namespace std;


// inline 정의를 붙이면 함수 호출 시 함수 정의부분으로 찾아가지 않고
// 붙여넣어짐 =-> 속도 빨라짐효과
// 단 간단한 함수여야 하며 inline기호가 붙어있어도 결정은 컴파일러가 함

// 메크로 함수
#define add(x) x+x

inline int func(int x)
{
    return x + x;
}

int main()
{
    cout << func(2) << endl;

    return 0;
}
