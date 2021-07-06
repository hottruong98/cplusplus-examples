### Introduction:
The word polymorphism means having many forms.
### Real-life example:
A person at the same time can have different characteristics. Like a man at the same time is a father, a husband, an employee. So the same person posses different behaviors in different situations.
### Divided into 2 types:
* **Compile time** polymorphism (*Early binding*):
  * Function overloading
  * Operator overloading
* **Runtime**  polymorphism(*Late binding*):
  * Function overriding (achieved by using *virtual function*)
### Why do we call *compile time polymorphism*?
Based on number of arguments or/and type of arguments we pass during function call determines which function is to be called. The call is determined during compile time, that's why it is called compile time polymorphism.
### Why do we call *runtime polymorphism*?
In case of function overriding, we have two definitions of the same function, one in parent class and one in child class. The call to the function is determined at runtime to decide which definition of the function is to be called, that's the reason it is called runtime polymorphism.
### Virtual function:
In the example *virtual_function.cpp*, we will see what are virtual functions and why we use them. When we declare a function as virtual in a class, **all the sub classes** that **override** this function have their function implementation as **virtual by default** (whether they mark them virtual or not). **Why** we declare a function virtual? **To let compiler know** that the call to this function needs to be resolved at runtime (also known as **late binding** and dynamic linking) so that the object type is determined and the correct version of the function is called.
**Note**:
* Never call virtual function during construction or destruction
* Only use it when appropriate - though it's really useful