//
// Created by konzy on 9/8/2016.
//

#include "Student.h"

int Student::id = 0;

const bool Student::gradesInRange(){
    for (int i = 0; i < grades.size(); ++i) {
        if (grades[i] < 0 || grades[i] > 100) {
            return false;
        }
    }
    return true;
};

Student * Student::operator=(const Student &rhs) const {
    return new Student(rhs.id, rhs.name, rhs.grades);
}

int Student::calculateGrades(){
    int total = 0;
    for (int i = 0; i < grades.size(); ++i) {
        total += grades[i];
    }
    return (int) (total / grades.size());
}