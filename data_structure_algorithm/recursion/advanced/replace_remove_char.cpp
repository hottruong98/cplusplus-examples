// 1. Replace character in an array
// 2. Remove character in an array
#include <iostream>
using namespace std;
void replaceChar(char *arr, char oldCharacter, char newCharacter) {
    if(*arr == '\0') {
        return;
    }
    if(*arr == oldCharacter) {
        *arr = newCharacter;
    }
    replaceChar(arr + 1, oldCharacter, newCharacter);
}
int countChar(const char *arr, char character) {
    if(*arr == '\0') {
        return 0;
    }
    if(*arr == character) {
        return 1 + countChar(arr + 1, character);
    }
    else {
        return countChar(arr + 1, character);
    }
}
void removeChar(char *arr, char character) {
    if(arr[0] == '\0') {
        return;
    }
    if(arr[0] == character) {
        for(int i=0; arr[i] != '\0'; i++) { // remove = shift to left
            arr[i] = arr[i+1];
        }
        removeChar(arr, character);
    }
    else {
        removeChar(arr + 1, character);
    }
}
int main() {
    char arr[] = "recursion";
    replaceChar(arr, 'r', '*');
    cout << arr << endl;
    removeChar(arr, '*');
    cout << arr << endl;
    return 0;
}