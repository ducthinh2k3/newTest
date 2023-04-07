// File Fraction.h nằm trong thư mục Header Files. Dùng để
// định nghĩa các thuộc tính và phương thức của lớp
// Tên class: Fraction
class Fraction
{
    // Phần khai báo thuộc tính
    // Nếu để mặc định thì sẽ là private
    int numerator;
    int denominator;
    // Phần khai báo phương thức bên trong lớp đối tượng
public:
    void setValue(int numerator, int denominator);
    void printOnScreen();
};