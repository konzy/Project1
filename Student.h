//
// Created by konzy on 9/8/2016.
//

#ifndef PROJECT1_STUDENT_H
#define PROJECT1_STUDENT_H
#include "Logger.h"
#include <string>
#include <vector>

#define A_GRADE 93
#define A_MINUS_GRADE 90
#define B_PLUS_GRADE 87
#define B_GRADE 83
#define B_MINUS_GRADE 80
#define C_PLUS_GRADE 77
#define C_GRADE 73
#define C_MINUS_GRADE 70
#define D_PLUS_GRADE 67
#define D_GRADE 60

#define A_STRING "A"
#define A_PLUS_STRING "A-"
#define B_PLUS_STRING "B+"
#define B_STRING "B"
#define B_MINUS_STRING "B-"
#define C_PLUS_STRING "C+"
#define C_STRING "C"
#define C_MINUS_STRING "C-"
#define D_PLUS_STRING "D+"
#define D_STRING "D"
#define F_STRING "F"

using namespace std;

#endif //PROJECT1_STUDENT_H

class Student {
public:
    ~Student() {}
    Student(const Student &student);
    Student(const string &name, const vector<int> &m);
    const bool gradeInRange(int);
    int calculateGrade();
    string calculateLetterGrade();
    Student operator=(const Student &rhs);
    string printReport();
    int getId() const;
    void setId(int id);
    const string &getName() const;
    void setName(const string &name);
    const vector<int> &getMarks() const;
    void setMarks(const vector<int> &marks);
    static int getIdCount();

private:
    int id;
    string name;
    vector<int> marks;
    static int idCount;
    Student(const int id, const string &name, const vector<int> &grades) : id(id), name(name), marks(grades) {Logger::getLogger();}//private constructor for operator=
};