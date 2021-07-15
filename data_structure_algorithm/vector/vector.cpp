#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> *vp = new vector<int>(); // Dynamic
    vector<int> v; // Static
    vector<int> v2(10); // Optional size
    vector<int> v3(10, -2); // first 10 elements with value -2
    v.push_back(1998);
    cout << v.capacity() << endl;
    cout << v3.capacity() << endl;
    v3.push_back(-3);
    cout << v3.capacity() << endl;
    cout << v3.size() << endl;
    cout << v3.at(0) << endl;
    cout << v3[0] << endl;
    sort(v3.begin(), v3.end());
    cout << v3.at(0) << endl;
    return 0;
}