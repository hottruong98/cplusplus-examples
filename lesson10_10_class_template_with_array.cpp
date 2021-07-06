// To deal with the array issue in genetic class:
// Use a constructor to allocate memory for the array. Set a default value to each element in the array.
// Now the compiler can properly allocate memory for the array.

#include <iostream>
using namespace std;
const int SIZE=5;

template <class T>
class StudentRecord {
    const int size=SIZE;
    T grade[SIZE];
    int studentId;
    public:
    StudentRecord(T grade);//A default constructor with a default value
    void setGrade(T* grade);
    void setId(int studentId);
    void printGrade();
};
template <class T>
StudentRecord<T>::StudentRecord(T grade) {
    //TODO: allocate memory for the array
    //by assigning a default value to each
    //array element.
    for (int i=0; i<SIZE; i++) {
        this->grade[i]=grade;
    }
}
template <class T>
void StudentRecord<T>::setGrade(T* grade) {
    for(int i=0; i<SIZE; i++) {
        this->grade[i]=grade[i];
    }
}
template <class T>
void StudentRecord<T>::setId(int studentId) {
    this->studentId=studentId;
}
template <class T>
void StudentRecord<T>::printGrade() {
    cout<<"ID# "<<studentId<<"\t";
    for(int i=0; i<SIZE; i++) {
        cout<<grade[i]<<"\t";
    }
    cout<<"\n";
}

int main() {
    StudentRecord<int> studentA(8);
    studentA.setId(1611201);
    int gradeA[SIZE]={9,7,8,8,8};
    studentA.setGrade(gradeA);
    studentA.printGrade();

    StudentRecord<char> studentB('A');
    studentB.setId(1611001);
    char gradeB[SIZE]={'B','B','A','B','A'};
    studentB.setGrade(gradeB);
    studentB.printGrade();

    StudentRecord<string> studentC("B+");
    studentC.setId(1612555);
    string gradeC[SIZE]={"A","B+","A","A-","A"};
    studentC.setGrade(gradeC);
    studentC.printGrade();
    return 0;
}