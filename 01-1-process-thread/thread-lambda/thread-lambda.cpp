#include <iostream>
#include <thread>

int main()
{
    std::thread t([](){
        std::cout << "thread function\n";
    });

    std::cout << "main thread\n";
    //makes the current thread wait until the thread t has finished executing.
    t.join();
    return 0;
}