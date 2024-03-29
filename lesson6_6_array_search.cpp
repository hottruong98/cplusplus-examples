/*Goal: practice searching an array in C++
**There is an array of integers. The length of the arrays to be searched 
**varies. A user will enter an integer and the program will search the array.
**If the value is in the array, the program will return the location of 
**the element. If the value is not in the array, the user will be notified 
**that the value is not in the array. To exit the program the user will enter -1.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int sequentialSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int searchArray[10] = {324, 4567, 6789, 5421345, 7, 65, 8965, 12, 342, 485};
    //use searchKey for the number to be found
    //use location for the array index of the found value
    int searchKey, location;
    int size = sizeof(searchArray) / sizeof(*searchArray);
    //TODO: write code to determine if integers entered by
    //the user are in searchArray
    while (1)
    {
        scanf("%d", &searchKey);
        location = sequentialSearch(searchArray, size, searchKey);

        //Use these commands to give feedback to the user
        if (location != -1)
        {
            std::cout << searchKey << " is at location " << location << " in the array.\n";
        }
        else
        {
            std::cout << searchKey << " is not in the array.\n";
        }
    }
    return 0;
}
