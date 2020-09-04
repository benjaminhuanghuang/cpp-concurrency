## promise and future
private channel between two threads that can be used only a single time.

We can have channel to pass data from a worker thread to the parent thread.

In the channel between the threads, the sending end is promise, while the receiving end is future.

The channel can be used to pass data as well as exception from worker thread to parent thread.

## Threads and Tasks
Tasks are some high-level concept where the system can choose whether to execute some code in parallel or synchronously

promise-future 的缺点是使用rvalue引用和std :: move将promise传递给线程函数非常麻烦, 并且涉及很多样板代码。 
相比std::thread，使用std::async()可以更方便的将data或Exception从工作线程返回到父线程
```
  std::future<double> ftr = std::async(std::launch::deferred, divideByNumber, num, denom);
``` 
std::thread和std::async之间的主要区别之一是，对于std::async，系统决定是否应以异步方式或同步方式运行关联的函数。
通过调整std::async的启动参数，我们可以直接影响相关的线程函数是同步还是异步执行。


## move semantics (C++11)
- pass data by value
- avoid unnessary copies 
- avoid dangers of passing by reference







