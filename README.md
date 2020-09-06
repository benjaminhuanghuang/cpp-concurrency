# Cpp Concurrent Programming


## Key points
- System thread, process information, CPU count

- Create thread using funciton, functor, lambda

- join() and detach()

- Pass data to thread when creating

- Data race and Mutex / lock_gard / unique_lock
  exception will cause mutex keep locking


- once_flag / call_once


- condition_variable
  避免无效的loop

- Pass data from sub-thread to parent thread: future / promise

  future / promise 只能move， 不能copy
  shared_future can be copied



