#include <iostream>
#include <string>

int main()
{
	// getline()�� ���๮��('\n')���� �Է��� �а�, �� ���๮�ڴ� ������
	/*std::string line;
	std::getline(std::cin, line);

	std::cout << line;
	std::cout << "hello";*/

	// ������ cin�� getline()�� ���� ������� ��� �߻�!!
	// cin >> �� getline()�� ���޾� ����� ���, 
	// cin >> �� ���� ���๮�ڰ� getline()�� ������ �� �� �ִ�

	std::string line2, line3;
	std::cin >> line2;
	std::getline(std::cin, line3);

	std::cout << "line2: " << line2;
	std::cout << "line3: " << line3;

	// cin >> �� ���� '\n'�� ���ۿ� ���� �־�, 
	// ���� getline()�� �̸� �а� �ٷ� ����Ǿ� �� ���ڿ��� ��ȯ

	return 0;
}