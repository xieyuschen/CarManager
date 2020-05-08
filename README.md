# whether an extension method or not in Cpp
&emsp;&emsp;[A wonderdul page to read in stackoverflow !](https://stackoverflow.com/questions/5463009/extension-methods-in-c) Here are some excellent paragraphs:    
&emsp;&emsp;Different languages approach development in different ways. In particular C# and Java have a strong point of view with respect to OO that leads to everything is an object mindset (C# is a little more lax here). In that approach, extension methods provide a simple way of extending an existing object or interface to add new features.    
&emsp;&emsp;There are no extension methods in C++, nor are they needed. When developing C++, forget the everything is an object paradigm --which, by the way, is false even in Java/C# . A different mindset is taken in C++, there are objects, and the objects have operations that are inherently part of the object, but there are also other operations that form part of the interface and need not be part of the class. A must read by Herb Sutter is [What's In a Class?](http://www.gotw.ca/publications/mill02.htm), where the author defends (and I agree) that you can easily extend any given class with simple free functions.  

&emsp;&emsp;As a particular simple example, the standard templated class `basic_ostream` has a few member methods to dump the contents of some primitive types, and then it is enhanced with (also templated) free functions that extend that functionality to other types by using the existing public interface. For example,`std::cout << 1; `is implemented as a member function, while `std::cout << "Hi"; `is a free function implemented in terms of other more basic members.  

&emsp;&emsp;**Extensibility in C++ is achieved by means of free functions, not by ways of adding new methods to existing objects**
## So by the way,what's the free function? :)
&emsp;&emsp;The term free function in C++ simply refers to non-member functions. Every function that is not a member function is a free function.


# A Interface Principle
[A worth reading passage about Interface Principle](http://www.gotw.ca/publications/mill02.htm)  
Add some abstracts here about passage's points.  

## 1. What's a class?
>In my mind:
a class is a collection to describe some real world thing, it owns some datas and methods.

So let's look class definition carefully:  
**A class describes a set of data along with the functions that operate on that data.**  
Pay attention to the describes of functions,a function belongs to class as long as function operate on the data.  
### Here is a demo,Does the f belongs to X?
--besides access right, f is not significant different from f as a member function in X.    
```cpp
class X { /*...*/ };

    /*...*/
 void f( const X& );
```

## 2. Interfacec Principle:
>For a class X, all functions, including free functions, that both  
&emsp;&ensp;(a) "mention" X, and  
&emsp;&ensp;(b) are "supplied with" X  
are logically part of X, because they form part of the interface of X.

In short,**if f is supplied in X or mentions  