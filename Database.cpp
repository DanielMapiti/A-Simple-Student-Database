#include "DbHeader.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct StudentRecords{
    string name;
    string surname;
    string studentNumber;
    string classRecord;
};

vector<StudentRecords> recordList;

void print(string message){
    cout<<"function "<<message<<" called."<<endl;
}
StudentRecords student;
void addStudent(){
    print("addStudent");
    cout<<"Enter the student's details separated by space (name surname studentNumber classRecord): \n";
    //StudentRecords student;
    cin>>student.name;
    cin>>student.surname;
    cin>>student.studentNumber;
    getline(cin, student.classRecord);
    recordList.push_back(student);
    for(int i=0;i<recordList.size();i++){cout<<recordList[i].name<<endl;}
    
}
void readDb(){
    print("readDb");
}
void saveDb(){
    print("saveDb");
}
void dispStudentData(){
    print("dispStudentData");
}
void grade(){
    print("grade");
}