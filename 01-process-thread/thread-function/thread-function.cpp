/*
    Demo the std::thread in C++ 11
*/
#include <iostream>
#include <thread>

void thread_function()
{
    for (int i = 0; i < 10000; i++)
        ;
    std::cout << "thread function Executing" << std::endl;
}

void thread_function2(int i)
{
    for (int i = 0; i < 10000; i++)
        ;
    std::cout << "thread function2 Executing" << std::endl;
    std::cout << "value = " << i << std::endl;
}

int main()
{
    std::thread threadObj(thread_function);
    for (int i = 0; i < 10000; i++)
        ;

    std::thread t2{thread_function2, 100};

    std::cout << "Display From MainThread" << std::endl;

    threadObj.join();
    t2.join();
    std::cout << "Exit of Main function" << std::endl;
    return 0;
}