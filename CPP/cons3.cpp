#include <iostream>

class MyClass {
    int num;    // 인자 하나므로 변환생성자 호출 가능
public:
    MyClass(int n) : num(n) { } // 변환 생성자
};

int main()
{

    return 0;
}