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
	  virtual void buyticket()//final�麯�����ܱ�������д
	{
		cout << "ȫ��" << endl;
		cout << _name << endl;
		
	}
	/* virtual person& buyticket()
	 {
		 cout << "ȫ��" << endl;
		 cout << _name << endl;
		 return*this;
	 }*/
	  /*virtual A* buyticket()
	 {
		 cout << "ȫ��" << endl;
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
	 void buyticket()//override����Ƿ���д������麯��
	{
		cout << "���" << endl;
		cout << _name << endl;
		cout << _num << endl;
		cout << person::_name << endl;
	}
	/*virtual void buyticket(int)//�麯����д������ֵ������������������ͬʱ����Ϊ������д�˻�����麯��
	{
		cout << "���" << endl;
		cout << _name << endl;
		cout << _num << endl;
	}*/
	/*virtual stu& buyticket()//�麯����д������������������ͬʱ����Ϊ������д�˻�����麯��(Э�����ö����������ã�ָ�붼ָ��)
	{
		cout << "���" << endl;
		cout << _name << endl;
		cout << _num << endl;
		return *this;
	}*/
	/*virtual B* buyticket()//ֻҪ����ֵ���㸸��Ը��࣬�������������û���ָ�룬��������Э�䡣������̳�Ҳ���ԡ�
	{
		cout << "���" << endl;
		cout << _name << endl;
		cout << _num << endl;
		return new B;
	}*/
	int _num;
	string _name;
};
void test1()
{
	//ͬ������ - ���ض���
	person p;
	p._name = "xff";
	stu s;
	s._name = "cf";
	s._num = 1;
	s.person::_name = "name";
	//p.buyticket();
	s.buyticket();
	//�������������������Ƭ
	//person* pp = &s;
	//person& ps = s;
	//ps.buyticket();
	//pp->buyticket();//����ָ�����person�����͵ģ�������ָ��(stu)���͵ġ�
	//stu*pps = &p;//������ò��Ϸ�
	//stu* ps = (stu*)&p; //ǿת
	//ps->buyticket();    //ǿת��stu����,���õĺ�����stu����ָ��ģ�������ָ��(person)���͵�,��Խ����ʡ�
}
void func(person p)
{
	p.buyticket();
}
void func1(person& p)//��������
{
	p.buyticket();
}
void func2(person* p)//����ָ��
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
	person *pp = new stu;//���Ƕ�̬���ڴ�й©
	//person *pp = new person;
	delete pp;
}
//�����ࣨ�ӿ��ࣩ ���麯������
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
	/*virtual void  fun()//����д���麯������Ͳ���ʵ����������
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
	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%p,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
void test4()
{
	A a;//�����಻��ʵ����������
	B b;
	//printf("%p\n", *((int*)&a));
	//printf("%p\n", *((int*)&b));
	VFPTR* va = (VFPTR*)(*(int*)&a);
	PrintVTable(va);
	VFPTR* vb = (VFPTR*)(*(int*)&b);
	PrintVTable(vb);
	//a.fun3();
	//b.fun3();
 	//cout << sizeof(a) << endl;//�麯����ָ��32λ-4�ֽڴ�С
	//cout << sizeof(b) << endl;

}
int main()
{
	//test1();//�����ض���������ͬ
	//test2();//��̬����д
	//test3();
	test4();
 	system("pause");
	return 0;
}

