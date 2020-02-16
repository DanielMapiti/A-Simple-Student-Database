#include "DbHeader.h"
#include <iostream>
#include <string>
using namespace std;

void print(string message){
    cout<<"function "<<message<<" called."<<endl;
}

void addStudent(){
    print("addStudent");

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