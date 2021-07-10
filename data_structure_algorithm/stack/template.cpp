#include <iostream>
using namespace std;

template <typename T, typename U>
class Pair {
    T x;
    U y;
    public:
        void setX(T x) {
            this->x = x;
        }
        void setY(U y) {
            this->y = y;
        }
        T getX() {
            return x;
        }
        U getY() {
            return y;
        }
};

int main() {
    Pair<int, int> p1;
    p1.setX(10);
    p1.setY(20);
    cout << "p1.x = " << p1.getX() << endl;
    cout << "p1.y = " << p1.getY() << endl;

    // If we want to create an obj{int x, int y, int z} from class Pair without creating a new class:
    Pair<int, int> temp;
    Pair<Pair<int, int>, int> p2;
    temp.setX(10);
    temp.setY(20);
    p2.setX(temp);
    p2.setY(30);
    cout << "p2.x = " << p2.getX().getX() << endl;
    cout << "p2.y = " << p2.getX().getY() << endl;
    cout << "p2.z = " << p2.getY() << endl;
    return 0;
}