#include<iostream>
#include<iomanip>
#include<math.h>
#define pi 3.1415926
using namespace std;
class CCircle
{
    double c_x;
    double c_y;
    double c_r;
public:
    void set_xy(double x, double y);
    void set_r(double r);
    double get_area()const;
    double get_circlum()const;
    CCircle operator+(const CCircle& c)const;
    CCircle operator-(const CCircle& c)const;
    CCircle operator++();      //用于前置形式
    CCircle operator++(int);   //用于后置形式
    CCircle operator--();      //用于前置形式
    CCircle operator--(int);   //用于后置形式
    bool operator<(const CCircle& c)const;
    bool operator>(const CCircle& c)const;
    bool operator==(const CCircle& c)const;
    bool operator!=(const CCircle& c)const;
    bool operator&(const CCircle& c)const;
    int operator|(const CCircle& c)const;
    friend ostream& operator<<(ostream&, const CCircle&);
};
CCircle CCircle::operator+(const CCircle& c)const
{
    CCircle ccc;
    ccc.set_r(this->c_r+c.c_r);
    ccc.set_xy(this->c_x, this->c_y);
    return ccc;
}
CCircle CCircle::operator-(const CCircle& c)const
{
    CCircle ccc;
    double s;
    s = c.get_area() - pi*this->c_r*this->c_r;
    s = fabs(s);
    s = sqrt(s / pi);
    ccc.set_xy(this->c_x, this->c_y);
    ccc.set_r(s);
    return ccc;
}
CCircle CCircle::operator++()
{
    CCircle tem;
    this->c_r++;
    tem.set_r(this->c_r);
    tem.set_xy(this->c_x, this->c_y);
    return tem;
}
CCircle CCircle::operator++(int)
{
    CCircle tem;
    tem.set_r(this->c_r * 2);
    tem.set_xy(this->c_x, this->c_y);
    this->c_r++;
    return tem;
}
CCircle CCircle::operator--()
{
    CCircle tem;
    this->c_r--;
    tem.set_r(this->c_r);
    tem.set_xy(this->c_x, this->c_y);
    return tem;
}
CCircle CCircle::operator--(int)
{
    CCircle tem;
    tem.set_r(this->c_r * 2);
    tem.set_xy(this->c_x, this->c_y);
    this->c_r--;
    return tem;
}
bool CCircle::operator<(const CCircle& c)const
{
    return this->c_r < c.c_r;
}
bool CCircle::operator>(const CCircle& c)const
{
    return this->c_r > c.c_r;
}
bool CCircle::operator==(const CCircle& c)const
{
    return this->c_r == c.c_r && this->c_x == c.c_x && this->c_y == c.c_y;
}
bool CCircle::operator!=(const CCircle& c)const
{
    return this->c_r != c.c_r || this->c_x != c.c_x || this->c_y != c.c_y;
}
bool CCircle::operator&(const CCircle& c)const
{
    return this->c_x == c.c_x && this->c_y == c.c_y;
}
int CCircle::operator|(const CCircle& c)const
{
    double r1, r2, s;
    r1 = this->c_r;
    r2 = c.c_r;
    s = (this->c_x - c.c_x) * (this->c_x - c.c_x) + (this->c_y - c.c_y) * (this->c_y - c.c_y);
    s = sqrt(s);
    if (s > r1 + r2)
    {
        return 3;
    }
    else if (r2 > r1 + s || r1 > r2 + s)
    {
        return 0;
    }
    else if (r1 + r2 == s)
    {
        return 2;
    }
    else if (s + r1 == r2 || s + r2 == r1)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
ostream& operator<<(ostream& output, const CCircle&c)
{
    output << "(" << fixed << setprecision(3) << c.c_x << ","<< fixed << setprecision(3) << c.c_y << ")" << " "<< fixed << setprecision(3) << c.c_r << " "<< fixed << setprecision(3) << c.get_circlum() << " "<<fixed << setprecision(3) << c.get_area() << endl;
    return output;
}
void CCircle::set_xy(double x, double y)
{
    this->c_x = x;
    this->c_y = y;
}

void CCircle::set_r(double r)
{
    this->c_r = r;
}
double CCircle::get_area()const
{
    double c_area;
    c_area = pi * this->c_r * this->c_r;
    return c_area;
}
double CCircle::get_circlum()const
{
    return 2 * pi * this->c_r;
}
int main()
{
    CCircle c1, c2, c3, c4;
    double x1, y1, x2, y2, r1, r2;
    int istate;
    cout << "请输入圆心坐标和半径: " << endl;
    cin >> x1 >> y1 >> r1;
    c1.set_xy(x1, y1);
    c1.set_r(r1);
    cout << c1 << endl;
    cout << "请输入圆心坐标和半径: " << endl;
    cin >> x2 >> y2 >> r2;
    c2.set_xy(x2, y2);
    c2.set_r(r2);
    cout << c2 << endl;

    c3 = c1 + c2;
    cout << " 两圆相加: " << c3 << endl;
    c4 = c3 - c2;
    cout << " 两圆相减: " << c4 << endl;
    ++c4;
    cout << " C4前自增: " << c4 << endl;
    cout << " C4后自增: " << c4++ << " C4自增后: " << c4 << endl;
    --c4;
    cout << " C4前自减: " << c4 << endl;
    cout << " C4后自减: " << c4-- << " C4自减后: " << c4 << endl;

    cout << "c1: " << c1 << " c2: " << c2 << endl;
    if (c1 > c2)
        cout << "c1>c2" << endl;
    else if (c1 < c2)
        cout << "c1<c2" << endl;
    else
        cout << "c1<>c2" << endl;   // 表示无比较结果

    cout << "c1: " << c1 << " c4: " << c4 << endl;
    if (c1 == c4)
        cout << "c1==c4" << endl;
    else if (c1 != c4)
        cout << "c1!=c4" << endl;
    else
        cout << "c1<>c4" << endl;   // 表示无比较结果


    if (c1 & c4)
        cout << "c1与c4同心" << endl;

    istate = c1 | c2;
    switch (istate)
    {
    case 0:
        cout << "c1包含c2" << endl;
        break;
    case 1:
        cout << "c1与c2相交" << endl;
        break;
    case 2:
        cout << "c1与c2相切" << endl;
        break;
    case 3:
        cout << "c1与c2相离" << endl;
        break;
    default:
        cout << "c1与c2位置判断错误" << endl;
    }
    istate = c3 | c1;
    switch (istate)
    {
    case 0:
        cout << "c3包含c1" << endl;
        break;
    case 1:
        cout << "c3与c1相交" << endl;
        break;
    case 2:
        cout << "c3与c1相切" << endl;
        break;
    case 3:
        cout << "c3与c1相离" << endl;
    default:
        cout << "c3与c1位置判断错误" << endl;
    }

    return 0;
}
