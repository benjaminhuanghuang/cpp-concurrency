#include <iostream>
#include <thread>
#include <string>

#include <mutex>
#include <future>

using namespace std;


int factorial(future<int> &f)
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

  future<int> fres = async(factorial, ref(f));

  p.set_value(4);    // pass data to thread

  int res = fres.get();  // wait working thread 

  cout << "Result is: " << res << endl;
  return 0;
}