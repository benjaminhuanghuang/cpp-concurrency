

#include <iostream>

using namespace std;

class XMutex
{
public:
  XMutex(mutex &mux) : mux_(mux)
  {
    cout << "Lock" << endl;
    mux_.lock();
  }

  ~XMutex()
  {
    cout << "Lock" << endl;
    mux_.unlock();
  }

private:
  mutex &mux_;
}

void
test(int status)
{
  XMutex lock(mux)

  if (status == 1)
  {
    cout << " = 1" << end;
    return;
  }
  else
  {
    cout << " != 1" << end;
    return;
  }
}

int main()
{
}