#include <iostream>
#include <thread>
#include <unistd.h> // for getpid() from the POSIX library.

int main()
{
  printf("The Process ID: %d\n", getpid());

  std::thread::id main_thread_id = std::this_thread::get_id();
  std::cout << "Hello concurrent world from main! Thread id = " << main_thread_id << std::endl;

  unsigned int nCores = std::thread::hardware_concurrency();
  std::cout << "This machine supports concurrency with " << nCores << " cores available" << std::endl;

  return 0;
}