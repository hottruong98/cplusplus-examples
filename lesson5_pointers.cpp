#include <iostream>
#include <cstdio>
#include <cstring>
#define LOG(x) std::cout << x << std::endl

int main() {
  /* Working with stack */
  // int var = 6;
  // int* ptr = &var;
  // *ptr = 98;
  // LOG(var);

  /* Working with heap */
  //What we're asking for is 8 bytes of memory. So this has allocated 8 bytes of memory
  //for us and is returning a pointer to the begining of that block of memory
  char* buffer = new char[8];
  memset(buffer, 0, 8); //fill a block of memory with data that we specify

  *buffer = 6;
  
  char** ptr = &buffer; //pointer to pointer

  delete[] buffer;
  std::cin.get();
  return 0;
}
