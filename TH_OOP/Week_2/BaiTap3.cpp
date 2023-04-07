#include <iostream>
#include <math.h>
using namespace std;

class Point2D
{
    private:
        double x, y;
    public:
        Point2D();
        ~Point2D();
        void Input();
        void Output();
        double Distance(Point2D B);
};

Point2D::Point2D()
{
    x=y=0;
}

Point2D::~Point2D()
{
    x=y=0;
}

void Point2D::Input()
{
    cout << "------Nhap toa do------" << endl;
    cout << "Nhap toa do x: ";
    cin >> x;
    cout << "Nhap toa do y: ";
    cin >> y;
}

void Point2D::Output()
{
    cout << "Toa do diem: " << "(" << x << "," << y << ")" << endl;
}

double Point2D::Distance(Point2D B)
{
    double result;
    result = sqrt(pow(this->x - B.x, 2) + pow(this->y - B.y, 2));
    return result;
}

int main()
{
    Point2D A;
    Point2D B;
    A.Input();
    B.Input();
    A.Output();
    B.Output();
    cout << "khoang cach: " << A.Distance(B) << endl;
}

