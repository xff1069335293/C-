#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//重载
void   swap(int x, int y)
{
	cout << "int swap()" << endl;
}
void  swap(double x, double y)
{
	cout << "double swap()" << endl;
}
void  swap(double x, int y)
{
	cout << "double int swap()" << endl;
}
void  swap(int x, double y)
{
	cout << "int double swap()" << endl;
}
class A
{
public:
	A(){}
};
class B:public A
{
public:
	B(){}
};
class per
{
public:
	/*virtual void fun1()
	{
		cout << "per::fun1()" << endl;
		
	}
	virtual A* fun1()//协变
	{
		cout << "per::fun1()" << endl;
		A* a = new A;
		return a;
	}*/
	virtual A& fun1()//协变
	{
		cout << "per::fun1()" << endl;
		A a;
		return a;
	}
	/*virtual B* fun1()
	{
		cout << "per::fun1()" << endl;
		B* b = new B;
		return b;
	}*/
	virtual void fun2()
	{
		cout << "per::fun2()" << endl;
	}
	void fun(int x)
	{
		cout << "per::fun()" << endl;
	}
	int _num = 1;
};
class stu :public per
{
public:
	 /*void fun1(int)//参数
	{
		cout << "stu::fun1()" << endl;
	}*/
	/*virtual int fun1()//返回值
	{
		cout << "stu::fun1()" << endl;
	}
	virtual void fun1()
	{
		cout << "stu::fun1()" << endl;
	}
	virtual B* fun1()
	{
		cout << "stu::fun1()" << endl;
		B* b = new B;
		return b;
	}*/
	virtual B& fun1()
	{
		cout << "stu::fun1()" << endl;
		B b;
		return b;
	}
	/*virtual A* fun1()//必须是基类与派生类的返回值
	{
		cout << "stu::fun1()" << endl;
		A* a = new A;
		return a;
	}*/
	void fun()
	{
		cout << "stu::fun()" << endl;
	}
	int _num=2;
	int _age = 18;
};
void test1()
{
	swap(1, 1);
	swap(9.9, 9.9);
	swap(9.9, 1);
	swap(1, 9.9);
}
void test2()//协变（重写）
{
	per*p = new stu;
	p->fun1();
}
void test3()//重定义
{
	stu s;
	cout << s._num << endl;
	cout << s.per::_num << endl;
	s.fun();
	s.per::fun(10);
}
int main()
{
	//test1();
	//test2();
	//test3();
	system("pause");
	return 0;
}