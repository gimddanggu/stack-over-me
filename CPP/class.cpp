#include <iostream>

class Myclass {
    // 속성값은 보통 private
    private: 
        int id;
        char name[20];
        int age;
    
    // 메서드는 보통 public
    public:
        // 생성자: 클래스이름과 동일한 메서드, 출력값이 없음!!!!
        // 디폴트 생성자: Myclass() {} 안만들면 os가 자동생성해줌
        Myclass(int id, char name[20], int age) {
            // this는 객체를 가리키는 포인터!!!!
            // this.id = id; // 자바 방법, 자바에는 포인터 개념이 없다. 
            this->age = 25;  // C++ 방법, C에는 포인터 개념이 있기 때문에 정확하게 써줘야 한다.
            // this->name = name; // 문자열을 대입연산자로 대입할 수 없다!!!! (but 객체인 string은 가능)
            // 배열을 선언한 후 문자열을 저장하는 경우는 
            strcpy(this->name, name); // 문자열 복사로 값 초기화 가능
        }
}
