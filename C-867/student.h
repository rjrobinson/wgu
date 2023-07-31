#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"

//#include <iostream>
//#include <string>

using namespace std;

class student {
public:
    // getters
    DegreeProgram getDegreeProgram() const;

    int getAge() const;

    string getEmailAddress() const ;

    string getFirstName() const;

    string getID() const ;

    string getLastName() const ;

    string printDegreeProgram() const;

    int* getDaysToComplete();

    // setters
    void print();

    void setAge(int age);

    void setDaysToComplete(int* days);

    void setDegreeProgram(DegreeProgram program);

    void setEmailAddress(string email);

    void setFirstName(string name);

    void setID(string id);

    void setLastName(string name);

    // constructors
    student();

    student(
            string studentID,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int daysToComplete[],
            DegreeProgram degreeProgram);

private:
    DegreeProgram degreeProgram;
    const static int DEFAULT_DAYS = 3;
    int daysToComplete[DEFAULT_DAYS];
    int age;
    string emailAddress;
    string firstName;
    string lastName;
    string studentID;
};

#endif