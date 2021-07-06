/*Goal: practice using a class. 
**Create an array called roster, populate it 
**with multiple instances of Dog, it has a size of SIZE. 
**Then create a function called 
**printRoster(roster, SIZE) that will print 
**all the information about all the dogs on the roster.
*/
#include "main.hpp"

int main(){
    int SIZE=2;
    Dog roster[SIZE];
    roster[0].setName("abc");
    roster[0].setLicenseNumber(123);
    roster[1].setName("def");
    roster[1].setLicenseNumber(456);
    printRoster(roster, SIZE);
    return 0;
}