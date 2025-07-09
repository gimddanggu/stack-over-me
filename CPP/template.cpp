// int func(int& arg)
// {
//     arg += 1;
//     return arg;
// }

// int func1(int arg)
// {
//     arg += 2;
//     return arg;
// }
// int main()
// {
//     int num = 10;

//     const int& res = func(num);
//     int res2 = func1(num);

// }


// 여러 가지 타입을 정의하는 것 보다 훨씬 편리하다
// 이것은 런타임때 타입이 결정된다.
#include <iostream>

template <typename T>
T add(T a, T b)
{
    return a + b;
}


int main()
{
    std::cout << add(3, 4) << std::endl;
    std::cout << add(3.3, 4.3) << std::endl;
    // std::cout << add(3, 4.3) << std::endl; 
    // 템플릿 인자 추론 실패하기 때문에 컴파일 에러가 발생한다 
    // 서로 다른 타입을 허용하려면 템플릿 매개변수를 2개로 분리해야 한다. (추가)

}

// (추가)
// -> decltype(a + b) 함수의 반환 타입을 명시하는 것 (C+11 문법)
template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

// C++14부터는 함수 반환 타입을 auto로 하고, 함수 본문에서 자동 추론 가능해짐
template <typename T1, typename T2>
auto add(T1 a, T2 b)
{
    return a + b;
}