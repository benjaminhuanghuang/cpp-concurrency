/*
There is one more difference between calling a function directly and passing it to a thread: 
With the former, arguments may be passed by value, by reference or by using move 
semantics - depending on the signature of the function. 

When calling a function using a variadic template, the arguments are by default either 
moved or copied - depending on wether they are rvalues or lvalues. 

There are ways however which allow us to overwrite this behavior. 
If you want to move an lvalue for example, we can call std::move. In the following example, 
two threads are started, each with a different string as a parameter. With t1, the string 
name1 is copied by value, which allows us to print name1 even after join has been called. 

The second string name2 is passed to the thread function using move semantics, which means 
that it is not available any more after join has been called on t2.
*/

#include <iostream>
#include <thread>
#include <string>

void printID(int id)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "ID = " << id << std::endl;
    
}

void printIDAndName(int id, std::string name)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "ID = " << id << ", name = " << name << std::endl;
}

int main()
{
    int id = 0; // Define an integer variable

    // starting threads using variadic templates
    std::thread t1(printID, id);
    std::thread t2(printIDAndName, ++id, "MyString");
    std::thread t3(printIDAndName, ++id); // this procudes a compiler error

    // wait for threads before returning
    t1.join();
    t2.join();
    //t3.join();


    return 0;
}