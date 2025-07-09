#include <iostream>

// 매개변수를 참조형으로 받아옴
int func(int& arg)
{
    arg += 1;
    return arg;
}

// 일반 함수
int func1(int arg)
{
    arg += 2;
    return arg;
}

// 참조형을 반환하는 함수
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
    // int& res1 = func(num);    
    // func(num)은 복사된 int 값, 임시 객체(rvalue) 리턴
    // int& 는 좌값(lvalue) 에만 바인딩 가능
    // lvalue: 메모리의 주소가 있는 값, 이름 붙은 변수
    // rvalue: 임시 값, 리터럴, 계산 결과, 메모리의 주소가 없는 값
    const int& res =func(num);
    // C++ 에서는 임시 객체(rvalue)는 const&로 참조 가능하다!!!

    /* !기억하기!
     * int& (일반 참조) 일 경우 lvalue만 받을 수 있다
     * const int& (const 참조) 일 경우 rvalue도 받을 수 있다.
     */

    int res3 = func1(num);

    int& res = func2(); 
    // 이 경우 눈에 보이는 에러는 없지만, func2 의 arg는 함수 종료와 함께 사라지므로 쓰레기 값이 출려된다 

}