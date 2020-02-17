#include "DbHeader.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    int choice;
    for(;;){

        cout<<"Enter a number (or q to quit) and press return...\n";
        cout<<"1: Add Student\n2: Read Database\n3: Save Database\n4: Display Given Student Data\n5: Grade Student\nq: Quit\n";
        cin>>choice;

        if(choice== 1){
            addStudent();
        } else if (choice==2)
        {
            readDb();
        }else if (choice==3)
        {
            saveDb();
        }else if (choice==4)
        {
            dispStudentData();
        }else if (choice ==5)
        {
            grade();
        }else
        {
            break;
        }

 
    }
    return 0;
}