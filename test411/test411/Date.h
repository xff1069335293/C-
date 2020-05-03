#include<iostream>
using namespace std;
class Date
{
public:
	//��ȡĳ�µ�����
	friend int Getmonthday(int year, int month);
	//���캯��ȫȱʡ
	Date(int year, int month, int day);
		
	//��������
	 ~Date();
	//����>
	 friend  bool operator>(const Date& d1, const Date& d2);
	//�����==����
	 friend bool operator==(const Date& d1, const Date& d2);
	//�������=����
	 friend bool operator!=(const Date& d1, const Date& d2);
	//�����>=����
	 friend bool operator>=(const Date& d1, const Date& d2);
	//����<����
	 friend bool operator<(const Date& d1, const Date& d2);
	//����<=����
	 friend bool operator<=(const Date& d1, const Date& d2);
	//��ֵ������� = 
	 //friend Date& operator=(Date& d1, const Date& d2);
	//����-=����
	 friend Date& operator-=(Date& d1, int day);
	//����-����
	 friend Date& operator-(Date& d1, int day);
	//����+����
	 friend  Date& operator+(Date& d1, int day);
	//����+=����
	 friend Date& operator+=(Date& d1, int day);
	//ǰ��++
	 friend Date& operator++(Date& d1);
	//����++
	 friend Date operator++(Date& d1, int);
	//ǰ��--
	 friend Date& operator--(Date& d1);
	//����--
	 friend Date operator--(Date& d1, int);
	//����-����
	 friend int operator-(const Date& d1, const Date&  d2);
	//<<
	friend ostream& operator<<(ostream& _out, const Date& d);
	//>>
	friend istream& operator>>(istream& _in, Date& d);
private:
	int _year;
	int _month;
	int _day;
};