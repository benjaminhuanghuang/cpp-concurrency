#include <iostream>
#include <thread>

void threadFunction()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // simulate work
  std::cout << "Finished work in thread\n";   // can not see this message
}

int main()
{
  // create thread
  std::thread t(threadFunction);

  // detach thread and continue with main
  /*
    Tell os not wait for a thread to finish its work. 
    This can be achieved by "detaching" the thread, by which the internal state variable "joinable" is set to "false".
  */
  t.detach();

  // do something in main()
  std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
  std::cout << "Finished work in main\n";

  return 0;
}