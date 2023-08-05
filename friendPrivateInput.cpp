#include<iostream>
#include<thread>
#include<memory>

class testClass {
private:
	friend void t_test();

	void test() {
	std::cout << "Threading" << std::endl;
	}
};

void t_test() {

	std::shared_ptr<testClass> C = std::make_shared<testClass>();

	std::thread tmp(&testClass::test, C);
	tmp.join();
}



int main() {
	
	t_test();

	std::cout << "Done" << std::endl;

	return 0;
}
