#include <iostream>
#include <string.h>
using namespace std;

class Person {
    char name[10];
    std::string name;
    int age;
public:

    Person() {}
    Person(const char* name, int age) 
    {
        //  strcpy(this->name, name); 널문자가 안들어갈 가능성있음 => strncpty() 사용으로 안전하게
        strncpy(this->name, name, strlen(name)+1);
        this->age = age;
        printf("Constructor 호출!! ");
    }

    // 복사생성자는 값을 변경할 수 없으므로 const 붙여야함
    // 복사 생성자는 원래 객체의 정보를 읽어서 새 객체에 복사하는 역할
    // => 원래 객체를 수정할 이유가 없음!!!
    // => const Person&은 const객체, 비-const 객체 모두 받을 수 있음 => 유연성 측면 good
    // 궁금증 6: &를 붙이는 이유?
    // 값으로 객체를 받으면 복사 생성자 안에 또 복사가 발생 -> 무한 재귀발생 => 참조로 받아야 함
    Person(const Person& other) { // const ref 상수

    }
    ~Person(){} 
    void view()
    {
        printf(" name: %s, age: %d\n", this->name, this->age);
    }

};

int main()
{
    // char c[3] = "abc"; // 문자열을 넣으려면 \n 문자열 공간을 줘야함(문자열 길이 + 1)
    char c[4] = "abc";
    // c[0] = 'a';
    // c[1] = 'b';
    // c[2] = 'c';

    Person p("김다현", 25);
    p.view();

    Person p2(p);    
    p2.view();        

    Person p3 = p;
    p3.view();        

    return 0;
}