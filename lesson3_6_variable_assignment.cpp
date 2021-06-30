#include <iostream>
using namespace std;
int main() {
  char charA = 'A';
  char charB = 66;
  int intNumber = 98;
  float floatNumber = 4.05;

  //The size of datatype
  cout<<"sizeof(char) = "<<sizeof(char)<<"\n";
  cout<<"sizeof(int) = "<<sizeof(int)<<"\n";
  cout<<"sizeof(float) = "<<sizeof(float)<<"\n";

  //assign char to float --> answer = value of char in float datatype
  floatNumber = charA;
  cout<<"floatNumber = charA = "<<floatNumber<<"\n";

  //assign integer to float --> answer = value of integer number in float datatype
  floatNumber = intNumber;
  cout<<"floatNumber = intNumber = "<<floatNumber<<"\n";

  //assign float to char --> won't work if the value of float isn't in the ASCII
  charA = floatNumber/3;
  cout<<"charA = "<<charA<<"\t floatNumber/3 = "<<floatNumber/3<<"\n";

  //assign float to integer --> truncated
  intNumber = floatNumber/3;
  cout<<"intNumber = "<<intNumber<<"\t floatNumber/3 = "<<floatNumber/3<<"\n";

  cin.get();
  return 0;
}