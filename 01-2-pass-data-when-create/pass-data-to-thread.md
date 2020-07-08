# Pass data to thread

## Use the funciton object

Pass arguments in to the thread function by packaging them in a class using the function call operator.

```
class Vehicle
{
  public:
    Vehicle(int id) : _id(id) {}
    void operator()()
    {
        std::cout << "Vehicle #" << _id << " has been created" << std::endl;
    }

  private:
    int _id;
};


std::thread t = std::thread(Vehicle(1)); // Use copy initialization
```

## Lambda
We can use a Lambda that captures the arguments and then calls the function.
```
  // starting a first thread (by reference)
  auto f0 = [&id]() {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      std::cout << "a) ID in Thread (call-by-reference) = " << id << std::endl;
  };

  std::thread t1(f0);
```
We can use lambda pass arguemnt to thread by reference.

when the data to which the reference refers changes before the thread is executed, those changes will be visible to the thread. 

## variadic-template
Allow the definition of funcitons that take a **varying number of arguments**.

We can use them to pass several arguments to a thread.

That is possible because the thread constructor is a variadic template that takes multiple arguments.

Before C++11, classes and functions could only accept a fixed number of arguments, which had to be specified during the first declaration. 

With variadic templates it is possible to include any number of arguments of any type.


There is one more difference between calling a function directly and passing it to a thread: 
- calling a function, arguments may be passed by value, by reference or by using move semantics - depending on the signature of the function. When calling a function using a variadic template, the arguments are by default either moved or copied - depending on wether they are rvalues or lvalues. 

## Starting Threads with Member Functions
the object v1 is passed to the thread function by value, thus a copy is made which does not affect the „original“ living in the main thread.

The second object v2 is instead passed by reference. Therefore, changes to its _id variable will also be visible in the main thread

```
  std::thread t1 = std::thread(&Vehicle::addID, v1, 1); // call member function on object v

  std::thread t2 = std::thread(&Vehicle::addID, &v2, 2); // call member function on object v
```

use a heap-allocated object and a reference-counted pointer such as std::shared_ptr<Vehicle> to ensure that the object lives as long as it takes the thread to finish its work.

```
    // create thread
    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t = std::thread(&Vehicle::addID, v, 1); // call member function on object v
```



