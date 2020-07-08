## Create thread
A thread can be created in several ways:
- Using a function pointer
```
void accumulator(const vector<int> &v, long &acm, int start, int end)
{
    acm = 0;
    for (int i = start; i < end; ++i)
    {
        acm += v[i];
    }
}


// create thread
long acm1 = 0;

// Important: All parameters passed to function are passed by value unless you wrap them in std::ref.
thread t1(accumulator, ref(v), ref(acm1), 0, v.size() / 2);

// wait for t1 to finish
t1.join(); 
```
- Using a functor
```
class CAccumulatorFunctor3
{
  public:
    void operator()(const std::vector<int> &v, 
                    unsigned int beginIndex, unsigned int endIndex)
    {
        _acm = 0;
        for (unsigned int i = beginIndex; i < endIndex; ++i)
        {
            _acm += v[i];
        }
    }
    unsigned long long _acm;
};


CAccumulatorFunctor3 accumulator1 = CAccumulatorFunctor3();

```

- Using a lambda function