#include <iostream>
#include <thread>
#include <string>

#include <mutex>

using namespace std;

mutex mu1;
mutex mu2;

void function_1()
{
}
int main()
{

  thread t1(function_1);

  t1.join();
  return 0;
}