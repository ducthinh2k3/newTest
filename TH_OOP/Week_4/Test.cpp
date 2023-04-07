#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

class Student
{
private:
    string studentId;
    double grade;
    string fullname;

public:
    Student();
    Student(string studentId, double grade, string fullname);
    friend istream &operator>>(istream &in, Student &s);
    friend ostream &operator<<(ostream &out, Student s);
    string getStudentId();
    double getGrade();
    string getFullName();
    void setStudentId(string newId);
    void setGrade(double newGrade);
    void setFullName(string newName);
    ~Student();
};

Student::Student()
{
    studentId = fullname = "";
    grade = 0;
}

Student::Student(string studentId, double grade, string fullname)
{
    this->studentId = studentId;
    this->grade = grade;
    this->fullname = fullname;
}

istream &operator>>(istream &in, Student &s)
{
    cout << "nhap StudentId: ";
    getline(in, s.studentId);
    cout << "Nhap ho ten: ";
    getline(in, s.fullname);
    cout << "Nhap diem: ";
    cin >> s.grade;
    cin.ignore();
    return in;
}

ostream &operator<<(ostream &out, Student s)
{
    cout << "StudentId: " << s.studentId << endl;
    cout << "Ho ten: " << s.fullname << endl;
    cout << "Diem: " << s.grade << endl;
    return out;
}

string Student::getStudentId()
{
    return studentId;
}

string Student::getFullName()
{
    return fullname;
}

double Student::getGrade()
{
    return grade;
}

void Student::setStudentId(string newId)
{
    studentId = newId;
}

void Student::setFullName(string newName)
{
    fullname = newName;
}

void Student::setGrade(double newGrade)
{
    grade = newGrade;
}

Student::~Student()
{
    grade = 0;
    studentId.erase(studentId.begin(), studentId.end());
    fullname.erase(fullname.begin(), fullname.end());
}

Student readStudent(string line_info)
{
    Student s;
    stringstream ss(line_info);
    string buffer;
    getline(ss, buffer, ' ');
    s.setStudentId(buffer);
    getline(ss, buffer, ' ');
    s.setFullName(buffer);
    buffer = "";
    getline(ss, buffer);
    double grade = stod(buffer);
    s.setGrade(grade);
    // s.setGrade(0);
    return s;
}

int main()
{
    
}
