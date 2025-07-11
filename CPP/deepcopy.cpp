#include <iostream>
#include <string.h>
using namespace std;
// 깊은 복사
// 궁금증7 : 깊은 복사 왜 필요함?
class Person {
    char* mname;
    // char mname[10]; // 궁금증8:왜 얘는 안될까?
    std::string name;
    int age;
public:

    Person() {}
    Person(const char* name, int age) 
    {
        mname = new char[strlen(name) + 1];
        strncpy(mname, name, strlen(name)+1);
        this->age = age;
        printf("Constructor 호출!! ");
    }

    Person(const Person& other) { 
        mname = new char[strlen(other.mname) + 1];
        strcpy(mname, other.mname);
        age = other.age;
        printf("Copy constructor 호출")
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

