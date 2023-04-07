#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    char *studentId;
    double gpa;
    char *fullname;
    char *address;

public:
    Student();
    Student(char *studentId, double gpa, char *fullname, char *address);
    Student(Student &s);
    void setStudentID(char *info);
    void setFullName(char *info);
    void setAddress(char *info);
    char *getStudentID();
    char *getFullName();
    char *getAddress();
    double getGpa();
    Student &operator=(Student &s);
    friend ostream &operator<<(ostream &out, Student &s);
    friend istream &operator>>(istream &in, Student &s);
    ~Student();
};

istream &operator>>(istream &in, Student &s)
{
    cout << "Nhap ID: ";
    cin.getline(s.studentId, 10);
    cout << "Nhap gpa: ";
    cin >> s.gpa; cin.ignore();
    cout << "Nhap ho ten: ";
    cin.getline(s.fullname, 50);
    cout << "Nhap dia chi: ";
    cin.getline(s.address, 100);
    return in;
}

void Student::setStudentID(char *info)
{
    for (int i = 0; i < strlen(info); i++)
    {
        studentId[i] = info[i];
    }
    studentId[strlen(info)] = '\0';
}

void Student::setFullName(char *info)
{
    for (int i = 0; i < strlen(info); i++)
    {
        fullname[i] = info[i];
    }
    fullname[strlen(info)] = '\0';
}

void Student::setAddress(char *info)
{
    for (int i = 0; i < strlen(info); i++)
    {
        address[i] = info[i];
    }
    address[strlen(info)] = '\0';
}

double Student::getGpa()
{
    return gpa;
}

char *Student::getStudentID()
{
    return studentId;
}

char *Student::getFullName()
{
    return fullname;
}

char *Student::getAddress()
{
    return address;
}

Student::Student()
{
    studentId = new char[10];
    gpa = 0;
    fullname = new char[50];
    address = new char[100];
}

Student::Student(char *ID, double GPA, char *FULLNAME, char *ADDRESS)
{
    gpa = GPA;

    // Các trường hợp nếu truyền vào là nullptr
    if (ID == nullptr)
    {
        studentId = new char[10];
    }
    else
    {
        studentId = new char[strlen(ID) + 1];
        setStudentID(ID);
    }

    if (FULLNAME == nullptr)
    {
        fullname = new char[50];
    }
    else
    {
        fullname = new char[strlen(FULLNAME) + 1];
        setFullName(FULLNAME);
    }

    if (ADDRESS == nullptr)
    {
        address = new char[100];
    }
    else
    {
        address = new char[strlen(ADDRESS) + 1];
        setAddress(ADDRESS);
    }
}

Student::Student(Student &s)
{
    gpa = s.getGpa();
    if (s.getStudentID() == nullptr)
    {
        studentId = new char[10];
    }
    else
    {
        studentId = new char[strlen(s.getStudentID()) + 1];
        setStudentID(s.getStudentID());
    }

    if (s.getFullName() == nullptr)
    {
        fullname = new char[50];
    }
    else
    {
        fullname = new char[strlen(s.getFullName()) + 1];
        setFullName(s.getFullName());
    }

    if (s.getAddress() == nullptr)
    {
        address = new char[100];
    }
    else
    {
        address = new char[strlen(s.getAddress()) + 1];
        setAddress(s.getAddress());
    }
}

Student &Student::operator=(Student &s)
{
    if (this == &s)
        return *this;
    delete[] studentId;
    delete[] fullname;
    delete[] address;

    gpa = s.getGpa();

    if (s.getStudentID() == nullptr)
    {
        studentId = new char[10];
    }
    else
    {
        studentId = new char[strlen(s.getStudentID()) + 1];
        setStudentID(s.getStudentID());
    }

    if (s.getFullName() == nullptr)
    {
        fullname = new char[50];
    }
    else
    {
        fullname = new char[strlen(s.getFullName()) + 1];
        setFullName(s.getFullName());
    }

    if (s.getAddress() == nullptr)
    {
        address = new char[100];
    }
    else
    {
        address = new char[strlen(s.getAddress()) + 1];
        setAddress(s.getAddress());
    }

    return *this;
}

ostream &operator<<(ostream &out, Student &s)
{
    out << "Ma hoc sinh: " << s.studentId << endl;
    out << "GPA: " << s.gpa << endl;
    out << "Ho ten: " << s.fullname << endl;
    out << "Dia chi: " << s.address << endl;
    return out;
}

Student::~Student()
{
    delete[] studentId;
    delete[] fullname;
    delete[] address;
}

int main()
{
    char *ID = new char[10];
    double GPA;
    char *FULLNAME = new char[50];
    char *ADDRESS = new char[100];
    cout << "Nhap ID: ";
    cin.getline(ID, 10);
    cout << "Nhap ho ten: ";
    cin.getline(FULLNAME, 50);
    cout << "Nhap dia chi: ";
    cin.getline(ADDRESS, 100);

    // Default constructor
    cout << "---Default constructor---" << endl;
    Student s1;
    cout << s1 << endl;

    // Full parametor constructor
    cout << "---Full parametor constructor---" << endl;
    Student s2(ID, 3.5, FULLNAME, ADDRESS);
    cout << s2 << endl;

    // Copy constructor
    cout << "---Copy constructor---" << endl;
    Student s3 = s2;
    cout << s3 << endl;

    // Assigment constructor
    cout << "---Assigment constructor---" << endl;
    Student s4;
    s4 = s2;
    cout << s4 << endl;

    //operator >>, <<
    Student s5;
    cin >> s5;
    cout << endl << s5 << endl;

    delete[] ID;
    delete[] ADDRESS;
    delete[] FULLNAME; 
}