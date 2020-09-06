#include <iostream>
#include <thread>
#include <string>

#include <mutex>

using namespace std;

mutex mu;
condition_variable cond;

void factorial(int n, int &x)
{
  int res = 1;
  for (int i = n; i > 1; i--)
  {
    res *= i;
  }
  
  x = res;
}

int main()
{

  int res;
  thread t1(factorial, 4, ref(res));

  t1.join();

  cout << "Result is: " << res << endl;
  return 0;
}