#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len){
    if (idx == len) 
    {
        arr[idx] = num; // 마지막 원소에 값을 넣는 경우
        len += 1;
    }
    else
    {
        for(int i = len; i >= idx; i--)
        {
            arr[i+1] = arr[i];
        }

        arr[idx] = num;
        len += 1;
    }
}

void erase(int idx, int arr[], int& len){
    if (idx == len-1) // 마지막 값 삭제
    {
        arr[idx] = 0;
        len -= 1;
    }
    else 
    {
        for (int i = idx+1; i < len; i++)
        {
            arr[i-1] = arr[i];
        }
        len -= 1;
    }
     
}

void printArr(int arr[], int& len){
  for(int i = 0; i < len; i++) cout << arr[i] << ' ';
  cout << "\n\n";
}

void insert_test(){
  cout << "***** insert_test *****\n";
  int arr[10] = {10, 20, 30};
  int len = 3;
  insert(3, 40, arr, len); // 10 20 30 40
  printArr(arr, len);
  insert(1, 50, arr, len); // 10 50 20 30 40
  printArr(arr, len);
  insert(0, 15, arr, len); // 15 10 50 20 30 40
  printArr(arr, len);
}

void erase_test(){
  cout << "***** erase_test *****\n";
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(4, arr, len); // 10 50 40 30 20
  cout << len << '\n';
  printArr(arr, len);
  erase(1, arr, len); // 10 40 30 20
  cout << len << '\n';
  printArr(arr, len);
  erase(3, arr, len); // 10 40 30
  cout << len << '\n';
  printArr(arr, len);
}

int main(void) {
  insert_test();
  erase_test();
}