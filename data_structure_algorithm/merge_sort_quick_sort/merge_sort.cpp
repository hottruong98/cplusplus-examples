#include <iostream>
using namespace std;

void merge(int *arr, int left, int right)
{
    cout<<"left and right = ["<<left<<","<<right<<"]\n";
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    int k = left;
    //int* temp = new int[right - left + 1];
    int* temp = new int[10];
    //int temp[100];
    cout<<right - left + 1<<"\n";

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
    //Copy all elements to the original array
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    // cout<<"temp = "<<temp[0]<<"\t"<<temp[1]<<"\t"<<temp[2]<<"\t"<<temp[3]<<"\t"<<temp[4]<<"\t"<<temp[5]<<"\t"<<temp[6]<<endl;
    delete[] temp;
}

void mergeSort(int arr[], int left, int right)
{
    //Base case: 0 and 1 element
    if (left >= right)
    {
        return;
    }
    //1. Divide
    int mid = (left + right) / 2;
    //2. Recursion [left,...,mid] and [mid+1,...,right]
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    //3. Merge the 2 parts
    merge(arr, left, right);
}

int main()
{
    int a[] = {7, 3, 10, 5, 6, 2, -5};
    mergeSort(a, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << "\t";
    }
    return 0;
}