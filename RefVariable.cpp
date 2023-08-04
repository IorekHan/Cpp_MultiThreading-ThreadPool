#include<iostream>
#include<thread>

void test(int& x) { // input address reference

	x++;
	std::cout << x << std::endl;

}

int main() {

	int a = 1;
	std::thread tmp(test, std::ref(a)); // use ref() to feed right input 
	tmp.join();
	std::cout << a << std::endl;
	return 0;

}
