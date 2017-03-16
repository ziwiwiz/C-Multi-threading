// study "thread.h"
#include <iostream>
#include <thread>

void thread_task1(int n)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Thread 1:" << n << std::endl;
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
void thread_task2(int& n)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Thread 2:" << n << std::endl;
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

int main()
{
	int n = 0;
	std::thread t1; // t1 is not a thread
	std::thread t2(thread_task1, n); // pass by value
	std::thread t3(thread_task2, std::ref(n)); // pass by reference
	std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a 
	std::cout << "joinable:" << t1.joinable()<< ":" << t2.joinable() << ":" << t3.joinable() << ":" << t4.joinable() << std::endl;
	std::cout << "get_id:" << t1.get_id() << ":" << t2.get_id() << ":" << t3.get_id() << ":" << t4.get_id() << std::endl;
	std::cout << "native_handle:" << t1.native_handle() << ":" << t2.native_handle() << ":" << t3.native_handle() << ":" << t4.native_handle() << std::endl;
	std::cout << "hardware_concurrency" <<t1.hardware_concurrency() << ":" << t2.hardware_concurrency() << ":" << t3.hardware_concurrency() << ":" << t4.hardware_concurrency() << std::endl;
	t2.join();
	t4.detach();
	std::cout << n << std::endl;
	return 0;
}