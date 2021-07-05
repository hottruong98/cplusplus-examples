#include <iostream>

class Dog
{
    int license;

public:
    Dog(); //Declare constructor
    Dog(int licenseIn);
    void setLicense(int licenseIn);
    int getLicense();
    ~Dog(); //Declare destructor
};

Dog::Dog()
{
    license = 0;
}
Dog::~Dog()
{
    std::cout << "\nDeleting the dog";
}
Dog::Dog(int licenseIn)
{
    license = licenseIn;
}
void Dog::setLicense(int licenseIn)
{
    license = licenseIn;
}
int Dog::getLicense()
{
    return license;
}

int main()
{
    Dog myDog(1998);
    std::cout << myDog.getLicense();
    std::cout<<"\nWhen will the contructor be called?";
    return 0;
}