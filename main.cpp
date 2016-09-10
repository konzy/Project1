#include <iostream>
#include "Student.h"
#include "Logger.h"

int main() {

    //Start of testing Student
    vector<int> *myGrades = new vector<int>;
    myGrades->push_back(71);
    myGrades->push_back(100);
    myGrades->push_back(99);
    myGrades->push_back(101);
    myGrades->push_back(-1);

    string str = "s";
    Student s(str, *myGrades);

    int i = s.calculateGrade();
    string letter = s.calculateLetterGrade();
    string report = s.printReport();

    Student s2("s2", vector<int>{12, 68, 99, 100, 78});
    s2 = s;

    int k = s2.calculateGrade();
    string anotherLetter = s2.calculateLetterGrade();

    Student s3(s2);

    string rep = s2.printReport();

    Student* s4 = new Student("s4", vector<int>{69, 69, 69, 69, 69});
    Student s5 = *s4;

    delete s4;

    //End of testing Student

    //Start of testing Logger

    cout << " something ";

    Logger::getLogger();
    Logger* logger;
    logger->log("something");

    logger->log("something else");

    //End of testing Logger
    return 0;
}