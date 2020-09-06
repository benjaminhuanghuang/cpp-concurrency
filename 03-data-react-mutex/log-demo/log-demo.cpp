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
    f.open("log.txt");
  }
  void shared_print(string id, int val)
  {
    lock_guard<mutex> guard(_mutex);
    f << "From " << id << ": " << val << endl;
  }

private:
  mutex _mutex;
  ofstream f;
};

void function_1(LogFile & log)
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