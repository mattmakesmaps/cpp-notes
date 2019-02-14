# cpp-notes

A rolling list of C++ keyword definitions and examples that I've
found to be useful.

## Links By CPP Keyword

### Explicit

> Specifies that a constructor or conversion function (since C++11)
> is explicit, that is, it cannot be used for implicit conversions 
> and copy-initialization.

- Well commented example here: https://en.cppreference.com/w/cpp/language/explicit

### Final

> Specifies that a virtual function cannot be overridden in a derived
> class or that a class cannot be inherited from.

- See: https://en.cppreference.com/w/cpp/language/final

### Override

> Specifies that a virtual function overrides another virtual function.

- See: https://en.cppreference.com/w/cpp/language/override

### Virtual

> A virtual function a member function which is declared within
> base class and is re-defined (Overriden) by derived class. When you
> refer to a derived class object using a pointer or a reference to
> the base class, you can call a virtual function for that object
> and execute the derived class’s version of the function.

- See: https://www.geeksforgeeks.org/virtual-function-cpp/

## Links By Topic

### CMake

- [Jetbrains CLion - Quick CMake Tutorial](https://www.jetbrains.com/help/clion/quick-cmake-tutorial.html)

### Threading

- [University of Chicago - Concurrency in C++ 11](https://www.classes.cs.uchicago.edu/archive/2013/spring/12300-1/labs/lab6/)
- [University of Chicago - Concurrency in C++ 11 Github Examples](https://github.com/uchicago-cs/cmsc12300/tree/master/examples/cpp/concurrency/simple)
- [Lawrence Livermore National Laboratory - POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)
- [Modernes CPP - Condition Variables](http://www.modernescpp.com/index.php/condition-variables)

### Smart Pointers

- [Intro to Smart Pointers](https://en.cppreference.com/book/intro/smart_pointers): 
  Check the `shared_ptr` section for a very good practical example of using `shared_ptr` with/outside of a class.
- [LESSON #4: SMART POINTERS](https://mbevin.wordpress.com/2012/11/18/smart-pointers/)
- [Classes With Pointer Data Members](http://pages.cs.wisc.edu/~hasti/cs368/CppTutorial/NOTES/CLASSES-PTRS.html)

### Pimpl

### RAII

### Unsorted

- [Copy constructors, assignment operators, and exception safe assignment](http://www.cplusplus.com/articles/y8hv0pDG/)
