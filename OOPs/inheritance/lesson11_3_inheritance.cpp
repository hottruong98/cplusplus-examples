#include <iostream>
using namespace std;

class Flower {
    string bloomTime;
    public:
    Flower();
    void setBloomTime(string bloomTime);
    string getBloomTime();
};
Flower::Flower() {
    bloomTime="summer";
}
void Flower::setBloomTime(string bloomTime) {
    this->bloomTime=bloomTime;
}
string Flower::getBloomTime() {
    return bloomTime;
}

class Rose: public Flower {
    string fragrance;
    public:
    Rose();
    void setFragrance(string fragrance);
    string getFragrance();
};
Rose::Rose() {
    fragrance="weak";
}
void Rose::setFragrance(string fragrance) {
    this->fragrance=fragrance;
}
string Rose::getFragrance() {
    return fragrance;
}

int main() {
    Rose r1;
    r1.setBloomTime("spring");
    r1.setFragrance("strong");
    cout<<"r1 blooms in "<<r1.getBloomTime()<<", "<<r1.getFragrance();
    return 0;
}
