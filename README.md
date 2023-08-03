# Cpp_MultiThreading-ThreadPool

This project is a C++ thread pool.

# Intro
- Process: a process is an independent and self-contained unit of execution that represents a running program. It has its own memory space and system resources, such as file handles and network connections. Processes are managed by the OS and provide a way for multiple programs to run concurrently.
- Thread: a thread is the smallest unit of execution within a process. Threads share the same memory space and resources of their parent process, allowing multiple threads to execute concurrently within a single process.
    - Start a thread in C++:
      ```C++
      #include <thread>
      std::thread t(function_name, args...);
      ```
- Thread Pool: A thread pool is a design pattern and a mechanism used in concurrent programming to manage and reuse a fixed number of threads.
    - Create a group of pre-initialized threads that are ready to perform tasks as needed
    - When a task needs to be executed concurrently, the thread pool assigns (not creating a new one) an available thread from the pool to perform the task. 
    - When a task is completed, the thread is returned to the pool, making it available for other tasks.
    - Reduce the overhead of thread creation and destruction
    - Max amount of threads cannot be greater than the amount of CPUs.

