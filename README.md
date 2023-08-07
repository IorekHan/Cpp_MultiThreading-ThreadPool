# Cpp_MultiThreading-ThreadPool

This project is a C++ thread pool. Following contents includes:
- Threading functions intro.
- How to deal with different input type.

# Intro
- Process: a process is an independent and self-contained unit of execution that represents a running program. It has its own memory space and system resources, such as file handles and network connections. Processes are managed by the OS and provide a way for multiple programs to run concurrently.
- Thread: a thread is the smallest unit of execution within a process. Threads share the same memory space and resources of their parent process, allowing multiple threads to execute concurrently within a single process.
- Functions:
    - Start a thread in C++:
      ```C++
      #include <thread>
      std::thread t(function_name, args...);
      ```
    - Freeze to wait for thread complete:
      ```C++
      t.join();
      ```
    - Detach thread from main:
      ```C++
      t.detach()
      ```
    - Try if thread can call .join() or .detach():
      ```C++
      t.joinable()
      /* return bool */
      ```
    - Mutex: mutual exclusion, mutex will block other threadings from accessing shared resources.
      ```C++
      std::mutex mtx;
      void function(){
          mtx.lock();
          /* calculations */
          mtx.unlock();
      }
      ```
    - lock_guard: automatically lock or unlock mutex when constructing or destructing:
      ```C++
      std::mutex mtx;
      void function(){
          std::lock_guard<std::mutex> lock(mtx);
          /* calculations */
      }
      ```
    - unique_guard: provide more functions than lock_guard.
    - call_once: ensure a function, like a static funciton, is called only once. This will prevent multiple threads call a function over expectation.
      ```C++
      std::call_once(flag, function);
      ```
      
- Thread Pool: A thread pool is a design pattern and a mechanism used in concurrent programming to manage and reuse a fixed number of threads.
    - Create a group of pre-initialized threads that are ready to perform tasks as needed
    - When a task needs to be executed concurrently, the thread pool assigns (not creating a new one) an available thread from the pool to perform the task. 
    - When a task is completed, the thread is returned to the pool, making it available for other tasks.
    - Reduce the overhead of thread creation and destruction
    - Max amount of threads cannot be greater than the amount of CPUs.

## Consumer and Producer Model with condition variable
    ```Producer_Comsumer_model.cpp``` shows how to build a simple producer - consumer mode threading pool.

## Threading with different input class
1. ```RefVariable.cpp``` shows how to use ref to feed addess reference
2. ```GlobalVariable.cpp``` shows how to feed address reference when both variable and the thread are global.
3. ```ptrVariable.cpp``` shows how to feed pointer and avoid wild pointers
4. ```SharedptrClassInput.cpp``` shows how to feed class public function input with shared pointer.
5 ```friendPrivateInput.cpp``` shows how to feed class private funciton input with friend funciton and shared pointer.
