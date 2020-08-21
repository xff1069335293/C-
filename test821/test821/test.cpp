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
//1.内置类型列表初始化
void test1()
{
	//内置类型
	int x1(1);
	int x2 = { 2 };

	//数组
	int array1[]{ 1,2,3 };
	int array2[5]={ 1,2,3 };

	//动态数组C++98不支持
	int *arr3 = new int[5]{ 1,2,3,4,5 };
	
	//标准容器
	vector<int> v1{ 1,2,3,4,5 };
	vector<int> v2={ 1,2,3,4,5,6};
	map<string, string> m{ {"left","左"},{"right","右"},{"string","字符串"} };
	for (auto&e : m)
	{cout << e.first << "—>" << e.second << endl;}

	//自定义类型
	test a{ 1,2 };
}
//2.多个列表对象初始化
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

	//RTTI(运行时识别)

	int x = 10;
	int y = 20;
	decltype(x + y) z;
	cout << typeid(z).name() << endl;
}
//3.范围for
//4.final 禁止重写虚函数，进制继承 
//5.override 检查是否重写了虚函数
//6.智能指针shared_ptr
//7.增加了 array  forward_list unordered系列

//8.默认成员函数的控制 未显示定义编译器会自动生成默认版本
//默认生成 构造函数 拷贝构造 运算符重载 析构函数 移动构造 移动拷贝构造 const&/&
//注意：避免删除函数和explicit
//显式缺省
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
	 //A a3(a2);删除拷贝构造就不能完成对象的实例化
 }

 //9.右值引用 纯右值和将亡值
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
	 //C++98中
	 //普通引用只能引用左值
	 int a1 = 10;
	 int& ra1 = a1;
	 //int& ra2 = 10;
	 //const 引用既可以引用左值，也可以引用右值
	 int a2 = 10;
	 const int& ra3 = a2;
	 const int& ra4 = 10;

	 //C++11
	 String s1;
	 String s2("hello");
	 s1 = s2;
	 String s3(s2);
	 String s4;
	 //这里需要又构造了一个临时变量（由于ret是局部变量出了作用域就销毁了）
	 s4 = s2 + s3;
	 String&& s5 = s2 + s3;
 }

 //10.move
 void test6()
 {
	 int a = 10;
	 //int&& ra = a;
	 //将左值转化为右值，就可以实现右值引用了
	 int&& ra = move(a);
	 cout << "a->"<<a<<"  ra->"<< ra <<endl;

	 //move将s1移动为右值时，s2拷贝时就会使用移动构造，s1的资源就会转移到s2
	 string s1("hello");
	 string s2(move(s1));
	 string s3(s2);
	 cout << s1 << endl;
	 cout << s2 << endl;
	 cout << s3 << endl;
 }

 //11.完美转发perfectforward
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
//12.lambda表达式
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
	 //内置类型
	 int array[] = { 4,1,8,5,3,7,0,9,2,6 };
	 std::sort(array, array + sizeof(array) / sizeof(array[0]));

	 std::sort(array, array + sizeof(array) / sizeof(array[0]),greater<int>());
	 for (auto&e : array)
	 {
		 cout << e << " ";
	 }

	 //自定义类型需要自己实现排序规则
	 Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, {"菠萝", 1.5} };
	 sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());
	
	
	//[捕获列表](参数列表)mutable(取消常性,使用这个修饰符时，参数列表不能省略，即使为空)->return-type返回值类型{函数体}
	 //[var]传值捕捉var、[&var]传引用捕捉var、[=]传值捕捉父作用域的变量包括this、
	 //[&]传引用捕捉父作用域的变量包括this、[this]传值捕捉当前this指针
	//最简单的表达式，无意义
	 [] {};

	 //省略参数列表，和返回值的表达式,由编译器推导为int
	 int a = 3, b = 4;
	 [=] {return a + 3; };

	 //省略返回值类型，无返回值类型
	 auto fun1 = [&](int c) {b = a + c; };
	 fun1(10);
	 cout << a<<" "<<b <<endl;

	 //各部分都很完善的lambda表达式
	 auto fun2 = [=, &b](int c)->int {return b += a + c; };
	 cout << fun2(10) << endl;

	  //复制捕捉x
	 int x = 10;
	 auto add_x = [x](int a)mutable {x *= 2; return a + x; };
	 cout << add_x(10) << endl;

	 //函数对象
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