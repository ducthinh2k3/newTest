#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
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

class Course
{
private:
    string CourseId;
    string CourseName;
    vector<Student> listStudent;

public:
    Course(string, string);
    ~Course();
    void Enroll();
    void unEnroll();
    void OutPut();
    void xuatSVXuatSac();
    void xuatSVGioi();
    void xuatSVKha();
    void xuatSVTrungBinh();
    void xuatSVDuoiTrungBinh();
    int amountOfPassCourse();
    int amountOfNoPassCourse();
    void SapXepDSTangDanTheoTen();
    void SapXepDSGiamDanTheoTen();
    void SapXepDSTangDanTheoDiem();
    void SapXepDSGiamDanTheoDiem();
    void writeFile(string filename);
    Course &readFile(string filename);
};

Course::Course(string Id, string name)
{
    CourseId = Id;
    CourseName = name;
}

Course::~Course()
{
    CourseId = CourseName = "";
    listStudent.erase(listStudent.begin(), listStudent.end());
}

void Course::OutPut()
{
    cout << "Course Id: " << CourseId << endl;
    cout << "Course Name: " << CourseName << endl;
    cout << "-----------------" << endl;
    cout << "Danh sach sinh vien: " << endl;
    for (int i = 0; i < listStudent.size(); i++)
    {
        cout << listStudent[i] << endl;
    }
}

void Course::xuatSVXuatSac()
{
    cout << "Course Id: " << CourseId << endl;
    cout << "Course Name: " << CourseName << endl;

    cout << "Danh sach sinh vien xuat sac: " << endl;
    for (int i = 0; i < listStudent.size(); i++)
    {
        if (listStudent[i].getGrade() >= 9)
            cout << listStudent[i] << endl;
    }
}

void Course::xuatSVGioi()
{
    cout << "Course Id: " << CourseId << endl;
    cout << "Course Name: " << CourseName << endl;

    cout << "Danh sach sinh vien Gioi: " << endl;
    for (int i = 0; i < listStudent.size(); i++)
    {
        if (listStudent[i].getGrade() >= 8 && listStudent[i].getGrade() < 9)
            cout << listStudent[i] << endl;
    }
}

void Course::xuatSVKha()
{
    cout << "Course Id: " << CourseId << endl;
    cout << "Course Name: " << CourseName << endl;

    cout << "Danh sach sinh vien Kha: " << endl;
    for (int i = 0; i < listStudent.size(); i++)
    {
        if (listStudent[i].getGrade() >= 6.5 && listStudent[i].getGrade() < 8)
            cout << listStudent[i] << endl;
    }
}

void Course::xuatSVTrungBinh()
{
    cout << "Course Id: " << CourseId << endl;
    cout << "Course Name: " << CourseName << endl;

    cout << "Danh sach sinh vien Kha: " << endl;
    for (int i = 0; i < listStudent.size(); i++)
    {
        if (listStudent[i].getGrade() >= 5 && listStudent[i].getGrade() < 6.5)
            cout << listStudent[i] << endl;
    }
}

void Course::xuatSVDuoiTrungBinh()
{
    cout << "Course Id: " << CourseId << endl;
    cout << "Course Name: " << CourseName << endl;

    cout << "Danh sach sinh vien Kha: " << endl;
    for (int i = 0; i < listStudent.size(); i++)
    {
        if (listStudent[i].getGrade() < 5)
            cout << listStudent[i] << endl;
    }
}

int Course::amountOfPassCourse()
{
    int result = 0;
    for (int i = 0; i < listStudent.size(); i++)
    {
        if (listStudent[i].getGrade() >= 5)
            result++;
    }
    return result;
}

int Course::amountOfNoPassCourse()
{
    return listStudent.size() - amountOfPassCourse();
}

bool cmp1(Student a, Student b)
{
    return a.getFullName() < b.getFullName();
}

bool cmp2(Student a, Student b)
{
    return a.getFullName() > b.getFullName();
}

void Course::SapXepDSTangDanTheoTen()
{
    sort(listStudent.begin(), listStudent.end(), cmp1);
}

void Course::SapXepDSGiamDanTheoTen()
{
    sort(listStudent.begin(), listStudent.end(), cmp2);
}

bool cmp3(Student a, Student b)
{
    return a.getGrade() < b.getGrade();
}

bool cmp4(Student a, Student b)
{
    return a.getGrade() > b.getGrade();
}

void Course::SapXepDSTangDanTheoDiem()
{
    sort(listStudent.begin(), listStudent.end(), cmp3);
}

void Course::SapXepDSGiamDanTheoDiem()
{
    sort(listStudent.begin(), listStudent.end(), cmp4);
}

