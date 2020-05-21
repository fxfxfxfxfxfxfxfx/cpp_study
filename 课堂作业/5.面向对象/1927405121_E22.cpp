#include<iostream>
#include<math.h>
#include<iomanip>
#define pi 3.1415926
using namespace std;

class CCircle
{
	double c_x;
	double c_y;
	double c_r;
public:
	void set_xy(double x,double y);
	void set_r(double r);
	double get_area();
	double get_circlum();
};
void CCircle::set_xy(double x, double y)
{
	this->c_x = x;
	this->c_y = y;
}

void CCircle::set_r(double r)
{
	this->c_r = r;
}
double CCircle::get_area()
{
	double c_area;
	c_area = pi * this->c_r * this->c_r;
	return c_area;
}
double CCircle::get_circlum()
{
	return 2 * pi * this->c_r;
}
int main()
{
	CCircle c1;
	double x, y, r1, r2;
	cout << "����Բ������Ͱ뾶" << endl;
	cin >> x >> y >> r1;
	c1.set_xy(x, y);
	c1.set_r(r1);
	cout << "Բ�ܳ������: " << fixed << setprecision(3) << c1.get_circlum() << " " << c1.get_area() << endl;
	cout << "�����µİ뾶:" << endl;
	cin >> r2;
	c1.set_r(r2);
	cout << "Բ�ܳ������: " << fixed << setprecision(3) << c1.get_circlum() << " " << c1.get_area() << endl;
	return 0;
}
