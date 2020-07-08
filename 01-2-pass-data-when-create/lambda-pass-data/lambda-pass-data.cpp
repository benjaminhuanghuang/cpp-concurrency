#include <iostream>
#include <thread>

/*
  c) ID in Main (call-by-value) = 1
  b) ID in Thread (call-by-value) = 0
  a) ID in Thread (call-by-reference) = 1


  when the data to which the reference refers changes before the thread is executed, those changes will be visible to the thread. 
*/
int main()
{
  int id = 0; // Define an integer variable

  // starting a first thread (by reference)
  auto f0 = [&id]() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // when the data to which the reference refers changes before the thread is executed, those changes will be visible to the thread.
    std::cout << "a) ID in Thread (call-by-reference) = " << id << std::endl;
  };
  std::thread t1(f0); // t1 starts after id was changed!

  // starting a second thread (by value)
  std::thread t2([id]() mutable {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "b) ID in Thread (call-by-value) = " << id << std::endl;
  });

  // increment and print id in main
  ++id;
  std::cout << "c) ID in Main (call-by-value) = " << id << std::endl;

  // wait for threads before returning
  t1.join();
  t2.join();

  return 0;
}