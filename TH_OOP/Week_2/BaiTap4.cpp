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

class Rectangle
{
    private:
        Point2D topLeft;
        Point2D topRight;
        Point2D underLeft;
        Point2D underRight;
    public:
        void Input();
        void Output();
        bool isValid();
        double getTopEdge();
        double getUnderEdge();
        double getLeftEdge();
        double getRightEdge();
        double Perimeter(); // Chu vi
        double Area(); // Diện tích
};

void Rectangle::Input()
{
    cout << "Nhap toa do diem tren ben trai: " << endl;
    topLeft.Input();
    cout << "Nhap toa do diem tren ben phai: "<< endl;
    topRight.Input();
    cout << "Nhap toa do diem duoi ben trai: "<< endl;
    underLeft.Input();
    cout << "Nhap toa do diem duoi ben phai: "<< endl;
    underRight.Input();
}

void Rectangle::Output()
{
    cout << "Toa do diem tren ben trai: ";
    topLeft.Output();
    cout << "Toa do diem tren ben phai: ";
    topRight.Output();
    cout << "Toa do diem duoi ben trai: ";
    underLeft.Output();
    cout << "Toa do diem duoi ben phai: ";
    underRight.Output();
}

double Rectangle::getTopEdge()
{
    return topLeft.Distance(topRight);
}

double Rectangle::getUnderEdge()
{
    return underLeft.Distance(underRight);
}

double Rectangle::getLeftEdge()
{
    return topLeft.Distance(underLeft);
}

double Rectangle::getRightEdge()
{
    return topRight.Distance(underRight);

}

bool Rectangle::isValid()
{
    
    //cout << getTopEdge() << "," << getUnderEdge() << "," << getLeftEdge() << "," <<getRightEdge() <<"," << endl;
    if(getTopEdge() == getUnderEdge() && getLeftEdge() == getRightEdge())
    {
        double diagonal1, diagonal2; // đường chéo
        diagonal1 = topLeft.Distance(underRight);
        diagonal2 = underLeft.Distance(topRight);
        //cout << diagonal1 << "," << diagonal2 << endl;
        if(diagonal1 == diagonal2) // kiểm tra 2 đường chéo có bằng nhau hay không
        {
            return 1;
        }
    }
    return 0;
}

double Rectangle::Perimeter()
{
    double result = (getTopEdge() + getLeftEdge())*2;
    return result;
}

double Rectangle::Area()
{
    double result = getTopEdge() * getLeftEdge();
    return result;
}

int main()
{
    Rectangle h;
    h.Input();
    h.Output();
    if(h.isValid() == 1)
    {
        cout << "Day la hinh chu nhat" << endl;
        cout << "Chu vi: " << h.Perimeter() << endl;
        cout << "Dien tich: " << h.Area() << endl;
    }
    else
    {
        cout << "Day khong la hinh chu nhat" << endl;
    }
}