#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> myMap;

    // Insert:
    // 1st way:
    pair<string, int> p("abc", 1);
    myMap.insert(p);
    // 2nd way: (more preferable)
    myMap["def"] = 2;
    cout << "Size of map = " << myMap.size() << endl;

    // Access:
    cout << myMap["abc"] << endl;
    cout << myMap.at("abc") << endl;
    // cout << myMap.at("ghi") << endl; // will throw exception
    cout << myMap["ghi"] << endl; // will insert new element with default value 0
    cout << "Size of map = " << myMap.size() << endl;

    // Check presence of a key:
    if(myMap.count("ghi")) {
        cout << "ghi is present" << endl;
    }
    else {
        cout << "ghi is not present" << endl;
    }

    // Update:
    myMap["abc"] = 99;

    // Erase:
    myMap.erase("ghi");
    cout << "Size of map = " << myMap.size() << endl;
    
    // Check presence of a key:
    if(myMap.count("ghi")) {
        cout << "ghi is present" << endl;
    }
    else {
        cout << "ghi is not present" << endl;
    }
    
    return 0;
}