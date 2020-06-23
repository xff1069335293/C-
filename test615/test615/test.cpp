#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
/*class A {};
class B :public A {};*/
class person
{
public:
	 person()
	{
		cout << "person()" << endl;
	 }
	   ~person()
	{
		cout << "~person()" << endl;
	}
	  virtual void buyticket()//final虚函数不能被子类重写
	{
		cout << "全价" << endl;
		cout << _name << endl;
		
	}
	/* virtual person& buyticket()
	 {
		 cout << "全价" << endl;
		 cout << _name << endl;
		 return*this;
	 }*/
	  /*virtual A* buyticket()
	 {
		 cout << "全价" << endl;
		 cout << _name << endl;
		 return new A;
	 }*/
	string _name;
};

class stu: public person
{
public:
	stu()
	{
		cout << "stu()" << endl;
	}
	 ~stu()
	{
		cout << "~stu()" << endl;
	}
	 void buyticket()//override检查是否重写基类的虚函数
	{
		cout << "半价" << endl;
		cout << _name << endl;
		cout << _num << endl;
		cout << person::_name << endl;
	}
	/*virtual void buyticket(int)//虚函数重写，返回值，函数名，参数都相同时，成为子类重写了基类的虚函数
	{
		cout << "半价" << endl;
		cout << _name << endl;
		cout << _num << endl;
	}*/
	/*virtual stu& buyticket()//虚函数重写，函数名，参数都相同时，成为子类重写了基类的虚函数(协变引用都必须是引用，指针都指针)
	{
		cout << "半价" << endl;
		cout << _name << endl;
		cout << _num << endl;
		return *this;
	}*/
	/*virtual B* buyticket()//只要返回值满足父类对父类，子类对子类的引用或者指针，都可以是协变。其他类继承也可以。
	{
		cout << "半价" << endl;
		cout << _name << endl;
		cout << _num << endl;
		return new B;
	}*/
	int _num;
	string _name;
};
void test1()
{
	//同名隐藏 - 》重定义
	person p;
	p._name = "xff";
	stu s;
	s._name = "cf";
	s._num = 1;
	s.person::_name = "name";
	//p.buyticket();
	s.buyticket();
	//父类调用子类对象出现切片
	//person* pp = &s;
	//person& ps = s;
	//ps.buyticket();
	//pp->buyticket();//调用指针对象（person）类型的，数据是指向(stu)类型的。
	//stu*pps = &p;//子类调用不合法
	//stu* ps = (stu*)&p; //强转
	//ps->buyticket();    //强转成stu类型,调用的函数是stu对象指向的，数据是指向(person)类型的,有越界访问。
}
void func(person p)
{
	p.buyticket();
}
void func1(person& p)//父类引用
{
	p.buyticket();
}
void func2(person* p)//父类指针
{
	p->buyticket();
}
void test2()
{
	person p;
	p._name = "xff";
	stu s;
	s._name = "cf";
	s._num = 1;
	//func(p);
	//func(s);
	func1(p);
	func1(s);
	//func2(&p);
	//func2(&s);
}

void test3()
{
	//person p;
	//stu s;
	person *pp = new stu;//不是多态会内存泄漏
	//person *pp = new person;
	delete pp;
}
//抽象类（接口类） 纯虚函数的类
class A 
{
public :
	virtual void  fun1()
	{
		cout << "A::fun1()" << endl;
	}
	virtual void  fun2()
	{
		cout << "A::fun2()" << endl;
	}
	void  fun3()
	{
		cout << "A()" << endl;
	}
	//virtual void  fun1() = 0;
	int _num1;
	
};
class B :public A 
{
public:
	virtual void  fun1() 
	{
		cout << "B::fun1()" << endl;
	}
	/*virtual void  fun()//不重写纯虚函数子类就不能实例化出对象
	{

	}*/
	void  fun3()
	{
		cout << "B()" << endl;
	}
	virtual void  fun4()
	{
		cout << "B::fun4()" << endl;
	}
	int _age;
};

typedef void(*VFPTR)();
void PrintVTable(VFPTR* vTable)
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%p,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
void test4()
{
	A a;//抽象类不能实例化出对象
	B b;
	//printf("%p\n", *((int*)&a));
	//printf("%p\n", *((int*)&b));
	VFPTR* va = (VFPTR*)(*(int*)&a);
	PrintVTable(va);
	VFPTR* vb = (VFPTR*)(*(int*)&b);
	PrintVTable(vb);
	//a.fun3();
	//b.fun3();
 	//cout << sizeof(a) << endl;//虚函数表指针32位-4字节大小
	//cout << sizeof(b) << endl;

}
int main()
{
	//test1();//隐藏重定义名字相同
	//test2();//多态重重写
	//test3();
	test4();
 	system("pause");
	return 0;
}

