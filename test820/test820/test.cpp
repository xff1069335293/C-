#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//C��������ת��
void test_c()
{
	//��ʽ����ת��
	int i = 1;
	double d = i;
	printf("i = %d ,d = %.2f\n", i, d);

	//��ʽ����ת��
	int *p = &i;
	int address =(int)p;
	printf("p = %p , address = %d\n", p, address);
}
//C++ 4������ת��

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

//������ͣ���ʽ���ͣ�
void test_static_cast()
{
	
	double d = 10.5;
	int i = static_cast<int>(d);
	cout << i << endl;
}
//��������ͣ�ǿת��
void test_reinterpret_cast()
{
	int *p = nullptr;
	int i = 10;
	p = (int*)i;
	cout << p << endl;
	p = reinterpret_cast<int*>(i);
	cout << p << endl;
}
//ȥ��const����
void test_const_cast()
{
	//const_cast
	int i1 = 10;
	int *p1 = const_cast<int*>(&i1);
	*p1 = 5;
	cout << "i1->" << i1 << " " << "*p1->" << *p1 << endl;
	//��const ��ԭ����ֵ���䣬��Ϊconst��ֵ�ڼĴ��������ڱ������Ż������棬���ĵ���ֵ�����ڴ����
	const int i2 = 10;
	int *p2 = const_cast<int*>(&i2);
	*p2 = 5;
	cout << "i2->" << i2 << " " << "*p2->" << *p2 << endl;
	//volatile��ֹ�������Ż�
	volatile const int i3 = 10;
	int *p3 = const_cast<int*>(&i3);
	*p3 = 5;
	cout << "i3->" << i3 << " " << "*p3->" << *p3 << endl;
}

void fun(A* p)
{
	/*A* pa = p;
	pa->_a;
	//ǿתԽ�������
	B* pb = (B*)p;
	pb->_b;*/

	
	B* b = dynamic_cast<B*>(p);
	if (b)
		cout << "ָ�����࣬ת���ɹ�" << endl;
	else
		cout << "ָ���࣬ת��ʧ��" << endl;
	
}
//��̬���͵�ת��,(��������������麯��)
//dynamic_cast�ǵ�ָ��ָ����������Ϸ��ҵ�����ı�ʶ��Ϣ
void test_dynamic_cast() 
{
	//�����������࣬��Ƭ
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

	//��ʽ����ת����ûд = �����ǻ���ʽ����ת���� C tmp(1)-> C c3(tmp)�Ӷ��������c3
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