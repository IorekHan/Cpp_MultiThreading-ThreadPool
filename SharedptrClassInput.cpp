#include<iostream>
#include<thread>
#include<memory>

class testClass {
public:
	void test() {
	std::cout << "Threading" << std::endl;
	}
};

int main() {

	std::shared_ptr<testClass> C = std::make_shared<testClass>();

	std::thread tmp(&testClass::test, C);

	tmp.join();
	std::cout << "Done" << std::endl;

	return 0;
}
