#include<iostream>
#include<thread>

std::thread tmp;
int a = 1;
// thread and variable both are global

void test(int& x) { // input reference 
	x++;
	std::cout << x << std::endl;  
}

void callThread() {
	tmp = std::thread(test, std::ref(a)); // ref to call variable as reference content on address
}

int main() {

	callThread();
	tmp.join();
	std::cout << a << std::endl;
	return 0;

}
