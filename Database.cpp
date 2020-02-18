#include "DbHeader.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
using namespace MPTSAN003;


    struct StudentRecords{
    string name;
    string surname;
    string studentNumber;
    string classRecord;
};


vector<StudentRecords> recordList;
/*
void print(string message){
    cout<<"function "<<message<<" called."<<endl;
}
*/


StudentRecords student;
/*Adds student records to a vector*/
void MPTSAN003::addStudent(){
    cout<<"Enter the student's details separated by space (name surname studentNumber(lowercase) classRecord): \n";
    cin>>student.name;
    cin>>student.surname;
    cin>>student.studentNumber;
    getline(cin, student.classRecord);
    recordList.push_back(student);
    for(int i=0;i<recordList.size();i++){cout<<recordList[i].name<<endl;}
    
}

/*Read all students records from the .txt file*/
void MPTSAN003::readDb(){
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
/*Saves all students records from vector to the .txt file*/
void MPTSAN003::saveDb(){
    string line;
    ofstream myfile;
    int noLine=0; 
    ifstream ff;
    //vector<int>::iterator it;
    ff.open("RecordsFile.txt");
    if(ff.is_open()){
          while (getline(ff, line))
       {noLine++;}
       for(int p=0;p<recordList.size();p++){
        for(int k=0; k<noLine;k++){
            getline(ff,line);
            if(recordList[p].studentNumber.compare(stnumber(line))==0){
                //it= recordList.begin();
                recordList.erase(recordList.begin()+p);
                

            }

        }
    }
    }else{cout<< "Unable to open file!\n";}ff.close();

     
      myfile.open("RecordsFile.txt", ios::app);
    if(myfile.is_open()){
    for(int i=0;i<recordList.size();i++){
        myfile<<recordList[i].name<<" "<<recordList[i].surname<<" "<<recordList[i].studentNumber<<" "<<recordList[i].classRecord<<endl;
        }  
        recordList.clear();  
    }
    else{
        cout<< "Unable to open file!\n";
    }
myfile.close();

}

/*Displays student's details by student number */
void MPTSAN003::dispStudentData(string target){

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

/*Calculates the average of all grade and prints it out*/
void MPTSAN003::grade(string target){
    string line;
    int tracker=0;
    int total=0;
    int x=0;
    int avg=0;
    string bb;
    vector<string> vv;
    ifstream myfile ("RecordsFile.txt");
    if(myfile.is_open()){
        while (getline(myfile, line)){
            if(target.compare(stnumber(line))==0){
                Split(line,vv);
                for(int i=vv.size(); i>2;i--){
                    bb=vv[i];
                    stringstream toInt(bb);
                    toInt>> x;
                    total +=x;
                }
                avg = total/(vv.size()-3);
                cout<< "The average for "<<target<<" is "<<avg<<endl;
                tracker++;
                break;
            }
        }
        if(tracker==0){cout<< "student "<<target<<" not found."<<endl;}
        myfile.close();
    }
}

/*Given a string of student records, it returns the student number*/
string MPTSAN003::stnumber(string str){
    istringstream ss(str);
     string stno;
    for(int i=0;i<3; i++){
        ss>>stno;
    }
    return stno;

}

/*Splits a string by " " to a vector*/
void MPTSAN003::Split(const string& subject, vector<string>& container)
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

//count the number of lines in a file
/*
int numLine(string filename){
    
    int count = 0;
    string line;
 
    ifstream file(filename);
    while (getline(file, line))
       {count++;}
 
    file.close();
    return count;

}*/