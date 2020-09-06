#include <iostream>

#include <deque>
#include <string>
//
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mu;
deque<int> q;
condition_variable cond;

void function_1()
{
  int count = 0;
  while (count > 0)
  {
    unique_lock<mutex> locker(mu);
    q.push_back(count);
    locker.unlock();
    cond.notify_one(); //
    count--;
  }
}

void function_2()
{
  int data = 0;
  while (data != 1)
  {
    unique_lock<mutex> locker(mu);
    cond.wait(locker, []() { return !q.empty(); });
    data = q.back();
    q.pop_back();
    locker.unlock();
  }
}

int main()
{

  thread t1(function_1);
  thread t2(function_2);

  t1.join();
  t2.join();
  return 0;
}