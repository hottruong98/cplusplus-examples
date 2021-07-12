#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.size() << endl;
    cout << s.empty() << endl;

    stack<int> s2;
    for(int i=0; i<10; i++) {
        s2.push(i);
    }
    while(!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    return 0;
}