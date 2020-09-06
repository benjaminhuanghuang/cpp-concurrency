
/*
  Thread can not be copied like
  thread t2 = t1;
*/

#include <iostream>
#include <string>
#include <thread>

using namespace std;

class Fctor
{
public:
  void operator()(string msg)        // Complier will complain when use string& msg here
  {
    cout << "t1 says: " << msg << endl;

    msg = "The string in thread";
  }
};

int main()
{
  string s = "The string in main";

  thread t1((Fctor()), move(s)); // start t1


  // Error! Thread can not be copied
  // thread t2 = t1;
  thread t2 = move(t1);
  t2.join();

  cout << s << endl;

  return 0;
}
