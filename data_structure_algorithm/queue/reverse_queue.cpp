#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template <typename T>
void reverse(queue<T> &q) {
    stack<T> s;
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}
int main() {
    queue<int> q;
    for(int i=0; i<5; i++) {
        q.push(i);
    }
    reverse(q);
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}