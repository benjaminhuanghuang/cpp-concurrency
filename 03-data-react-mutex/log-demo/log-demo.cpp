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
#include <fstream>

using namespace std;

class LogFile
{
public:
  LogFile()
  {
  }
  void shared_print(string id, int val)
  {
    call_once(_flag, [&](){f.open("log.txt");});

    lock_guard<mutex> guard(_mutex);
    f << "From " << id << ": " << val << endl;
  }

private:
  mutex _mutex;
  once_flag _flag;

  ofstream f;
};

void function_1(LogFile &log)
{
  for (int i = 0; i < 10000; i++)
  {
    log.shared_print("From thread: ", i);
  }
}
int main()
{
  LogFile log;
  // C++ pass parameter to thread by value, so have to use std::ref() here
  thread t1(function_1, ref(log));

  for (int i = 0; i < 10000; i++)
  {
    log.shared_print("From main: ", i);
  }

  t1.join();
  return 0;
}