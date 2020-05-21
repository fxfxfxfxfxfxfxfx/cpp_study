#include<iostream>
using namespace std;
class Circle
{
private:
    double m_x;
    double m_y;
    double m_r;
    int m_id;
    static int max_id;
    static int sumofcircle;
public:
    Circle(double x,double y,double r);
    Circle(Circle& c);
    static int get_num();
    Circle& operator++();//前自增
    Circle operator++(int);//后自增
    Circle operator+(const Circle& c) const;
    friend ostream& operator<<(ostream&, Circle&);

};
int main()
{
    Circle c1(1.12, 2.23, 3.34), c2(c1);

    cout << c1 << c2;
    cout << "Number of circles = " << Circle::get_num() << endl;

    Circle c3 = c1 + c2;
    cout << c3;
    cout << "Number of circles = " << Circle::get_num() << endl;

    cout << c1++;
    cout << ++c2;
    cout << c1;

    return 0;
}

