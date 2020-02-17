#include "DbHeader.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
    ofstream myfile;
    myfile.open("RecordsFile.txt");
    myfile<<recordList[0].name;
    myfile.close();
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