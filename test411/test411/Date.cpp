#include"Date.h"

	//获取某月的天数
	int Getmonthday(int year, int month){
		int day[13] = { 0, 31,28,31,30,31,30,31,30,31,30,31,30 };
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
			day[2] = 29;
		}
		return day[month];
	}
	//构造函数全缺省
	Date::Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		,_day(day)
	{
		if (year >= 0 && month > 0 && month < 13 && day>0 && day <= Getmonthday(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}else{
			cout << "非法日期" << endl;
		}
	}
	//析构函数
	Date::~Date(){}
	//运算符>重载
	 bool operator>(const Date& d1,const Date& d2){
		if (d1._year > d2._year){
			return true;
		}
		else if (d1._year == d2._year&&d1._month > d2._month){
			return true;
		}
		else if (d1._year == d2._year&&d1._month == d2._month&&d1._day > d2._day){
			return true;
		}
		return false;
	}
	//运算符==重载
	bool operator==(const Date& d1, const Date& d2) {
		if (d1._year == d2._year && d1._month == d2._month&&d1._day == d2._day){
			return true;
		}
		return false;
	}
	//运算符！=重载
	bool operator!=(const Date& d1, const Date& d2) {
		return !(d1 == d2);
	}
	//运算符>=重载
	bool operator>=(const Date& d1, const Date& d2){
		if (d1 > d2){
			return true;
		}
		else if (d1 == d2){
			return true;
		}
		return false;
	}

	//运算<重载
	bool operator<(const Date& d1, const Date& d2) {
		if (d1>= d2){
			return false;
		}
		return true;
	}

	//运算<=重载
	bool operator<=(const Date& d1, const Date& d2) {
		if (d1 > d2){
			return false;
		}
		return true;
	}
	////赋值运算符号 = 
	/* Date& operator=( Date& d1, const Date& d2) {
		if (&d1 != &d2){
			d1._year = d2._year;
			d1._month = d2._month;
			d1._day = d2._day;
		}
		return d1;
	}*/
	//日期-天数
	Date& operator-=(Date& d1,int day){
		if (day < 0){
			return d1 += -day;
		}
		d1._day -= day;
		while (d1._day <= 0){
			--d1._month;
			if (d1._month == 0){
				d1._month = 12;
				--d1._year;
			}
			d1._day += Getmonthday(d1._year, d1._month);
		}
		return d1;
	}
	Date& operator-( Date& d1,int day){
		d1 -= day;
		return d1;
	}
	//日期+=天数
	Date& operator+=(Date& d1, int day) {
		if (day < 0) {
			return d1 -= -day;
		}
		d1._day += day;
		while (d1._day > Getmonthday(d1._year, d1._month)) {
			++d1._month;
			if (d1._month > 12) {
				++d1._year;
				d1._month = 1;
			}
			d1._day -= Getmonthday(d1._year, d1._month);
		}
		return d1;
	}
	//日期+天数
	Date& operator+(Date& d1, int day) {
		d1 += day;
		return d1;
	}
	
	//前置++
	Date& operator++(Date& d1){
		d1 += 1;
		return d1;
	}
	//后置++
	Date operator++(Date& d1,int) {
		Date d(d1);
		d1 += 1;
		return d;
	}
	//前置--
	Date& operator--(Date& d1) {
		d1 -= 1;
		return d1;
	}
	//后置--
	Date operator--(Date& d1, int){
		Date d(d1);
		d1 -= 1;
		return d;
	}
	//日期-日期
	int operator-(const Date& d1,const Date&  d2){
		Date max = d1;
		Date min = d2;
		int flag = 1;
		int num = 0;
		if (d1 < d2){
			max = d2;
			min = d1;
			flag = -1;
		}
		while (min != max){
			++num;
			++min;
		}
		return flag == 1 ? num : -num;
	}

//重载<<
ostream& operator<<(ostream& _out, const Date& d) {
	_out << d._year << "-" << d._month << "-" << d._day << endl;
	return _out;
}
//重载>>
istream& operator>>(istream& _in, Date& d) {
	_in >> d._year >> d._month >> d._day;
	return _in;
}
void test()
{
	Date d1(1900,1,1);
	Date d2(2020,1,1);
	//d1 = d2;
	//cout << (d1 == d2) << endl;
	//cout << (d1 != d2) << endl;
	//cout << (d1 >= d2) << endl;
	//cout << (d1 <= d2) << endl;
	//cout << (d1 > d2) << endl;
	//cout << (d1 < d2) << endl;
	//d1 + 1;
	//d1 + -1;
	//d1 - 1;
	//d1 += -1;
	//d1 += 1;
	//d1 -1;
	//d1 -= 1;
	//d1 -= -1;
	//cout<<d1++;
	//cout <<++d1;
	//cout<<d1--;
	//cout <<--d1;
	//cin >> d1;
	//cout << d1;
	//cout << (d2 - d1) << endl;
	//cout << (d1 - d2) << endl;
	cout<< Getmonthday(2020,5);
}



