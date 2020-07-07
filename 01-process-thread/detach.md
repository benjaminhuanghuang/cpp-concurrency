

Without calling join() on worker thread, the thread's destructor while be called and cause the program aborts with an error. 

There are some situations, where it might make sense to not wait for a thread to finish its work. This can be achieved by "detaching" the thread, by which the internal state variable "joinable" is set to "false".

The destructor of a detached thread does nothing: It neither blocks nor does it terminate the thread. 
calling thread.detach() causes the main thread to immediately continue until it reaches the end of the program code and returns. 

Note that a detached thread can not be joined ever again.

You have to make sure that the detached thread does not access any data that might get out of scope or be deleted.

