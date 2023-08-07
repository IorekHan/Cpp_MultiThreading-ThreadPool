#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<condition_variable>
#include<queue>

std::queue<int> test_q;
std::condition_variable test_cv;
std::mutex mtx;


void Producer(int i) {
	
	for (int j = 0; j < i; j++) {
		std::unique_lock<std::mutex> lock(mtx);
		test_q.push(j);	
		
		std::cout << "task:" << j <<  " is added" << std::endl;
		lock.unlock();
		test_cv.notify_one();

	}
	
}


void Consumer() {
	while (1) {
		std::unique_lock<std::mutex> lock(mtx);
		test_cv.wait(lock, []() {return !test_q.empty(); });
		int output = test_q.front();
		test_q.pop();
		std::cout << "Removed task: " << output << std::endl;
		lock.unlock();
	}
}


int main() {
	std::thread t1(Producer,10);
	std::thread t2(Consumer);
	t1.join();
	t2.join();

	return 0;
}
