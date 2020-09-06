
/*
  Deadlock Demo

*/

#include <iostream>
#include <thread>
#include <string>

#include <mutex>

using namespace std;

mutex mu1;
mutex mu2;

void shared_print1(string msg, int i)
{
  lock_guard<mutex> guard1(mu1);
  lock_guard<mutex> guard2(mu2);
  cout << msg << i << endl;
}

void shared_print2(string msg, int i)
{
  lock_guard<mutex> guard2(mu2);
  lock_guard<mutex> guard1(mu1);
  cout << msg << i << endl;
}

void function_1()
{
  for (int i = 0; i < 10000; i++)
  {
    shared_print1("From thread: ", i);
  }
}
int main()
{

  thread t1(function_1);

  for (int i = 0; i < 10000; i++)
  {
    shared_print2("From main: ", i);
  }

  t1.join();
  return 0;
}