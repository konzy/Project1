//
// Created by konzy on 9/8/2016.
//

#include "Student.h"

int Student::idCount = 0;

Logger* logger;

Student::Student(const Student &student) :
        id(*new int(student.id)),
        name(*new string(student.name)),
        marks(*new vector<int>(student.marks)){
    logger->log("Copy Constructor");
}

Student::Student(const string &n, const vector<int> &m) :
        id(++idCount),
        name(n) {

    for (int i = 0; i < m.size(); ++i) {
        if(gradeInRange(m.at(i))) {
            marks.push_back(m.at(i));
        }
    }
    Logger::getLogger();
    logger->log("Default Constructor");
}

string Student::printReport() {
    string result = "{id=" + to_string(id) + " name=\"" + name + "\" marks=[";
    for (int i = 0; i < marks.size(); ++i) {
        result += to_string(marks.at(i));
        if (i + 1 < marks.size()) {
            result += ", ";
        }
    }
    result += "]}";

    logger->log("printReport()=" + result);
    return result;
}

const bool Student::gradeInRange(int grade){
    bool result = grade >= 0 && grade <= 100;
    logger->log("gradeInRange()=" + to_string(result));
    return result;
};

Student Student::operator=(const Student &rhs) {

    if (this != &rhs) {
        name = rhs.name;
        id = rhs.id;
        marks = rhs.marks;
    }
    logger->log("copy constructor");
    return *this;
}

int Student::calculateGrade(){
    int result = 0;
    int total = 0;
    if (marks.size() == 0) {
        return 0;
    }
    for (int i = 0; i < marks.size(); ++i) {
        total += marks[i];
    }
    result = (int) (total / marks.size());

    logger->log("calculateGrade()=" + to_string(result));
    return result;
}

string Student::calculateLetterGrade(){
    string result = "";
    int grade = calculateGrade();
    if(grade >= A_GRADE) result = A_STRING;
    else if(grade >= A_MINUS_GRADE) result = A_PLUS_STRING;
    else if(grade >= B_PLUS_GRADE) result = B_PLUS_STRING;
    else if(grade >= B_GRADE) result = B_STRING;
    else if(grade >= B_MINUS_GRADE) result = B_MINUS_STRING;
    else if(grade >= C_PLUS_GRADE) result = C_PLUS_STRING;
    else if(grade >= C_GRADE) result = C_STRING;
    else if(grade >= C_MINUS_GRADE) result = C_MINUS_STRING;
    else if(grade >= D_PLUS_GRADE) result = D_PLUS_STRING;
    else if(grade >= D_GRADE) result = D_STRING;
    else result = F_STRING;

    logger->log("calculateLetterGrade()=" + result);
    return result;
}

int Student::getId() const {

    logger->log("getId()=" + to_string(id));
    return id;
}

void Student::setId(int id) {

    logger->log("setId()=" + to_string(id));
    Student::id = id;
}

const string &Student::getName() const {

    logger->log("getName()=" + name);
    return name;
}

void Student::setName(const string &name) {

    logger->log("setName()=" + name);
    Student::name = name;
}

const vector<int> &Student::getMarks() const {
    string logString = "getMarks()=";
    for (int i = 0; i < marks.size(); ++i) {
        logString += to_string(marks[i]) + " ";
    }
    logger->log(logString);
    return marks;
}

void Student::setMarks(const vector<int> &marks) {
    string logString = "setMarks()=";
    for (int i = 0; i < marks.size(); ++i) {
        logString += to_string(marks[i]) + " ";
    }

    logger->log(logString);
    Student::marks = marks;
}

int Student::getIdCount() {

    logger->log("getIdCount()=" + to_string(idCount));
    return idCount;
}