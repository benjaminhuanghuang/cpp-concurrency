#include <iostream>
#include <thread>
#include <string>

#include <mutex>
#include <future>

using namespace std;


int factorial(shared_future<int> f)
{
  int res = 1;
  int n = f.get();
  for (int i = n; i > 1; i--)
  {
    res *= i;
  }
  
  return res;
}

int main()
{
  promise<int> p;
  future<int> f = p.get_future();

  // shared_future can be copied
  shared_future<int> sf = f.share();
  future<int> fres = async(factorial, sf);   // copy
  future<int> fres2 = async(factorial, sf);   // copy
  future<int> fres3 = async(factorial, sf);   // copy

  p.set_value(4);    // pass data to thread all threads

  int res = fres.get();  // wait working thread 

  cout << "Result is: " << res << endl;
  return 0;
}