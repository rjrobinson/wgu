#include <iostream>
#include<string>
#include <utility>
#include "student.h"

using namespace std;

// Constructors
student::student() {
    // assign vars.
    setID("NO_studentID");
    setFirstName("NO_firstName");
    setLastName("NO_lastName");
    setEmailAddress("NO_emailAddress");
    setAge(-1);
    setDegreeProgram(degreeProgram);

    for (int i = 0; i < 3; ++i) {
        this->daysToComplete[i] = 0;
    }
}

student::student(
        string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysToComplete[],
        DegreeProgram degreeProgram) {
    // assign vars.
    setID(std::move(studentID));
    setFirstName(std::move(firstName));
    setLastName(std::move(lastName));
    setEmailAddress(std::move(emailAddress));
    setAge(age);
    setDaysToComplete(daysToComplete);
    setDegreeProgram(degreeProgram);
}

// Getters
string student::getID() const {
    return studentID;
}

string student::getFirstName() const {
    return firstName;
}

string student::getLastName() const {
    return lastName;
}

string student::getEmailAddress() const {
    return emailAddress;
}

int student::getAge() const {
    return age;
}

int *student::getDaysToComplete() {
    return this->daysToComplete;
}

DegreeProgram student::getDegreeProgram() const {
    return degreeProgram;
};

// Setters
void student::setDaysToComplete(int *newDays) {
    for (int i = 0; i < 3; ++i) { this->daysToComplete[i] = newDays[i]; }
}

void student::setID(string id) {
    studentID = std::move(id);
}

void student::setFirstName(string name) {
    firstName = std::move(name);
}

void student::setLastName(string name) {
    lastName = std::move(name);
}

void student::setEmailAddress(string email) {
    this->emailAddress = std::move(email);
}

void student::setAge(int age) {
    this->age = age;
}

string student::printDegreeProgram() const {
    DegreeProgram program = getDegreeProgram();
    string rtrString;
    if (program == SOFTWARE) {
        rtrString = "SOFTWARE";
    } else if (program == NETWORK) {
        rtrString = "SECURITY";
    } else if (program == SECURITY) {
        rtrString = "SECURITY";
    } else {
        rtrString = "UNDEFINED_PROGRAM";
    }

    return rtrString;
}

void student::setDegreeProgram(DegreeProgram program) {
    degreeProgram = program;
}

void student::print() {
    string degree_program = printDegreeProgram();
    int* days = getDaysToComplete();

    cout << "FirstName: " << getFirstName() << "\t";
    cout << "LastName: " << getLastName() << "\t";
    cout << "Degree Program: " << degree_program << "\t";
    cout << "Age: " << getAge() << "\t";
    cout << "Course Days: ";
    for (int i = 0; i <= 2; i++) {
        cout << days[i];
        cout << (i>=2 ? "":", ");
    }
    cout << endl;
}