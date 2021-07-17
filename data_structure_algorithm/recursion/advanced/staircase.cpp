// Number of ways to reach N from 0, you can take a jump at 1, 2, 3
// Ex: N = 1 then 1 => 1 way only
// Ex: N = 2 then 2 , 1 1 => 2 ways
// Ex: N = 3 then 3 , 2 1 , 1 2 , 1 1 1 => 4 ways
// Ex: N = 4 then 3 1 , 2 2 , 2 1 1 , 1 3 , 1 2 1 , 1 1 2 , 1 1 1 1 => 7 ways
// Ex: N = 5 then f(5) = f(4) + f(3) + f(2) = 7 + 4 + 2 = 13 ways
// So, we can reach N from N-1, N-2 or N-3 => ways to reach N = sum of ways to reach N-1, N-2, N-3
#include <iostream>
using namespace std;
int staircase(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    if(n == 2) {
        return 2;
    }
    int smallAns_1 = staircase(n - 1); // ways to reach n-1   
    int smallAns_2 = staircase(n - 2); // ways to reach n-2
    int smallAns_3 = staircase(n - 3); // ways to reach n-3
    return smallAns_1 + smallAns_2 + smallAns_3; // ways to reach n 
}
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Number of ways to reach " << n << " : " << staircase(n) << endl;
    return 0;
}