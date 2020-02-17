#ifndef _DBHEADER_H
#define _DBHEADER_H
#include <string>

void addStudent();
void readDb();
void saveDb();
void dispStudentData(std::string target);
void grade(std::string target);
void print();
std::string stnumber(std::string str);
void Split(const std::string& subject, std::vector<std::string>& container);


#endif