void Course::writeFile(string filename)
{
    ofstream fout(filename, ios::out);
    if (!fout)
    {
        cout << "Mo file khong thanh cong" << endl;
        return;
    }
    cout << "Mo file thanh cong" << endl;

    fout << CourseId << endl;
    fout << CourseName << endl;
    for (int i = 0; i < listStudent.size(); i++)
    {
        fout << listStudent[i].getStudentId() << " ";
        fout << listStudent[i].getFullName() << " ";
        fout << listStudent[i].getGrade();
        if(i != listStudent.size() - 1)
            fout << endl;
    }

    fout.close();
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
    getline(ss, buffer);
    double grade = stod(buffer);
    s.setGrade(grade);
    //s.setGrade(0);
    return s;
}

Course &Course::readFile(string filename)
{
    CourseId = CourseName = "";
    listStudent.erase(listStudent.begin(), listStudent.end());

    ifstream fin(filename, ios::in);
    if (!fin)
    {
        cout << "Mo file khong thanh cong" << endl;
        return *this;
    }
    cout << "Mo file thanh cong" << endl;

    getline(fin, CourseId);
    getline(fin, CourseName);

    string line_info;
    while (!fin.eof())
    {
        getline(fin, line_info);
        listStudent.push_back(readStudent(line_info));
    }

    fin.close();
    return *this;
}

void Course::Enroll()
{
    int number;
    cout << "Nhap so sinh vien muon them: ";
    cin >> number;
    cin.ignore();

    Student s;
    for (int i = 0; i < number; i++)
    {
        cout << "----- Nhap thong tin sinh vien -----" << endl;
        cin >> s;
        listStudent.push_back(s);
    }
}

void Course::unEnroll()
{
    int number;
    cout << "Nhap so sinh vien muon xoa: ";
    cin >> number;
    cin.ignore();

    string removeId;
    for (int i = 0; i < number; i++)
    {
        cout << "Nhap StudentId muon xoa: ";
        getline(cin, removeId);
        for (int j = 0; j < listStudent.size(); j++)
        {
            if (removeId == listStudent[j].getStudentId())
            {
                listStudent.erase(listStudent.begin() + j);
                break;
            }
        }
    }
}

int main()
{
    Course c("CSC10003", "Lap Trinh Huong Doi Tuong");

    int luaChon = 0;
    cout << "--------- Quan li khoa hoc ---------" << endl;
    cout << "0: ket thuc" << endl;
    cout << "1: Them sinh vien vao khoa hoc" << endl;
    cout << "2: Xoa sinh vien khoi khoa hoc theo StudentID" << endl;
    cout << "3: Lay danh sach sinh vien xuat sac" << endl;
    cout << "4: Lay danh sach sinh vien gioi" << endl;
    cout << "5: Lay danh sach sinh vien kha" << endl;
    cout << "6: Lay danh sach sinh vien trung binh" << endl;
    cout << "7: Lay danh sach sinh vien duoi trung binh" << endl;
    cout << "8: So luong sinh vien qua mon va khong qua mon" << endl;
    cout << "9: Sap xep danh sach giam dan theo ten" << endl;
    cout << "10: Sap xep danh sach tang dan theo ten" << endl;
    cout << "11: Sap xep danh sach giam dan theo diem" << endl;
    cout << "12: Sap xep danh sach tang dan theo diem" << endl;
    cout << "13: Luu danh sach xuong file" << endl;
    cout << "14: Doc file danh sach khoa hoc" << endl;
    cout << "15: Xuat thong tin khoa hoc" << endl;

    while(true)
    {
        do
        {
            cout << endl
                 << "Nhap lua chon: ";
            cin >> luaChon;
            cin.ignore();
        } while (luaChon < 0 || luaChon > 15);

        switch(luaChon)
        {
            case 0:
                return 0;
            case 1:
                c.Enroll();
                break;
            case 2:
                c.unEnroll();
                break;
            case 3:
                c.xuatSVXuatSac();
                break;
            case 4:
                c.xuatSVGioi();
                break;
            case 5:
                c.xuatSVKha();
                break;
            case 6:
                c.xuatSVTrungBinh();
                break;
            case 7:
                c.xuatSVDuoiTrungBinh();
                break;
            case 8:
                cout << "So luong sv qua mon: " << c.amountOfPassCourse() << endl;
                cout << "So luong sv chua qua mon: " << c.amountOfNoPassCourse() << endl;
                break;
            case 9:
                cout << "Da sap xep" << endl;
                c.SapXepDSGiamDanTheoTen();
                break;
            case 10:
                cout << "Da sap xep" << endl;
                c.SapXepDSTangDanTheoTen();
                break;
            case 11:
                cout << "Da sap xep" << endl;
                c.SapXepDSGiamDanTheoDiem();
                break;
            case 12:
                cout << "Da sap xep" << endl;
                c.SapXepDSTangDanTheoDiem();
                break;
            case 13:
                c.writeFile("output.txt");
                break;
            case 14:
                c.readFile("output.txt");
                break;
            case 15:
                c.OutPut();
                break;
        }
    }


    


}