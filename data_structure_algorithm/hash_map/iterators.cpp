#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

int main() {
    unordered_map<string, int> myMap;
    myMap["key 1"] = 59;
    myMap["key 2"] = 23;
    myMap["key 3"] = 89;
    myMap["key 4"] = 71;
    myMap["key 5"] = 73;
    myMap["key 6"] = 41;
    myMap["key 7"] = 97;
    for(unordered_map<string, int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
        cout << "KEY: " << it->first << ", VALUE: " << it->second << endl;
    }
    cout << "--------------\n";
    for(auto it = myMap.begin(); it != myMap.end(); it++) {
        cout << "KEY: " << it->first << ", VALUE: " << it->second << endl;
    }
    cout << "--------------\n";
    unordered_map<string, int>::iterator ptr = myMap.begin();
    for(int i = 0; i < myMap.size(); ptr++, i++) {
        cout << "KEY: " << ptr->first << ", VALUE: " << ptr->second << endl;
    }
    cout << "--------------\n";

    map<string, int> myMap2;
    myMap2["key 1"] = 59;
    myMap2["key 2"] = 23;
    myMap2["key 3"] = 89;
    myMap2["key 4"] = 71;
    myMap2["key 5"] = 73;
    myMap2["key 6"] = 41;
    myMap2["key 7"] = 97;
    for(map<string, int>::iterator it = myMap2.begin(); it != myMap2.end(); it++) {
        cout << "KEY: " << it->first << ", VALUE: " << it->second << endl;
    }
    cout << "--------------\n";

    vector<int> myVec;
    myVec.push_back(59);
    myVec.push_back(23);
    myVec.push_back(89);
    myVec.push_back(71);
    myVec.push_back(73);
    myVec.push_back(41);
    myVec.push_back(97);
    for(vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++) {
        cout << "VALUE: " << *it << endl;
    }
    cout << "--------------\n";

    // Erase a key
    unordered_map<string, int>::iterator it = myMap.find("key 3");
    myMap.erase(it);

    // Check a key using find()
    if(myMap.find("key 3") == myMap.end()) {
        cout << "key 3 is not present" << endl;
    }
    else {
        cout << "key 3 is present" << endl;
    }
    // Check a key using count()
    if(myMap.count("key 4")) {
        cout << "key 4 is present" << endl;
    }
    else {
        cout << "key 4 is not present" << endl;
    }

    // Erase all key in a map
    myMap2.erase(myMap2.begin(), myMap2.end());
    for(auto it2 = myMap2.begin(); it2 != myMap2.end(); it2++) {
        cout << "KEY: " << it2->first << ", VALUE: " << it2->second << endl;
    }
    return 0;
}