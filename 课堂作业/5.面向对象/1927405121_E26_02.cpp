#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
// Ϊ�˱��ڲ��ԣ��ṩһ��ϵͳ�����࣬������ȫ�ֶ����ʾ��ǰϵͳ����
class CSystemTime
{
private:
    int m_year, m_month, m_day;
public:
    void setDate(int y, int m, int d)
    {
        m_year = y;
        m_month = m;
        m_day = d;
    }
    int getYear()const { return m_year; }
    int getMonth()const { return m_month; }
    int getDay()const { return m_day; }
};

CSystemTime  systemTime;   // ȫ�ֱ�����ʾ��ǰϵͳʱ��
class CAount
{
	double m_Money;
	CSystemTime d;
    static double m_InterestRate;
public:
	static void SetInterestRate(double n);
	static double GetInterestRate();
	void SaveMoney(double n);
    int LendMoney(double n);
    double CalcInterest(double n);
    void SaveInterest();
    friend ostream& operator<<(ostream&, const CAount&);
};
double CAount::m_InterestRate = 0.1;
void CAount::SetInterestRate(double n)
{
    m_InterestRate=n;
}
double CAount::GetInterestRate()
{
    return m_InterestRate;
}
void CAount::SaveMoney(double n)
{
    this->m_Money = n;
    this->d = systemTime;
}
int CAount::LendMoney(double n)
{
    if (this->m_Money < n)
    {
        return -1;
    }
    else
    {
        this->m_Money = this->m_Money - n;
        return 1;
    }
}
double CAount::CalcInterest(double n)
{
    int day;
    double sum;
    if (n > this->m_Money)
    {
        return 0;
    }
    else
    {
        day = (systemTime.getYear() - d.getYear()) * 360;
        day = day + (systemTime.getMonth() - d.getMonth())*30;
        day = day + (systemTime.getDay() - d.getDay());
        sum = n * this->m_InterestRate / 360 * day;
    }
    return sum;
}
void CAount::SaveInterest()
{
    double sum;
    int day;
    day = (systemTime.getYear() - d.getYear()) * 360;
    day = day + (systemTime.getMonth() - d.getMonth()) * 30;
    day = day + (systemTime.getDay() - d.getDay());
    sum = this->m_Money * this->m_InterestRate / 360 * day;
    this->m_Money = sum + this->m_Money;
}

ostream& operator<<(ostream&output, const CAount&c)
{
    output << c.d.getYear() << "-" << c.d.getMonth() << "-"
        << c.d.getDay() << " " << c.m_Money << " " << c.m_InterestRate;
    return output;
}

int main()
{
    CAount aount;
    aount.SetInterestRate(0.1);
    int year, month, day;
    double money, istate;
    cout << "���뵱ǰ����(������):" << endl;
    cin >> year >> month >> day;
    systemTime.setDate(year, month, day);
    cout << "��������:" << endl;
    cin >> money;
    aount.SaveMoney(money);
    cout << "��ǰ�˻���Ϣ:" << endl;
    cout << aount << endl;

    cout << "�����µ�����(������):" << endl;
    cin >> year >> month >> day;
    systemTime.setDate(year, month, day);
    aount.SaveInterest();
    cout << "��ǰ�˻���Ϣ:" << endl;
    cout << aount << endl;

    cout << "�����µ�����(������):" << endl;
    cin >> year >> month >> day;
    systemTime.setDate(year, month, day);
    CAount::SetInterestRate(0.2);
    cout << "����ȡ����:" << endl;
    cin >> money;
    istate = aount.LendMoney(money);
    if (istate < 0)
        cout << "�˻�������" << endl;
    else
        cout << "ȡ��: " << istate << endl;

    cout << "��ǰ�˻���Ϣ:" << endl;
    cout << aount << endl;
    //system("pause");
    return 0;
}

