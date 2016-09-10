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
public:
    ~Student()
    {

    }

    Student(const Student & rhs) : id(*new int(rhs.id)), name(*new string(rhs.name)), grades (*new vector<int>(rhs.grades)){}//copy constructor

    Student(const string &n, const vector<int> &g) : id(++idCount), name(n) {
        for (int i = 0; i < g.size(); ++i) {
            if(gradeInRange(g.at(i))) {
                grades.push_back(g.at(i));
            }
        }
    }//default constructor

    const bool gradeInRange(int);
    int calculateGrade();
    string calculateLetterGrade();
    Student * operator=(const Student &rhs) const;
    string printReport();

    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    const vector<int> &getGrades() const;

    void setGrades(const vector<int> &grades);

    static int getIdCount();

    static void setIdCount(int idCount);

private:
    int id;
    string name;
    vector<int> grades;
    static int idCount;
    Student(const int id, const string &name, const vector<int> &grades) : id(id), name(name), grades(grades) {}//private constructor for operator=
};