#define _CRT_SECURE_NO_WARNINGS 1
//锁守卫
//异常
#include<string>
#include<iostream>
using namespace std;
double Div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw string("除0错误");//抛出的是临时对象	
	return (double)a / (double)b;
}


#include<mutex>
template<class Lock>
class LockGuard
{
public:
	LockGuard(Lock& lk)
		:_lk(lk)
	{
		cout << "加锁" << endl;
		_lk.lock();
	}
	~LockGuard()
	{
		cout << "解锁" << endl;
		_lk.unlock();
	}
	LockGuard(const LockGuard<Lock>& ld) = delete;
	LockGuard<Lock>operator=(const LockGuard<Lock>& ld) = delete;
private:
	Lock& _lk;  //锁不允许拷贝
};

void Fun1()
{
	/*mutex mtx;
	mtx.lock();

	cout << Div() << endl; //如果抛异常，会造成死锁

	mtx.unlock();*/

	mutex mtx;
	
	LockGuard<mutex> ld(mtx);

	//cout << Div() << endl;
	try
	{
		cout << Div() << endl;
	}
	catch (const string& msg)   //找最近的栈捕获，没有就一层一层找，直到main没有退出
	{							//找到就继续按照当前捕获列表向下执行
		cout << msg << endl;
	}
	/*catch (...)
	{
		cout << "未知异常" << endl;//避免未获取程序崩溃
		throw;
	}*/
	//cout << "Fun1()" << endl;
}
void test1() 
{
	try
	{
		Fun1();
	}
	catch (const string& msg)//捕捉列表可以有多个
	{
		cout << msg << endl;
	}
	catch (...)
	{
		cout << "未知异常"<< endl;//避免未获取程序崩溃
	}
}


void Fun2()//异常安全问题,（资源泄漏）
{
	cout << "new int[100]" << endl;
	cout << Div() << endl;

	/*try
	{
		cout << Div() << endl;
	}
	catch (...)     //解决办法，捕获异常，处理资源问题之后，重新抛出原有异常。
	{
		cout << "delete[] " << endl;
		throw;
	}*/
}
void test2()
{
	try
	{
		Fun2();
	}
	catch (const string& msg)
	{
		cout << msg << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}
}


class Exception 
{
public:
	Exception(const char* errmsg, const int errid)
		:_errid(errid)
		, _errmsg(errmsg)
	{}
	virtual string what() = 0;
protected:
	int _errid;     //错误码
	string _errmsg; //错误描述
};

class SqlException :public Exception
{ 
public:
	SqlException(const char* errmsg, const int errid)
		:Exception(errmsg, errid)
	{}
	string what()
	{
		return "数据库错误: " +_errmsg;
	}
};

class Network :public Exception
{
public:
	Network(const char* errmsg, const int errid)
		:Exception(errmsg, errid)
	{}
	string what()
	{
		return "网络错误:" + _errmsg;
	}
};
void server()
{
	
	int n = 0;
	cin >> n;
	if (n == 1)
		throw SqlException("数据库启动失败\n", 1);
	if (n == 2)
		throw Network("网络连接失败\n", 2);
	else
		throw "  ";
}
void test3()
{
	try {
		server();
		// 抛出对象都是派生类对象
	}
	catch (Exception& e) // 这里捕获父类对象就可以
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
}

void test4()//异常规范
{	
	//抛出多个异常
	//void fun() throw(A，B，C，D);

	//抛出单个异常
	//void fun() throw(A); 
	
	//不抛异常
	//void fun() throw(); //void fun() noexcept;
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	system("pause");
	return 0;
}