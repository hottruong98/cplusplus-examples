#include <iostream>
#include <string>

int main() {
  std::string userName;
  std::cout<<"Type in your name: ";
  std::getline(std::cin, userName);
  std::cout<<"Hi "<<userName<<"\n";
  std::cin.get(); //Keep the console open
  return 0;
}
