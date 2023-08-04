#include<iostream>
#include<thread>

std::thread tmp;

void test(int *x) { //input type pointer
	*x += 1;
	std::cout << *x << "   from thread" << std::endl;
}

int main() {
	int* ptr = new int(1);
	std::thread tmp(test, ptr);
	std::cout << *ptr << std::endl;
	// error if delete ptr now (causing wild pointer)
	tmp.join();

	std::cout << *ptr << std::endl;
	
	delete ptr;
	return 0;
}

/*output:
1
2   from thread
2
*/
