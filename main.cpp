#include <iostream>
#include "Student.h"
#include "Logger.h"

int main() {

    Logger::getLogger();
    Logger* logger;

    Student student1 = Student("student1", vector<int>{71,77,76});

    student1.calculateGrade();
    student1.calculateLetterGrade();
    student1.getId();
    student1.getIdCount();
    student1.getMarks();
    student1.getName();
    student1.printReport();

    logger->log("End of Default Constructor and accessors\n\n");

    logger->log("Start of mutators");
    student1.setId(77);
    student1.setMarks(vector<int>{99,89,79});
    student1.setName("student1 mutated");
    logger->log("End of mutators\n\n");

    logger->log("start of accessors after mutators");
    student1.getName();
    student1.getMarks();
    student1.getId();
    student1.getIdCount();
    logger->log("End of accessors after mutators\n\n");

    logger->log("Start of operator=");
    Student student2 = Student("name", vector<int>{});
    student2 = student1;
    logger->log("deep copy different addresses=" + to_string(&student1 != &student2));
    logger->log("deep copy same id=" + to_string(student1.getId() == student2.getId()));
    logger->log("deep copy same name" + to_string(student1.getName() == student2.getName()));
    logger->log("End of operator=\n\n");

    logger->log("start of copy constructor");
    Student student3 = Student(student1);
    logger->log("deep copy different addresses=" + to_string(&student1 != &student3));
    logger->log("deep copy same id=" + to_string(student1.getId() == student3.getId()));
    logger->log("deep copy same name" + to_string(student1.getName() == student3.getName()));
    logger->log("end of copy constructor\n\n");

    logger->log("edge cases");
    Student student4 = Student("", vector<int>{});
    student4.getName();
    student4.getMarks();
    student4.calculateLetterGrade();
    student4.calculateGrade();
    student4.printReport();


//
//
//
//
//    Student student3 = Student("student3", vector<int>{-11, 99, 101});
//
//
//
//    //Start of testing Student
//    vector<int> *myGrades = new vector<int>;
//    myGrades->push_back(71);
//    myGrades->push_back(100);
//    myGrades->push_back(99);
//    myGrades->push_back(101);
//    myGrades->push_back(-1);
//
//    string str = "s";
//    Student s(str, *myGrades);
//
//
//    int i = s.calculateGrade();
//    string letter = s.calculateLetterGrade();
//    string report = s.printReport();
//
//    Student s2("s2", vector<int>{12, 68, 99, 100, 78});
//    s2 = s;
//
//    int k = s2.calculateGrade();
//    string anotherLetter = s2.calculateLetterGrade();
//
//    Student s3(s2);
//
//    string rep = s2.printReport();
//
//    Student* s4 = new Student("s4", vector<int>{69, 69, 69, 69, 69});
//    Student s5 = *s4;
//
//    delete s4;
//
//    //End of testing Student
//
//    //Start of testing Logger
//
//    cout << " something ";
//
//    logger->log("something");
//
//    logger->log("something else");
//
//    //End of testing Logger
    return 0;
}