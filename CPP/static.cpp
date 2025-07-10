#include <iostream>
using namespace std;

class MyClass{
private:

    // 맴버변수 생성할 때 a 값을 초기화 했지만 이후 생성자에서 20을 대입했기 때문에 20 출력
    int a = 10; // 객체의 멤버
    static int static_a; // 같은 객체끼리 공유하는 값 클래스의 멤버
public:
    MyClass();
    void print();
    // static 변수 값을 건드리기 위해서는 별도의 메서드를 만드는 것이 좋다(이유는 ..?)
    static void set_static_a(int _a); // 선언
};
// private인데도 접근 가능함
// -> 객체들 한테 접근 제한자가 적용된다는 것을 알 수 있다. 
// -> 클래스를 통해서 접근할 수 있음
int MyClass::static_a = 100;
// 이런 생성자를 만들면 초기화가 어떻게 되는걸까?
MyClass::MyClass()
{
    a = 20;
}
// 함수 정의 부분에서는 static 키워드 붙지 않는다.
void MyClass::set_static_a(int _a)
{
    static_a = _a;
    // a = 8; // 일반 멤버가 static 함수에 들어올 수 없음
}
void MyClass::print() {
    std::cout << a << ", " << static_a << std::endl;
}

int main()
{
    MyClass obj;
    obj.print();
    // 속성을 public 으로 해놨기 때문에 오류 x
    obj.static_a = 50; // 문법상 맞지만 별로 좋은 방법은 아님
    obj.print();

    MyClass obj2;
    obj2.print();


    return 0;
}

// 한 줄 정리: static은 클래스 거다. 객체를 이용해서 static에 접근하는 것은 좋지 않다.