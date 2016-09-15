#include <iostream>
#include "Student.h"
#include "Logger.h"

int main() {

    Logger::getLogger();
    Logger* logger;

    logger->log("Start of Default Constructor and accessors\n\n");

    Student student1("student1", vector<int>{71,77,76});

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
    Student student2("name", vector<int>{});
    student2 = student1;
    logger->log("deep copy different addresses=" + to_string(&student1 != &student2));
    logger->log("deep copy same id=" + to_string(student1.getId() == student2.getId()));
    logger->log("deep copy same name" + to_string(student1.getName() == student2.getName()));
    logger->log("End of operator=\n\n");

    logger->log("start of copy constructor");
    Student student3(student1);
    logger->log("deep copy different addresses=" + to_string(&student1 != &student3));
    logger->log("deep copy same id=" + to_string(student1.getId() == student3.getId()));
    logger->log("deep copy same name" + to_string(student1.getName() == student3.getName()));
    logger->log("end of copy constructor\n\n");

    logger->log("edge cases");
    Student student4("", vector<int>{});
    student4.getName();
    student4.getMarks();
    student4.calculateLetterGrade();
    student4.calculateGrade();
    student4.printReport();
    logger->log("end edge cases\n\n");

    return 0;
}