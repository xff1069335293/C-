#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//特殊类设计

//1.只能在堆上创建的对象
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
	
private:
	HeapOnly(){}

	//C++98 只声明不实现
	//HeapOnly(const HeapOnly&);
public:
	//C++11 delete
	HeapOnly(const HeapOnly&) = delete;
};
#include<memory>
void test_heaponly()
{
	HeapOnly* p = HeapOnly::CreateObject();
	shared_ptr< HeapOnly> sp(HeapOnly::CreateObject());
	//HeapOnly hp(*p);//拷贝构造也要删除掉，不然会通过默认拷贝构造，构造出在栈上的对象
}

//2.只能在栈上创建对象
//class StackOnly 
//{
//public:
//	static StackOnly CreateObject()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly(){}
//};

class StackOnly
{
public:
	StackOnly() {}
private:
	void* operator new (size_t size);
	void operator delete(void* p);
};
void test_stackonly()
{
	//构造函数私有化
	//StackOnly st1(StackOnly::CreateObject());
	//StackOnly* p = new StackOnly;

	//屏蔽New
	StackOnly s;
	//StackOnly* p = new StackOnly;
	//缺陷
	static StackOnly ss;//在静态区
}

//3.不能拷贝
class CopyBan
{
public:
	CopyBan(){}
private:

	//C++98 访问权限设置为私有
	//CopyBan(const CopyBan&);
	//CopyBan& operator=(const CopyBan&);

	//C++11		删除默认拷贝构造与赋值
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator=(const CopyBan&) = delete;
};
void test_copyban()
{
	CopyBan c1;
	//CopyBan c2 = c1;
}

//4.可以继承
class NonInherit //final修饰就不能继承了
{
public:
	NonInherit()
	{
		cout << "NonInherit()" << endl;
	}
	
private:
	
};

class NewNonInherit : public NonInherit
{
public:
	NewNonInherit(const NonInherit& n)
	{
		cout << "NewNonInherit <- NonInherit" << endl;
	}
private:
};
//不可以继承
//class NonInherit
//{
//public:
//	static NonInherit GetInstance()
//	{
//		return NonInherit();
//	}
//private:
//	NonInherit() {cout << "NonInherit()" << endl;}
//
//};
//
//class NewNonInherit : public NonInherit
//{
//public:
//	/*NewNonInherit(const NonInherit& n = NonInherit::GetInstance())//由于基类构造函数私有，无法访问，所以无法实现拷贝构造
//	{
//		cout << "NewNonInherit <- NonInherit" << endl;
//	}*/
//private:
//};

void test_noninherit()
{
	//可以继承的版本
	//NonInherit n ;
	//NewNonInherit nn(n);

	//不可以继承的版本
	//NonInherit n = NonInherit::GetInstance();
	//NewNonInherit nn(n);
}

#include<mutex>
#include<thread>
#include<vector>
#include<windows.h>
//单例模式 一个类只能在全局只有一个对象
//懒汉模式->延迟加载
namespace Lazyman {
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			if (_pinst == NULL) //双检查->       不用每次加锁，因为只要实例化出对象之后就不会进去了
			{					//加锁主要为了保护第一次多线程实例化对象的问题，不加锁就会创建多个对象
				_mtx.lock();
				if (_pinst == NULL)
					_pinst = new Singleton;
				_mtx.unlock();
			}
			return _pinst;
		}

		//垃圾回收
		class CGarbo
		{
		public:
			~CGarbo()
			{
				if (Singleton::_pinst)
				{
					delete Singleton::_pinst;
					_pinst = nullptr;
				}
			}
		};
		static CGarbo Garbo;
		//C++11删除默认拷贝和赋值
		//Singleton&operator=(const Singleton&) = delete;
		//Singleton(const Singleton&) = delete;
	private:
		Singleton()
		{
			cout << "Singleton() " << endl;
		}
		static Singleton* _pinst;

		//C++98私有化默认拷贝和赋值
		Singleton&operator=(const Singleton&);
		Singleton(const Singleton&);

		static mutex _mtx;
	};
	mutex Singleton::_mtx;
	Singleton* Singleton::_pinst = NULL;
	Singleton::CGarbo Garbo;

	void test_singleton()
	{
		Singleton* s1 = Singleton::GetInstance();
		//Singleton s2 = *Singleton::GetInstance();
		/*cout << Singleton::GetInstance() << endl;
		cout << Singleton::GetInstance() << endl;
		cout << Singleton::GetInstance() << endl;*/
		//Singleton s3(*Singleton::GetInstance());
		cout << s1 << endl;
		cout << Singleton::GetInstance() << endl;
		//cout << &s2 << endl;
		//cout << &s3 << endl;
	}
	void test_thread()
	{
		vector<thread> vthreads;
		int n = 50;
		for (int i = 0; i < n; ++i)
		{

			vthreads.push_back(thread([]() {
				Sleep(100);
				cout << Singleton::GetInstance() << endl;

			}));
		}
		for (auto&t : vthreads)
		{
			t.join();
		}
	}
}

//饿汉模式->main之前创建
namespace Hungryman 
{
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			return &_inst;
		}
		Singleton(const Singleton&) = delete;
		Singleton operator=(const Singleton&) = delete;
	private:
		Singleton(){}
		static Singleton _inst;
	};
	Singleton Singleton::_inst; //在main函数之前创建，不存在线程安全的问题
								//原来C语言中如何在main函数开始前执行函数, 在gcc中，可以使用attribute关键字

	void test_singleton()
	{

	}
	void test_thread()
	{
		vector<thread> vthreads;
		int n = 50;
		for (int i = 0; i < n; ++i)
		{

			vthreads.push_back(thread([]() {
				Sleep(100);
				cout << Singleton::GetInstance() << endl;

			}));
		}
		for (auto&t : vthreads)
		{
			t.join();
		}
	}
}
int main() 
{
	//test_heaponly();
	//test_stackonly();
	//test_copyban();
	//test_noninherit();

	//Lazyman::test_singleton();
	//Lazyman::test_thread();	
	
	//Hungryman::test_thread();
	system("pause");
	return 0;
}