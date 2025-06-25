## STL 정리

### 참고자료 
[geeksforgeeks](https://www.geeksforgeeks.org/cpp/the-c-standard-template-library-stl/)

**Sequence Containers**
- Arrays
- Vector
- Deque
- Lists
- Forward Lists

**Container Adaptors**
- Stack
- Queue
- Priority Queue

**Associative Containers**
- Sets
- Maps
- Multisets
- Multimaps

**Unordered Associative Containers**
- Unordered Set
- Unordered Multiset
- Unordered Map
- Unordered Multimap


### vector
```cpp
vector<T> v;
```

#### 벡터 초기화 방법
```cpp
vector<int> v1 = {1, 4, 2, 3, 5};

vector<int> v2(5, 9); // 값이 모두 9인 5크기의 벡터 생성
```

#### 벡터 값 삽입 방법
```cpp
vector<int> v = {1, 2, 3, 5}

// 1) 맨 끝에 값 삽입
v.push_back(6)

// 2) 중간에 값 삽입 (index 3)
v.insert(v.begin() + 3) 
```

#### 벡터 값 접근 방법
```cpp
vector<char> v = {'a', 'b', 'e', 'f'}
// 1) []
v[2] = 'c'

// 2) at()
v.at(3) = 'd'

// 결과 {'a', 'c', 'f', 'd', 'z'}
```

#### 벡터 사이즈 확인
```cpp
vector<char> v = {'a', 'c', 'f', 'd', 'z'};
cout << v.size();

// 출력 결과 : 5
```

#### 벡터 값 삭제
```cpp
vector<char> v = {'a', 'c', 'f', 'd', 'z'};

// 1) 마지막 값 삭제
v.pop_back();

// 2) 특정 값 찾아서 삭제
v.erase(find(v.begin(), v.end(), 'f'));
```