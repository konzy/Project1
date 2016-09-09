//
// Created by konzy on 9/8/2016.
//

#ifndef PROJECT1_STUDENT_H
#define PROJECT1_STUDENT_H
#include <string>
#include <vector>

using namespace std;

#endif //PROJECT1_STUDENT_H

class Student {
private:
    int id;
    string name;
    vector <int> grades;
    static int idCount;
    Student(const int id, const string &name, const vector<int> &grades) : id(id), name(name), grades(grades) {}

public:
    ~Student()
    {
        delete name;
        delete grades;
    }

    Student(const string &name, const vector<int> &grades) : id(++idCount), name(name), grades(grades) {}
    const bool gradesInRange();
    int calculateGrades();
    Student * operator=(const Student &rhs) const;
};