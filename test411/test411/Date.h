#include<iostream>
using namespace std;
class Date
{
public:
	//获取某月的天数
	friend int Getmonthday(int year, int month);
	//构造函数全缺省
	Date(int year, int month, int day);
		
	//析构函数
	 ~Date();
	//重载>
	 friend  bool operator>(const Date& d1, const Date& d2);
	//运算符==重载
	 friend bool operator==(const Date& d1, const Date& d2);
	//运算符！=重载
	 friend bool operator!=(const Date& d1, const Date& d2);
	//运算符>=重载
	 friend bool operator>=(const Date& d1, const Date& d2);
	//运算<重载
	 friend bool operator<(const Date& d1, const Date& d2);
	//运算<=重载
	 friend bool operator<=(const Date& d1, const Date& d2);
	//赋值运算符号 = 
	 //friend Date& operator=(Date& d1, const Date& d2);
	//日期-=天数
	 friend Date& operator-=(Date& d1, int day);
	//日期-天数
	 friend Date& operator-(Date& d1, int day);
	//日期+天数
	 friend  Date& operator+(Date& d1, int day);
	//日期+=天数
	 friend Date& operator+=(Date& d1, int day);
	//前置++
	 friend Date& operator++(Date& d1);
	//后置++
	 friend Date operator++(Date& d1, int);
	//前置--
	 friend Date& operator--(Date& d1);
	//后置--
	 friend Date operator--(Date& d1, int);
	//日期-日期
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