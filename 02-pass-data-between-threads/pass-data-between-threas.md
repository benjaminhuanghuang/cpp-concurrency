## promise and future
private channel between two threads that can be used only a single time.

We can have channel to pass data from a worker thread to the parent thread.

In the channel between the threads, the sending end is promise, while the receiving end is future.

The channel can be used to pass data as well as exception from worker thread to parent thread.

## Threads and Tasks
Tasks are some high-level concept where the system can choose whether to execute some code in parallel or synchronously

## move semantics (C++11)
- pass data by value
- avoid unnessary copies 
- avoid dangers of passing by reference







