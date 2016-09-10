//
// Created by konzy on 9/8/2016.
//

#include "Student.h"
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

int Student::idCount = 0;

string Student::printReport() {
    string result = "{id=" + to_string(id) + " name=\"" + name + "\" grades=[";
    for (int i = 0; i < grades.size(); ++i) {
        result += to_string(grades.at(i));
        if (i + 1 < grades.size()) {
            result += ", ";
        }
    }
    result += "]}";
    return result;
}

const bool Student::gradeInRange(int grade){
    return grade >= 0 && grade <= 100;
};

Student * Student::operator=(const Student &rhs) const {
    return new Student(rhs);
}

int Student::calculateGrade(){
    int total = 0;
    for (int i = 0; i < grades.size(); ++i) {
        total += grades[i];
    }
    return (int) (total / grades.size());
}

string Student::calculateLetterGrade(){
    int grade = calculateGrade();
    if(grade >= A_GRADE){
        return "A";
    } else if(grade >= A_MINUS_GRADE) {
        return "A-";
    } else if(grade >= B_PLUS_GRADE) {
        return "B+";
    } else if(grade >= B_GRADE) {
        return "B";
    } else if(grade >= B_MINUS_GRADE) {
        return "B-";
    } else if(grade >= C_PLUS_GRADE) {
        return "C+";
    } else if(grade >= C_GRADE) {
        return "C";
    } else if(grade >= C_MINUS_GRADE) {
        return "C-";
    } else if(grade >= D_PLUS_GRADE) {
        return "D+";
    } else if(grade >= D_GRADE) {
        return "D";
    } else {
        return "F";
    }
}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    Student::id = id;
}

const string &Student::getName() const {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

const vector<int> &Student::getGrades() const {
    return grades;
}

void Student::setGrades(const vector<int> &grades) {
    Student::grades = grades;
}

int Student::getIdCount() {
    return idCount;
}

void Student::setIdCount(int idCount) {
    Student::idCount = idCount;
}
