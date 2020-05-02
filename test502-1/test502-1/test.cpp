//5.2类和对象下篇
#include<iostream>
using namespace std;
//初始化列表
//class B {
//public:
//	B(int a,char b)
//		:_a(a)
//		,_b(b)
//	{
//		cout << "B()" << endl;
//	}
//private:
//	int _a;//4
//	char _b;//1
//};
//class A {
//public:
//	A(int year,int month,int day,int hour,char b,int c)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		,_b(hour,b)
//		,_c(c)
//		,_d(1)
//	
//	{
//		cout << "A()" << endl;
//	}
//	/*class D {///内部类
//	public:
//		D() {
//			_h;//可以访问静态成员变量
//		}
//	private:
//		int _g;
//	};*/
//
//	void Display() {
//		cout << _year << _month << _day << endl;
//	}
//private:
//	int _year;//4
//	int _month;//4
//	int _day;//4
//	static int _h;//4在静态区，不计算到A类大小里面
//	//必须初始化的成员变量
//	B _b;//内存对齐之后是8
//	int& _c;//4
//	const int _d;//4
//	
//};
//int A::_h = 1;
//class C
//{
//public:
//	explicit C(int j, int w, int z)
//		//:_f(f)//构造 函数无法初始化静态数据
//		:_j(j)
//		, _w(w)
//		,_z(z)
//	{}
//	void Display() {
//		cout << _j <<_w<<_z<< endl;
//	}
//private:
//	static int _f;//静态的数据在，静态区存储
//	int _j;
//	int _k;
//	int _w;
//	int _z;
//};
//int C::_f = 1;


//class A {
//public:
//	A() { 
//		cout << "A()" << endl;
//		++_scount;
//	}
//	A(const A& t) { 
//		cout << "A()拷贝" << endl;
//		++_scount; 
//	}
//	static int GetACount() { return _scount; }
//private:
//	static int _scount;
//};
//int A::_scount = 0;
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}
int main() {
	//char a= 'a';
	//A d(0,0,0,a,0,0);
	//d.Display();
	//C c(1,2,3);
	//c.Display();
	//C d = (1,2);
	//d.Display();
	//cout << sizeof(A) << endl;
	//cout << sizeof(C) << endl;//1
	//TestA();
	system("pause");
	return 0;
}
