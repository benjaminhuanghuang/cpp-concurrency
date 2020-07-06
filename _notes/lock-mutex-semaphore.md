mutex是用作互斥的，而semaphore是用作同步的。 

mutex的初始化一定是为1，而semaphore可以是任意的数， ... 同时mutex和semaphore还有一个区别是，获得mutex的进程必须亲自释放它，而semaphore则可以一个进程获得，另一个进程释放