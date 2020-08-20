#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//C语言类型转换
void test_c()
{
	//隐式类型转换
	int i = 1;
	double d = i;
	printf("i = %d ,d = %.2f\n", i, d);

	//显式类型转换
	int *p = &i;
	int address =(int)p;
	printf("p = %p , address = %d\n", p, address);
}
//C++ 4种类型转换

class A
{
public:
	virtual void f() {}
	int _a=1;
};
class B:public A	
{
public:
	int _b = 2;
};

//相近类型（隐式类型）
void test_static_cast()
{
	
	double d = 10.5;
	int i = static_cast<int>(d);
	cout << i << endl;
}
//不相近类型（强转）
void test_reinterpret_cast()
{
	int *p = nullptr;
	int i = 10;
	p = (int*)i;
	cout << p << endl;
	p = reinterpret_cast<int*>(i);
	cout << p << endl;
}
//去除const属性
void test_const_cast()
{
	//const_cast
	int i1 = 10;
	int *p1 = const_cast<int*>(&i1);
	*p1 = 5;
	cout << "i1->" << i1 << " " << "*p1->" << *p1 << endl;
	//有const 的原来的值不变，因为const的值在寄存器（由于编译器优化）里面，而改掉的值是在内存里的
	const int i2 = 10;
	int *p2 = const_cast<int*>(&i2);
	*p2 = 5;
	cout << "i2->" << i2 << " " << "*p2->" << *p2 << endl;
	//volatile防止编译器优化
	volatile const int i3 = 10;
	int *p3 = const_cast<int*>(&i3);
	*p3 = 5;
	cout << "i3->" << i3 << " " << "*p3->" << *p3 << endl;
}

void fun(A* p)
{
	/*A* pa = p;
	pa->_a;
	//强转越界访问了
	B* pb = (B*)p;
	pb->_b;*/

	
	B* b = dynamic_cast<B*>(p);
	if (b)
		cout << "指向子类，转换成功" << endl;
	else
		cout << "指向父类，转换失败" << endl;
	
}
//多态类型的转换,(父类对象必须包换虚函数)
//dynamic_cast是到指针指向对象的虚表上方找到对象的标识信息
void test_dynamic_cast() 
{
	//子类对象给父类，切片
	A a;
	B b;

	A* pa = &a;
	fun(pa);

	pa = &b;
	fun(pa);

}
void test_cpp()
{
	//test_static_cast();
	//test_reinterpret_cast();
	//test_const_cast();
	//test_dynamic_cast();
}

class C
{
public:
	 explicit C(int c)
	{
		cout << "C(int c)" << endl;
	}
	C(const C& c)
	{
		cout << "C(const C& c)" << endl;
	}
private:
	int _a;
};
void  test_explicit()
{
	C c1(1);
	C c2(c1);

	//隐式类型转换，没写 = ，但是会隐式类型转换成 C tmp(1)-> C c3(tmp)从而构造出来c3
	//C c3 = 1;
	
}
int main()
{
	//test_c();
	//test_cpp();
	//test_explicit();
	system("pause");
	return 0;
}