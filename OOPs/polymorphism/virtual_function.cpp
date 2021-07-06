#include <iostream>
using namespace std;
// Parent/base/super class
class Animal
{
public:
    virtual void animalSound()
    {
        cout << "Animal sound" << endl;
    }
    void averageAge()
    {
        cout << "Average age of animal" << endl;
    }
};
// Child/derived/sub class
class Dog : public Animal
{
public:
    void animalSound() //Although we don't add virtual keyword, this one is actually a virtual function...
                       //...because it overrides the virtual function in the base class (README.md)
    {
        cout << "Gau Gau" << endl;
    }
    void averageAge()
    {
        cout << "10-13 years" << endl;
    }
};
int main()
{
    Dog myDog;
    myDog.animalSound();         //"Gau Gau"
    myDog.averageAge();          //"10-13 years"
    myDog.Animal::animalSound(); //"Animal sound"
    myDog.Animal::averageAge();  //"Average age of animal", we're accessing an overriden function animalSound() of base class

    Animal *obj;
    obj = new Dog();
    obj->animalSound(); //"Gau Gau" (achieved by using virtual function)
    obj->averageAge();  //"Average age of animal" (it calls the function of base class...
                        //...because obj is Animal type, eventhough it point to a Dog obj)

    Dog strayDog;
    Animal *ptrAnimal = &strayDog;
    Dog *ptrDog = &strayDog;
    ptrAnimal->animalSound(); //"Gau Gau", b/c of virtual function
    ptrDog->animalSound();    //"Gau Gau"
    ptrAnimal->averageAge();  //"Average age of animal", like the obj->averageAge(); examples
    ptrDog->averageAge();     //"10-13 years"

    return 0;
}