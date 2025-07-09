#include <iostream>
// 수정 하기
int func(int& arg)
{
    arg += 1;
    return arg;
}

int func1(int arg)
{
    arg += 2;
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