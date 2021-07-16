// Palindrome = a word, phrase, or sequence that reads the same backward as forward
// e.g., "madam" or "nurses run" or " 1 2 2 1" ...
// Given a[] = {1, 2, 2, 1} => isPalindrome(a) returns true
#include <iostream>
#include <algorithm> // For std::remove() function
using namespace std;
template <typename T>
bool isPalindrome(const T *arr, int size) {
    if(size == 0 || size == 1) {
        return true;
    }
    // cout << arr[0] << " " << arr[size - 1] << endl;
    if(arr[0] == arr[size - 1]) {
        return isPalindrome(arr + 1, size - 2); // 2 base cases, 2 jumps
    }
    else {
        return false;
    }
}

template <typename T>
bool isPalindrome2(const T *arr, int left, int right) {
    if(left > right) {
        return true;
    }
    if(arr[left] == arr[right]) {
        return isPalindrome2(arr, left + 1, right -1);
    }
    else {
        return false;
    }
}
int main() {
    int A[] = {1, 1, 2, 1};
    int B[] = {5, 6, 0, 0, 1, 0, 0, 6, 5};
    int C[] = {5, 6, 0, 0, 1, 0, 0, 6, 5};
    cout << "Is A a palindrome? " << isPalindrome(A, sizeof(A)/sizeof(int)) << endl;
    cout << "Is B a palindrome? " << isPalindrome(B, sizeof(B)/sizeof(int)) << endl;
    cout << "Is C a palindrome? " << isPalindrome2(C, 0, sizeof(C)/sizeof(int) - 1) << endl;
    
    string strA = "madam";
    string strB = "nurses run";
    char strC[] = "dad";
    // Remove spaces in string
    std::string::iterator end_pos = std::remove(strB.begin(), strB.end(), ' ');
    cout << strB << endl; // strB = "nursesrunn"
    strB.erase(end_pos, strB.end());
    cout << strB << endl; // strB = "nursesrun"
    cout << "Is strA a palindrome? " << isPalindrome(&strA[0], strA.length()) << endl;
    cout << "Is strB a palindrome? " << isPalindrome(&strB[0], strB.length()) << endl;
    cout << "Is strC a palindrome? " << isPalindrome(strC, (sizeof(strC) - 1)/sizeof(char)) << endl; 
    // sizeof("abc") also includes NUll value => number of char = [sizeof() - 1]
    return 0;
}