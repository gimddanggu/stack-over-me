#include <iostream>
using namespace std;
int main()
{
    int size;
    int* arr;
    int* arr2;

    cout << "배열크기: ";
    cin >> size;
    arr = new int; // 자바에서는 일반 변수에 넣을 수 있지만 
    // c++에는 포인터의 개념이 있으므로 포인터로 받아야 한다

    arr = new int[size];
    // java 에서는 int를 가비지컬렉터로 자동적으로 소멸시켜주지만 
    // c++에서는 heap 영역에 남아있기 때문에 소멸자를 호출해 메모리를 해제시켜야 한다.

    delete arr;
    //delete arr2; 배열 형태로 선언했기 때문에 배열형태로 소멸 시켜줘야한다.
    delete[] arr2;

    return 0;
}