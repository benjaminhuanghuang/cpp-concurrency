/*
 Threads that waste CPU cycles
  
  getpid()  get process id
  
  std::this_thread::get_id()   get thread id
  
  std::thread::id   id 
*/
#include <thread>
#include <chrono>
#include <unistd.h>

// a simple function that wastes CPU cycles "forever"
void cpu_waster() {
    printf("CPU Waster Process ID: %d\n", getpid());

    std::thread::id curr_thead_id = std::this_thread::get_id();
    printf("CPU Waster Thread ID %d\n", curr_thead_id);
    while(true) continue;
}

int main() {
    printf("Main Process ID: %d\n", getpid());
    
    std::thread::id main_thread_id = std::this_thread::get_id();
    printf("Main Thread ID: %d\n", main_thread_id);
    
    std::thread thread1(cpu_waster);
    std::thread thread2(cpu_waster); 

    while(true) { // keep the main thread alive "forever"
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}