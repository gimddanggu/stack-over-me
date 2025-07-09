#include <iostream>

// 매개변수를 참조형으로 받아옴
int func(int& arg)
{
    arg += 1;
    return arg;
}

// 일반 함수 변수
int func1(int arg)
{
    arg += 2;
    return arg;
}

int& func2()
{
    int arg = 3;
    return arg;
}

int main()
{
    int num = 10;
    // func() 함수는 값을 반환
    int res = func(num);
    int& res = func(num);
    int res2 = func1(num);

}