/*
  Exception between
    mutex.lock();
    mutex.unlock();
  will cause mutex keep locking
*/
#include <iostream>
#include <thread>
#include <string>

#include <mutex>

using namespace std;

mutex mu;

void shared_print(string msg, int i)
{
  lock_guard<mutex> guard(mu);
  //mu.lock();
  cout << msg << i << endl;
  //mu.unlock();
}

void function_1()
{
  for (int i = 0; i < 10000; i++)
  {
    shared_print("From thread: ", i);
  }
}
int main()
{

  thread t1(function_1);

  for (int i = 0; i < 10000; i++)
  {
    shared_print("From main: ", i);
  }

  t1.join();
  return 0;
}