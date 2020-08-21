#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
class test
{
public:
	test(int a,int b)
		:_a(a)
		,_b(b)
	{
		cout << _a<<" "<<_b << endl;
	}
private:
	int _a;
	int _b;
};
//1.���������б��ʼ��
void test1()
{
	//��������
	int x1(1);
	int x2 = { 2 };

	//����
	int array1[]{ 1,2,3 };
	int array2[5]={ 1,2,3 };

	//��̬����C++98��֧��
	int *arr3 = new int[5]{ 1,2,3,4,5 };
	
	//��׼����
	vector<int> v1{ 1,2,3,4,5 };
	vector<int> v2={ 1,2,3,4,5,6};
	map<string, string> m{ {"left","��"},{"right","��"},{"string","�ַ���"} };
	for (auto&e : m)
	{cout << e.first << "��>" << e.second << endl;}

	//�Զ�������
	test a{ 1,2 };
}
//2.����б�����ʼ��
#include<initializer_list>
template<class T>
class Vector
{
public:
	Vector(initializer_list<T> l)
		:_capacity(l.size())
		,_size(0)
	
	{
		_array = new T[_capacity];
		for (auto e : l)
			_array[_size++] = e;
	}
	Vector<T>& operator=(initializer_list<T> l) {
		delete[] _array;
		size_t i = 0;
		for (auto e : l)
			_array[i++] = e;
		return *this;
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};
void test2()
{
	vector<int> v{ 1,2,3,4,5 };
	auto ils1 = { 1,2,3,4,5 };
	Vector<int> v1(ils1);
}
void test3()
{
	short a = 32670;
	short b = 32670;
	short c = a + b;
	cout << c << endl;
	cout << typeid(c).name() << endl;

	auto d = a + b;
	cout << d << endl;
	cout << typeid(d).name() << endl;

	//RTTI(����ʱʶ��)

	int x = 10;
	int y = 20;
	decltype(x + y) z;
	cout << typeid(z).name() << endl;
}
//3.��Χfor
//4.final ��ֹ��д�麯�������Ƽ̳� 
//5.override ����Ƿ���д���麯��
//6.����ָ��shared_ptr
//7.������ array  forward_list unorderedϵ��

//8.Ĭ�ϳ�Ա�����Ŀ��� δ��ʾ������������Զ�����Ĭ�ϰ汾
//Ĭ������ ���캯�� �������� ��������� �������� �ƶ����� �ƶ��������� const&/&
//ע�⣺����ɾ��������explicit
//��ʽȱʡ
class A
{
public:
	A() = default;
	A(int a)
		:_a(a)
	{
		cout <<"A(int a)" << endl;
	}
	A(const A&) = delete;
	A& operator=(const A&);
private:
	int _a;
};
 A& A::operator=(const A& a) = default;
 void test4()
 {
	 A a1;
	 A a2(10);
	 a1 = a2;
	 //A a3(a2);ɾ����������Ͳ�����ɶ����ʵ����
 }

 //9.��ֵ���� ����ֵ�ͽ���ֵ
#include<string.h>
 class String
 {
 public:
	 String(const char* str = "")
	 {
		 cout<<"String"<<endl;
		 if (nullptr == str)
			 str = "";
		 _str = new char[strlen(str) + 1];
		 strcpy(_str, str);
	 }
	 String(const String& s)
		 :_str(new char[strlen(s._str) + 1])
	 {
		 cout << "String(const String& s)" << endl;
		 strcpy(_str, s._str);
	 }
	 String& operator=(const String& s)
	 {
		 cout << "String& operator=(const String& s)" << endl;
		 if (this != &s)
		 {
			 char *ptmp = new char[strlen(s._str) + 1];
			 strcpy(ptmp, s._str);
			 delete[] _str;
			 _str = ptmp;
		 }
		 return *this;
	 } 
	String operator+(const String& s)
	 {
		 char *ptmp = new char[strlen(s._str)+strlen(_str) + 1];
		 strcpy(ptmp, _str);
		 strcpy(ptmp+strlen(_str), s._str);
		 String ret(ptmp);
		 return ret;
	 }
	String(String&& s)
		:_str(s._str)
	{
		s._str = nullptr;

	}
	 ~String()
	 {
		 cout << "~String()" << endl;
		 if (_str)
		 {
			 delete[] _str;
			 _str = nullptr;
		 }
	 }
 private:
	 char* _str;
 };
 void test5()
 {
	 //C++98��
	 //��ͨ����ֻ��������ֵ
	 int a1 = 10;
	 int& ra1 = a1;
	 //int& ra2 = 10;
	 //const ���üȿ���������ֵ��Ҳ����������ֵ
	 int a2 = 10;
	 const int& ra3 = a2;
	 const int& ra4 = 10;

	 //C++11
	 String s1;
	 String s2("hello");
	 s1 = s2;
	 String s3(s2);
	 String s4;
	 //������Ҫ�ֹ�����һ����ʱ����������ret�Ǿֲ���������������������ˣ�
	 s4 = s2 + s3;
	 String&& s5 = s2 + s3;
 }

