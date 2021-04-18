#include <thread>
#include <future>
#include <string>
#include <iostream>

using namespace std;

void test_fugure(promise<string> p)
{
  cout << "begin test_future" << endl;
  this_thread::sleep_for(1s);

  cout << "begin set value" << endl;

  p.set_value("Test Future value");

  this_thread::sleep_for(1s);

  cout << "begin set value" << endl;
}

int main()
{
  promise<string> p;

  future<string> ftr = p.get_future();


  thread t = thread(test_fugure, move(p));

  cout << "future get()=" << ftr.get() << endl;
  
  t.join();
}