/*Goal: Practice array manipulation in C++. 
**The user will input 40 integers. 
**Put them into an array. Then print the array in the order the numbers were
**entered. Then print in reverse order. Then sort the array in ascending order 
**and print it. 
**The each print of the array should separate the numbers in the array by
**one space. 
**For example: the array were [3,4,55] the printout would be 3 4 55
*/

#include <iostream>
#include <stdio.h>
using namespace std;

void merge(int *arr, int left, int right)
{
    int mid = (left + right) / 2;

    int i = left;
    int j = mid + 1;
    int k = 0;

    int *temp = new int[right - left + 1];

    while (i <= mid && j <= right)
    {
        temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    i = left;
    for (int k = 0; k < right - left + 1; k++)
    {
        arr[i++] = temp[k];
    }
    delete[] temp;
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, right);
}
int main()
{
    int userInput[40];
    for (int i = 0; i < 40; i++)
    {
        cin >> userInput[i];
    }
    cout << "\nInput order: ";
    for (int i = 0; i < 40; i++)
    {
        cout << userInput[i] << " ";
    }
    cout << "\nReverse order: ";
    for (int i = 39; i >= 0; i--)
    {
        cout << userInput[i] << " ";
    }
    cout << "\nAcsending order: ";
    mergeSort(userInput, 0, 39);
    for (int i = 0; i < 40; i++)
    {
        cout << userInput[i] << " ";
    }
    return 0;
}