 //10.move
 void test6()
 {
	 int a = 10;
	 //int&& ra = a;
	 //����ֵת��Ϊ��ֵ���Ϳ���ʵ����ֵ������
	 int&& ra = move(a);
	 cout << "a->"<<a<<"  ra->"<< ra <<endl;

	 //move��s1�ƶ�Ϊ��ֵʱ��s2����ʱ�ͻ�ʹ���ƶ����죬s1����Դ�ͻ�ת�Ƶ�s2
	 string s1("hello");
	 string s2(move(s1));
	 string s3(s2);
	 cout << s1 << endl;
	 cout << s2 << endl;
	 cout << s3 << endl;
 }

 //11.����ת��perfectforward
 void Fun(int &x) { cout << "lvalue ref" << endl; }
 void Fun(int &&x) { cout << "rvalue ref" << endl; }
 void Fun(const int &x) { cout << "const lvalue ref" << endl; }
 void Fun(const int &&x) { cout << "const rvalue ref" << endl; }
 template<class T>
 void  perfectforward(T&& t)
 {
	 Fun(std::forward<T>(t)); 
 }
 void test7()
 {
	 perfectforward(10);

	 int a;
	 perfectforward(a);
	 perfectforward(move(a));

	 const int b = 10;
	 perfectforward(b);
	 perfectforward(move(b));

 }
//12.lambda���ʽ
#include<algorithm>
#include<functional>
 struct Goods
 {
	 string _name;
	 double _price; 
 };
 struct Compare
 {
	 bool operator()(const Goods& gl, const Goods& gr)
	 {
		 return gl._price <= gr._price;
	 }
 };

 class Rate
 {
 public:
	 Rate(double rate) : _rate(rate)
	 {}
	 double operator()(double money, int year)
	 {
		 return money * _rate * year;
	 }
 private:
	 double _rate;
 };

 void test8()
 {
	 //��������
	 int array[] = { 4,1,8,5,3,7,0,9,2,6 };
	 std::sort(array, array + sizeof(array) / sizeof(array[0]));

	 std::sort(array, array + sizeof(array) / sizeof(array[0]),greater<int>());
	 for (auto&e : array)
	 {
		 cout << e << " ";
	 }

	 //�Զ���������Ҫ�Լ�ʵ���������
	 Goods gds[] = { { "ƻ��", 2.1 }, { "�ཻ", 3 }, { "����", 2.2 }, {"����", 1.5} };
	 sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());
	
	
	//[�����б�](�����б�)mutable(ȡ������,ʹ��������η�ʱ�������б���ʡ�ԣ���ʹΪ��)->return-type����ֵ����{������}
	 //[var]��ֵ��׽var��[&var]�����ò�׽var��[=]��ֵ��׽��������ı�������this��
	 //[&]�����ò�׽��������ı�������this��[this]��ֵ��׽��ǰthisָ��
	//��򵥵ı��ʽ��������
	 [] {};

	 //ʡ�Բ����б��ͷ���ֵ�ı��ʽ,�ɱ������Ƶ�Ϊint
	 int a = 3, b = 4;
	 [=] {return a + 3; };

	 //ʡ�Է���ֵ���ͣ��޷���ֵ����
	 auto fun1 = [&](int c) {b = a + c; };
	 fun1(10);
	 cout << a<<" "<<b <<endl;

	 //�����ֶ������Ƶ�lambda���ʽ
	 auto fun2 = [=, &b](int c)->int {return b += a + c; };
	 cout << fun2(10) << endl;

	  //���Ʋ�׽x
	 int x = 10;
	 auto add_x = [x](int a)mutable {x *= 2; return a + x; };
	 cout << add_x(10) << endl;

	 //��������
	 double rate = 0.49;
	 Rate r(rate);
	 cout << r(0.5,100) << endl;

	 //lambda
	 auto r2 = [=](double money, int year)mutable->double {return money * rate*year; };
	 double&& ret = r2(0.5, 100);
	 cout << ret << endl;
 }
int main()
{
	//test1();
	test2();
	///test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	system("pause");
	return 0;
}