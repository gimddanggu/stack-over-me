// 멤버변수 초기화
#incldue <iostream>

// 1. 생성자 초기화
class MyClass {
    int a;      // 0
public:
    MyClass(int _a) { a = _a;} // 전달받은 a 값
}; // 2번의 대입 연산 이루어짐 

//2. 초기화 리스트
class MyClass1 {
    int a;
public:
    MyClass1(int _a) : a(_a) {}
}; // 1번의 대입 연산이 이루어짐

// C++11 이후(in_class 초기화)
class MyClass2 {
    int x = 10;     // 선언과 동시에 초기화 - 내부적으로 초기화 리스트 형태로 만들어줌 
};
// static 초기화 - 클래스 외부에서 초기화 한다
class MyClass3 {
    // static int count = 10; // 선언과 동시에 초기화 되어야 함
    // in-class initializer가 있는 멤버는 const여야 합니다 오류 발생
    // -> 클래스 외부에서 초기화를 시켜줄 필요 있음
    static int count;
};
// int count = 0; => 이건 전역변수 선언이므로 스코프:: 붙여서 초기화해야한다.
int MyClass3::count = 0;
// const 초기화
class Myclass4 {
    const int id = 10;
public:
    Myclass4(int _id) : id(_id){}    
};
// 참조 초기화
class MyClass5 {
    int& ref;
    int x;
public:
    MyClass5(int& r): ref(r) {}
    // void f(int _x) : x(_x){} 일반 함수에서는 초기화 리스트를 할 수 없다. 생성자에서만 !!!!
};

// 객체를 전역변수 형태로 선언
MyClass a(10); // main() 함수 호출보다 먼저생성됨

int main()
{
    MyClass b(10);
    return 0;
}

// 일반함수, 
// 인라인함수:  그 위치에 바로 코드 삽입되어 실행됨