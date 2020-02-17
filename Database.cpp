#include "DbHeader.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
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
    string line;
    ifstream myfile ("RecordsFile.txt");
    if(myfile.is_open()){
        while (getline(myfile, line)){
            cout<<line<<endl;
        }
        myfile.close();
    }
    else{
        cout<<"Unable to open file!\n";
    }

    
}
void saveDb(){
    print("saveDb");
    ofstream myfile;
    myfile.open("RecordsFile.txt");
    if(myfile.is_open()){
    for(int i=0;i<recordList.size();i++){
        myfile<<recordList[i].name<<" "<<recordList[i].surname<<" "<<recordList[i].classRecord<<endl;
        }  
        recordList.clear();  
    }
    else{
        cout<< "Unable to open file!\n";
    }
myfile.close();

}
void dispStudentData(string target){
    print("dispStudentData");

    string line;
    int tracker=0;
    ifstream myfile ("RecordsFile.txt");
    if(myfile.is_open()){
        while (getline(myfile, line)){
            if(target.compare(stnumber(line))==0){
                cout<<line<<endl;
                tracker++;
                break;
            }
        }
        if(tracker==0){cout<< "student "<<target<<" not found."<<endl;}
        myfile.close();
    }
    else{
        cout<<"Unable to open file!\n";
    }


    

}
void grade(string target){
    print("grade");
    string line;
    int tracker=0;
    ifstream myfile ("RecordsFile.txt");
    if(myfile.is_open()){
        while (getline(myfile, line)){
            if(target.compare(stnumber(line))==0){
                cout<< line.length();
                tracker++;
                break;
            }
        }
        if(tracker==0){cout<< "student "<<target<<" not found."<<endl;}
        myfile.close();
    }
}

string stnumber(string str){
    istringstream ss(str);
     string stno;
    for(int i=0;i<3; i++){
        ss>>stno;
    }
    return stno;

}

void Split(const std::string& subject, std::vector<std::string>& container) //stack overflow
{
  container.clear();
  size_t len = subject.length() + 1;
  char* s = new char[ len ];
  memset(s, 0, len*sizeof(char));
  memcpy(s, subject.c_str(), (len - 1)*sizeof(char));
  for (char *p = strtok(s, " "); p != NULL; p = strtok(NULL, " "))
  {
    container.push_back( p );
  }
  delete[] s;
}