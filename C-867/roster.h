#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class roster {
public:
    void add(const string& studentID, const string& firstName, const string& lastName, const string& emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void printAll();
    void printByDegreeProgram(int degreeProgram);
    void printAverageDaysInCourse(const string& studentID);
    void printInvalidEmails();
    void remove(const string& studentID);
    ~roster();
    student *classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr };
};