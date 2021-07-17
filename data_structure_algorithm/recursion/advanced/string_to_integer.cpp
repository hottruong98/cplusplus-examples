// Input: "12345" => 12345
#include <iostream>
#include <cmath>
using namespace std;

int strToInt(string str) {
    if(str.length() == 0) {
        return 0;
    }
    return (int)(str[0] - 48) * pow(10, str.length() - 1) + strToInt(str.substr(1));
}
int strToInt2(string str, int n) {
    if(n == 0) {
        return 0;
    }
    int smallAns = strToInt2(str, n - 1);
    return smallAns * 10 + (str[n - 1] - '0');
}
int main() {
    string str = "1998";
    cout << strToInt(str) << endl;
    cout << strToInt2(str, str.length()) << endl;
    return 0;
}
