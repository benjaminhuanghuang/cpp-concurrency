#include <iostream>
#include <thread>

void threadFunction()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // simulate work
  std::cout << "Finished work in thread\n";
}

int main()
{
  // create thread
  std::thread t(threadFunction);

  // do something in main()
  std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
  std::cout << "Finished work in main\n";

  /*
    When the main thread finished, the program will terminate and the resources of 
    the associated process will be freed by the OS. 
    
    As the worker thread exists within the process, it can no longer access those 
    resources and finish with error.

    To prevent that issue, use t.join() to  wait for thread t to finish
    Without t.join() there will be an error when process terminated
  */
  t.join();

  return 0;
}