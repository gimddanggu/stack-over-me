#include <iostream>
#include <string.h>
using namespace std;

class Person {
    char name[10];
    std::string name;
    int age;
public:
    // 값을 읽기만 하는 경우 const 붙여주는게 좋음 
    // 궁금증1: 왜 const int 는 안하나???
    Person() {}
    Person(const char* name, int age) // 얘네는 객체마다 생기는 거 -> 스택영역에 저장
    {
        // this->name = name;
         strcpy(this->name, name);
        this->age = age;
        printf("Constructor 호출!! ");
    }
    ~Person(){} // 객체마다 생성되는 변수밖에 없으므로 객체에서 소멸가능
    void view()
    {
        printf(" name: %s, age: %d\n", this->name, this->age);
    }

};

int main()
{
    // Person p; // 기본 생성자가 없으므로 오류
    // 코드상에 생성자를 만들었으면 기본 생성자 생성 안해줌
    // 기본형태가 필요할 때는 명시적으로 만들어주기!!
    Person p("김다현", 25);
    p.view();

    Person p2(p);     // 디폴트 복사 생성자 호출 
    p2.view();        // Constructor 호출!! 가 한 번만 실행됨

    Person p3 = p;
    p3.view();        // 복사 생성자 호출

    // 멤버 변수는 복사됨
    // 멤버 함수는 복사안됨!!! 함수는 코드영역에서 공유됨!!!!

    return 0;
}