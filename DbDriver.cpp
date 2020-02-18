#include "DbHeader.h"
#include <iostream>
#include <string>
using namespace std;
using namespace MPTSAN003;

int main(){
    int choice;
    string target;
    for(;;){
        cout<<"+------------------------------=------------------------------------------+\n";
        cout<<"Enter a number (or q to quit) and press return...\n";
        cout<<"1: Add Student\n2: Save Database\n3: Read Database\n4: Display Given Student Data\n5: Grade Student\nq: Quit\n";
        cout<<"+-------------------------------------------------------------------------+\n";
        cin>>choice;

        if(choice== 1){
            MPTSAN003::addStudent();
        } else if (choice==2)
        {
            MPTSAN003::saveDb();
        }else if (choice==3)
        {
            MPTSAN003::readDb();
            
        }else if (choice==4)
        {
            cout<<"Enter the student number: \n";
            cin>> target;
            MPTSAN003::dispStudentData(target);

        }else if (choice ==5)
        {
            cout<<"Enter the student number: \n";
            cin>> target;
            MPTSAN003::grade(target);
        }else
        {
            break;
        }

 
    }
    return 0;
}