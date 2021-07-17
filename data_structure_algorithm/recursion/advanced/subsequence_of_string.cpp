// Input : abc  => "", "a", "b", "c", "ab", "bc", "ac", "abc"
// Input : aaa  => "", "a", "aa", "aaa"
// Input : aabc => "" "aab" "aa" "aac" "bc" "b" "abc" "aabc" "ab" "ac" "a" "c" 
#include <iostream>
#include <vector>
using namespace std;
void printSubsequence(const string input, string output) {
    if(input.length() == 0) {
        cout << output << " ";
        return;
    }
    // 1st choice: exclude char by passing the sub string
    printSubsequence(input.substr(1), output); 
    // 2nd choice: include char and call recursion on the sub string
    printSubsequence(input.substr(1), output + input[0]); 
}
void printSub(const char input[], char output[], int i) {
    if(input[0] == '\0') {
        output[i] = '\0';
        //cout << output << endl;
        return;
    }
    // Excluding
    printSub(input + 1, output, i);
    // Including
    cout << "output[" << i << "] = " << input[0] << endl;
    output[i] = input[0];
    printSub(input + 1, output, i + 1);
}
// Store subsequence in a vector
void saveSubsequence(string input, string output, vector<string>* sub) {
    if(input.length() == 0) {
        sub->push_back(output);
        return;
    }
    saveSubsequence(input.substr(1), output, sub);
    saveSubsequence(input.substr(1), output + input[0], sub);
}
int main() {
    string input = "abc";
    string output = "";
    cout << "Subsequence: ";
    printSubsequence(input, output);
    char input_2[] = "abc";
    char output_2[100] = "";
    // printSub(input_2, output_2, 0);
    // cout << output_2 << endl;
    vector<string> v;
    saveSubsequence(input, output, &v);
    cout << "\nSubsequence: ";
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    return 0;
}
