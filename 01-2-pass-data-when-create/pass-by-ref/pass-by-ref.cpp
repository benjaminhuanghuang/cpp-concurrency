
/*
  Pass data to thread as reference is sort of method to share data between
  main() and thread.

  


*/

#include <iostream>
#include <string>
#include <thread>

using namespace std;

class Fctor
{
public:
  void operator()(string& msg)
  {
    cout << "t1 says: " << msg << endl;

    msg = "The string in thread";
  }
};

int main()
{
  string s = "The string in main";

  /*
    The paramter is passed to thread by value!! You have to use std::ref()
  */
  thread t1((Fctor()), ref(s)); // start t1

  t1.join();

  cout << s << endl;

  return 0;
}
