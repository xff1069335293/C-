#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//���μ̳�-�����������������������,����������ŵ�β����������ƫ������
class per
{
public:
	int _num1=2;
	
};

class stu:virtual public per
{
public:
	int _num2=2;
};

class teach :virtual  public per
{
public:
	int _num3=3;

};
class ass : public stu,  public teach
{
public:
	int _num4=4;
};
void test6()
{
	per p;
	//cout << p._num1 << endl;
	stu s;
	//cout << s._num1 << s._num2 << endl;
	teach t;
	//cout << t._num1 << t._num3 << endl;
	ass a;
	a.stu::_num1;
	a.teach::_num1;
	a._num1;
	//cout <<a.stu::_num1 << a._num2 << a._num3 << a._num4 << endl;
	printf("%p", *(int*)&a);
}

/*

void test1()
{
	stu s;
	//cout << s._num << endl;
	per p;
	//cout << p._num << endl;
	p = s;
	//cout << p._num << endl;
	//s = p;
	per*pp = &s;
	pp->_num = 20;
	cout << pp->_num << endl;
	stu*ss = (stu*)&p;
	//ss->_num = 10;
	cout << ss->_num << endl;
}

//������д
class A
{
public:
	void fun()
	{
		cout << "fun()" << endl;
	}
};

class B :public A
{
public:
	void fun(int i = 1)
	{
		A::fun();
		cout << "fun(int i)->" <<i<< endl;
	}
};
void test2()
{
	B b;
	b.fun(10);
	A a;
	//a.fun();
		
}
//Ĭ�ϳ�Ա����
#include<string>
class per
{
public:
	per(const char* name="peter")
		:_name(name)
	{
		cout << "per()" << endl;
	}
	~per()
	{
		cout << "~per()" << endl;

	}
	per(const per& p)
		:_name(p._name)
	{
		cout << "per(const per& p)" << endl;
	}
	per& operator =(const per& p)	
	{
		cout << "per& operator =(const per& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}
protected:
	string _name;

};
class stu :public per
{
	
	public:
		stu(const char*name,int num)
			:per(name)
			,_num(num)
		{
			cout << "stu()" << endl;
		}
		~stu()
		{
			cout << "~stu()" << endl;
		}
		stu(const stu& s)
			:_num(s._num)
			,per(s)
		{
			cout << "stu(const stu& s)" << endl;
		}
		stu& operator =(const stu& s)
		{
			cout << "stu& operator =(const stu& s)" << endl;
			if (this != &s)
			{
				per::operator=(s);//�����ͨ�����࣬�ͻ���ɵݹ������
				_num = s._num;
			}
			return *this;
		}
protected:
	int _num;
};
void test3()
{
	stu s1("jack", 18);
	stu s2(s1);
	stu s3("rose", 17);
	s1 = s3;
}
//��Ԫ��ϵ���̳�
#include<string>
class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name; // ����
};
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
void Display(const Person& p, const Student& s) {
	cout << p._name << endl;
	cout << s._stuNum << endl;//��Ԫ��ϵ���̳�
}
void test4()
{
	Person p;
	Student s;
	Display(p, s);
}
//static��̬��Աֻ��һ��
class per
{
public:
	 static int _num;
};
int per::_num = 1;
class stu :public per
{

};
class gra :public stu
{

};
void test5()
{
	per p1;
	stu s1;
	gra g4;
	cout << p1._num << endl;
	s1._num = 10;
	cout << s1._num<< endl;
	cout << p1._num << endl;
	cout << g4._num << endl;
	cout << per::_num << endl;
	cout << stu::_num << endl;
}*/
int main()
{
	//test1();
	//test2();
	//test3();
	//test4()
	//test5();
	test6();
	system("pause");
	return 0;
}