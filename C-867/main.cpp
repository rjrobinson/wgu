#include <iostream>

#include <sstream>
#include "roster.h"
#include "degree.h"

using namespace std;

int main() {
    roster classRoster;

    const string studentData[] = {
            "A1,John,Smith,John1989@gm il.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Robert,Robinson,rrob284@wgu.edu,37,35,40,45,SOFTWARE"
    };


    //populate the class roster array
    for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
        string input = studentData[i];
        istringstream ss(input);
        string token;
        string tempHolder[9];

        int x = 0;
        while (getline(ss, token, ',')) {
            cout << tempHolder[x] << endl;
            tempHolder[x] = token;
            x += 1;
        }

        DegreeProgram degree_program;
        if (tempHolder[8] == "NETWORK") {
            degree_program = NETWORK;
        } else if (tempHolder[8] == "SECURITY") {
            degree_program = SECURITY;
        } else if (tempHolder[8] == "SOFTWARE") {
            degree_program = SOFTWARE;
        } else {
            degree_program = UNDEFINED_PROGRAM;
        }

        classRoster.add(tempHolder[0], tempHolder[1], tempHolder[2], tempHolder[3], std::stoi(tempHolder[4]),
                        std::stoi(tempHolder[5]), std::stoi(tempHolder[6]), std::stoi(tempHolder[7]), degree_program);
    }
    cout << "Course: Scripting and Programming Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 000856539" << endl;
    cout << "Student Name: Robert Robinson" << "\n\n";

    cout << "PRINT CLASS ROSTER" << endl;
    classRoster.printAll();
    cout << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "AVERAGE DAYS IN COURSE" << endl;
    for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[i]); i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
    }
    cout << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    classRoster.remove("A3");
    classRoster.remove("A3");

    return 0;
}