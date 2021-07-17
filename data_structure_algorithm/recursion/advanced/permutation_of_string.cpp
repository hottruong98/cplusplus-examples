// In mathematics, a permutation of a set is, loosely speaking,...
// an arrangement of its members into a sequence or linear order.
// Input: ABC => ABC, ACB, BAC, BCA, CAB, CBA (3! = 3x2x1 = 6)
// String with n characters => n recursive cases
#include <iostream>
#include <vector>
using namespace std;

void permutation(string str, string output, vector<string> &v) {
    // Base case
    if(str.length() == 0) {
        cout << output << endl;
        v.push_back(output);
        return;
    }
    // N characters => N recursive cases
    for(int i = 0; i < str.length(); i++) {
        // First, fix the character[i] -> add the output string
        char temp = str[0];
        str[0] = str[i];
        str[i] = temp;
        // Then, call the recursion on the smaller array
        permutation(str.substr(1), output + str[0], v);
    }
}

int main() {
    string str = "ABCD";
    string output = "";
    vector<string> v;
    permutation(str, output, v);
    cout << v.size() << endl;
    return 0;
}

