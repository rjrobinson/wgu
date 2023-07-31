#include <iostream>
#include <regex>
#include "roster.h"

using namespace std;

void roster::add(const string &studentID, const string &firstName, const string &lastName, const string &emailAddress,
                 int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

    int courseDays[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = new student(studentID,
                                              firstName,
                                              lastName,
                                              emailAddress,
                                              age,
                                              courseDays,
                                              degreeProgram);
            break;
        }
    }
}

void roster::remove(const string &studentID) {
    bool removed = false;
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getID() == studentID) {
            classRosterArray[i] = nullptr;
            removed = true;
            break;
        }
    }

    if (!removed) {
        cout << "ERROR: student ID '" << studentID << "' does not exist \n";
    }
}

void roster::printAll() {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        classRosterArray[i]->print();
    }
}

void roster::printAverageDaysInCourse(const string &studentID) {
    float avg = 0.0;
    int max = 3;
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getID() == studentID) {
            int *daysInCourse = classRosterArray[i]->getDaysToComplete();
            for (int x = 0; x < max; x++) {
                avg += daysInCourse[x];
            }

            cout << "student " << classRosterArray[i]->getID() << "'s average number of course days " << (avg / max);
            cout << "\n";
            break;
        }
    }
}

void roster::printInvalidEmails() {
    cout << " INVALID EMAILS" << endl;
    const std::regex pattern(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");

    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        string email = classRosterArray[i]->getEmailAddress();

        if (!(std::regex_match(email, pattern))) {
            cout << "[ " << email << "] - NOT A VALID EMAIL\n";
        }
    }
}

void roster::printByDegreeProgram(int degreeProgram) {
    cout << "PRINT BY DEGREE PROGRAM" << endl;
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

roster::~roster() {
    delete[] classRosterArray;
}