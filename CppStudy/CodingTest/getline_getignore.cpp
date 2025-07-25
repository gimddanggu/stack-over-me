#include <iostream>
#include <string>

int main()
{
	// getline()은 개행문자('\n')까지 입력을 읽고, 그 개행문자는 버린다
	/*std::string line;
	std::getline(std::cin, line);

	std::cout << line;
	std::cout << "hello";*/

	// 문제는 cin과 getline()을 같이 사용했을 경우 발생!!
	// cin >> 와 getline()을 연달아 사용할 경우, 
	// cin >> 가 남긴 개행문자가 getline()에 영향을 줄 수 있다

	std::string line2, line3;
	std::cin >> line2;
	std::getline(std::cin, line3);

	std::cout << "line2: " << line2;
	std::cout << "line3: " << line3;

	// cin >> 가 남긴 '\n'이 버퍼에 남아 있어, 
	// 다음 getline()은 이를 읽고 바로 종료되어 빈 문자열을 반환

	return 0;
}