/*Create a class that has four constructors:
* one that accepts no input parameters
* one that accepts name
* one that accepts license number
* one that accepts name and license number
* The default values are:
name = NA
license = 0
*/

#include<iostream>
#include<string>
using namespace std;
class Dog {
  string name;
  int license;
  public: 
  Dog();
  Dog(string name);
  Dog(int license);
  Dog(string name, int license);
  string getName();
  int getLicense();
};
Dog::Dog() {
    name = "NA";
    license = 0;
}
Dog::Dog(string name) {
    this->name=name;
    license = 0;
}
Dog::Dog(int license) {
    name="NA";
    this->license=license;
}
Dog::Dog(string name, int license){
    this->name=name;
    this->license=license;
}
string Dog::getName() {
    return name;
}
int Dog::getLicense() {
    return license;
}
int main(){
    Dog d1;
    Dog d2("Kali");
    Dog d3(12345);
    Dog d4("Sammy", 65432);
    
    cout<<d1.getName()<<" "<<d1.getLicense()<<"\n";
    cout<<d2.getName()<<" "<<d2.getLicense()<<"\n";
    cout<<d3.getName()<<" "<<d3.getLicense()<<"\n";
    cout<<d4.getName()<<" "<<d4.getLicense()<<"\n";
    return 0;
}