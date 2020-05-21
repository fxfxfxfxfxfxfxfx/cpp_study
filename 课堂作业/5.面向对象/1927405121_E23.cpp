#include<iostream>
#include<iomanip>
#define pi 3.1415926
using namespace std;

class CColumn
{
	double c_x;
	double c_y;
	double c_r;
	double c_h;
public:
	void SetXY(double x, double y);
	void SetR(double r);
	void SetH(double h);
	double GetBottomArea();
	double GetBottomCirclum();
	double GetSideArea();
	double GetVolume();
};
void CColumn::SetXY(double x, double y)
{
	this->c_x = x;
	this->c_y = y;
}
void CColumn::SetR(double r)
{
	this->c_r = r;
}
void CColumn::SetH(double h)
{
	this->c_h = h;
}
double CColumn::GetBottomArea()
{
	return pi * this->c_r * this->c_r;
}
double CColumn::GetBottomCirclum()
{
	return pi * this->c_r * 2;
}
double CColumn::GetSideArea()
{
	return pi * this->c_r * 2 * this->c_h;
}
double CColumn::GetVolume()
{
	return pi * this->c_r * this->c_r * this->c_h;
}
int main()
{
	CColumn c1;
	double x, y, r1, r2, h1, h2;
	cout << "输入圆心坐标、半径和高" << endl;
	cin >> x >> y >> r1 >> h1;
	c1.SetXY(x, y);
	c1.SetR(r1);
	c1.SetH(h1);
	cout << "圆柱的底面周长、底面积、侧面积和体积：" << endl;
	cout << fixed << setprecision(3) << c1.GetBottomCirclum() << " "
		<< c1.GetBottomArea() << " "
		<< c1.GetSideArea() << " "
		<< c1.GetVolume() << endl;
	cout << "输入底圆半径和高:" << endl;
	cin >> r2 >> h2;
	c1.SetR(r2);
	c1.SetH(h2);
	cout << "圆柱的底面周长、底面积、侧面积和体积：" << endl;
	cout << fixed << setprecision(3) << c1.GetBottomCirclum() << " "
		<< c1.GetBottomArea() << " "
		<< c1.GetSideArea() << " "
		<< c1.GetVolume() << endl;

	return 0;
}
