#include <iostream>
#include <thread>
#include <string>

#include <mutex>
#include <future>

using namespace std;


int factorial(int n)
{
  int res = 1;
  for (int i = n; i > 1; i--)
  {
    res *= i;
  }
  
  return res;
}

int main()
{
  // async(launch:: async || launch:: deferred )
  future<int> fu = async(factorial, 4);

  int res = fu.get();  // wait working thread 

  cout << "Result is: " << res << endl;
  return 0;
}