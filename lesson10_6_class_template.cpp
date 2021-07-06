#include <iostream>
using namespace std;

template <class T>
class StudentRecord {
    const int size=5;
    T grade;
    int studentId;
    public:
    StudentRecord(T grade);
    void setId(int studentId);
    void printGrade();
};
template <class T>
StudentRecord<T>::StudentRecord(T grade) {
    this->grade=grade;
}
template <class T>
void StudentRecord<T>::setId(int studentId) {
    this->studentId=studentId;
}
template <class T>
void StudentRecord<T>::printGrade() {
    cout<<"ID# "<<studentId<<"\t";
    cout<<grade<<"\n\n";
}

int main() {
    StudentRecord<int> studentA(8);
    studentA.setId(1611201);
    studentA.printGrade();

    StudentRecord<char> studentB('A');
    studentB.setId(1611001);
    studentB.printGrade();

    StudentRecord<string> studentC("B+");
    studentC.setId(1612555);
    studentC.printGrade();
    return 0;
}