#include <iostream>
using namespace std;

class Student
{
    private:
        float mathGrade, englishGrade, programmingGrade;
    public:
        void inPut();
        float average(); 
        bool isGood();   
};

void Student::inPut()
{
    cout << "Nhap vao diem mon toan: ";
    cin >> mathGrade;
    cout << "Nhap vao diem mon anh van: ";
    cin >> englishGrade;
    cout << "Nhap vao diem mon lap trinh: ";
    cin >> programmingGrade;
}

float Student::average()
{
    float ave = (mathGrade + englishGrade + programmingGrade) / 3;
    return ave;
}

bool Student::isGood()
{
    if(average() <= 8 || (mathGrade < 6.5 || englishGrade < 6.5 || programmingGrade < 6.5) )
        return false;
    return true;
}

int main()
{
    Student s;
    s.inPut();
    cout << "Diem trung binh cua sinh vien nay: " << s.average() << endl;
    if(s.isGood())
    {
        cout << "Day la sinh vien gioi toan dien" << endl;
    }
    else
    {
        cout << "Day khong la sinh vien gioi toan dien" << endl;
    }
}