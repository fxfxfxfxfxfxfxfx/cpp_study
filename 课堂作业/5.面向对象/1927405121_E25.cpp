#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

class CComplex
{
	double m_real;
	double m_image;
public:
	void setValue(double real, double image);  // 设置复数的实部和虚部
	friend CComplex operator+(const CComplex& c1, const CComplex& c2);
	friend CComplex operator+( const CComplex& a,double n);
	friend CComplex operator++(CComplex& a);      //用于前置形式
	friend CComplex operator++(CComplex& a,int);   //用于后置形式
	friend ostream& operator<<(ostream&, const CComplex&);

};

void CComplex::setValue(double real, double image)
{
	this->m_image = image;
	this->m_real = real;
}
CComplex operator+(const CComplex& c1, const CComplex& c2)
{
	CComplex tem;
	tem.m_image = c1.m_image + c2.m_image;
	tem.m_real = c1.m_real + c2.m_real;
	return tem;
}
CComplex operator+(const CComplex& c1, double n)
{
	CComplex tem;
	tem.m_image = c1.m_image;
	tem.m_real = c1.m_real + n;
	return tem;
}
CComplex operator++(CComplex& a)
{
	a.m_image = a.m_image + 1;
	a.m_real = a.m_real + 1;
	CComplex tem;
	tem.m_image = a.m_image;
	tem.m_real = a.m_real;
	return tem;
}
CComplex operator++(CComplex& a, int)
{
	a.m_image = a.m_image + 1;
	a.m_real = a.m_real + 1;
	CComplex tem;
	tem.m_image = a.m_image - 1;
	tem.m_real = a.m_real - 1;
	return tem;
}
ostream& operator<<(ostream& output, const CComplex&c)
{
	output << c.m_real << "+" << c.m_image << "*i";
	return output;
}

int main()
{
	double x1, y1, x2, y2;
	CComplex c1, c2, c3;

	cout << "输入四个实数:" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	c1.setValue(x1, y1);
	c2.setValue(x2, y2);
	cout << "复数c1: " << c1 << endl;
	cout << "复数c2: " << c2 << endl;
	c3 = c1 + c2;
	cout << "c1+c2: " << c3 << endl;
	cout << "c1+x2: " << c1 + x2 << endl;
	cout << "++c2: " << ++c2 << endl;
	cout << "c2++: " << c2++ << endl;
	cout << "c2: " << c2 << endl;

	//system("pause");
	return 0;
}


