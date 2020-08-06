#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
namespace xff
{
	template<class T>
	class Smartptr
	{
	public:
		Smartptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			,_pmutex(new mutex)
		{
			cout << "Smartptr()" << endl;
		}

		/*~Smartptr()
		{
			if (_ptr)
			{
				delete _ptr;
				cout << "~Smartptr():" << _ptr << endl;
				_ptr = nullptr;
				_p = nullptr;
				
			}
		}*/

		//shared_ptr
		~Smartptr()
		{
			/*if (--*_pcount == 0 && _ptr)
			{
				delete _ptr;
				cout << "~Smartptr():" << _ptr << endl;
				_ptr = nullptr;
				_pcount = nullptr;
			}	*/
			release();
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* get_ptr()
		{
			return _ptr;
		}
		//auto_ptr 
		//1.管理权转移  C++98 
		/*Smartptr(Smartptr<T>& tmp)
			:_ptr(tmp._ptr)
		{
			tmp._ptr = nullptr;
		}
		Smartptr<T>& operator=(const Smartptr<T>& tmp)
		{
			if (this != &tmp)
			{
				if(_ptr)
					delete _ptr;
				_ptr = tmp._ptr;
				tmp._ptr = nullptr;
				cout << "~Smartptr():" << _ptr << endl;
			}
			return *this;
		}*/

		//unique_ptr C++11
		//防拷贝，删除默认拷贝构造和赋值
		/*Smartptr<T>& operator=(const Smartptr<T>& tmp)= delete;
		Smartptr(Smartptr<T>& tmp) =delete;*/
		

		//shared_ptr
		//指针计数
		Smartptr<T>& operator=(const Smartptr<T>& tmp)
		{
			if (this != &tmp)
			{
				/*if (--(*_pcount) == 0)//如果当前对象还管理着其他资源，要判断去除本次计数之后的数据，考虑释放问题。
				{
					delete _ptr;
					delete _pcount;
					_pcount = _ptr = nullptr;
					cout << "~Smartptr():" << _ptr << endl;
				}*/
				release();
				_ptr = tmp._ptr;
				_pcount = tmp._pcount;
				_pmutex = tmp._pmutex;

				add_ref_count();
			}
			return *this;
		}
		Smartptr(Smartptr<T>& tmp)
			:_ptr(tmp._ptr)
			, _pcount(tmp._pcount)
			,_pmutex(tmp._pmutex)
		{
			add_ref_count();
		}
		int use_count()
		{
			return *_pcount;
		}
		void add_ref_count()
		{
			_pmutex->lock();
			++(*_pcount); 
			_pmutex->unlock();
		}
		void  release()
		{
			bool flag = false;
			_pmutex->lock();

			if (--(*_pcount) == 0)
			{
				cout << "~Smartptr():" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;

				delete _pcount;
				_pcount = nullptr;
				flag = true;
			}
			_pmutex->unlock();
			if (flag == true)
			{
				delete _pmutex;
				_pmutex = nullptr;
			}
		}
	private:
		T* _ptr;
		//static int _count;
		//用静态变量的话，同类型多个对象就不能区分了
		int* _pcount;
		mutex* _pmutex;
	};
	//template<class T>
	//int Smartptr<T>::_count = 1;
	void test_Smartptr()
	{
		int *p1 = new int(1);
		Smartptr<int> pi1(p1);
		*pi1 = 10;
		cout << *p1 << " " << *pi1 << endl;

		Smartptr<pair<int,int>> pi2(new pair<int, int>);
		pi2->first = 10;
		pi2->second = 20;
		cout << pi2->first <<" "<<pi2->second << endl;
	}

	void test_auto_ptr()
	{
		int *p1 = new int(1);
		Smartptr<int> pi1(p1);
		*pi1 = 10;
		cout << *p1 <<" "<< *pi1 << endl;
		
		//Smartptr<int> pi2 = pi1;
		//Smartptr<int> pi3(pi1);
	}

	void test_unique_ptr()
	{
		int* pi = new int(10);
		Smartptr<int> pi1(pi);
		//unique_ptr<int> pi2(pi1);
		//unique_ptr<int> pi3 = pi1;
	}

	void test_shared_ptr() 
	{
		int *p1 = new int(1);
		Smartptr<int> pi1(p1);
		*pi1 = 10;
		cout << *p1 << " " << *pi1 << endl;
		Smartptr<int> pi2 = pi1;
		Smartptr<int> pi3(pi1);
		Smartptr<int> pi4(pi1);


		Smartptr<int> pi5(new int);
		Smartptr<int> pi6(pi5);
	}

	void test_thread()
	{
		Smartptr<int> sp(new int);
		cout << sp.use_count() << endl;
		int n = 100000;
		thread t1([&]() {
			for (int i = 0; i < n; ++i)
			{ 
				Smartptr<int> sp1(sp);
			}
		});

		thread t2([&]() {
			for (int i = 0; i < n; ++i)
			{
				Smartptr<int> sp2(sp);
			}	
		});

		t1.join();
		t2.join();
		cout << sp.use_count() << endl;
	}
}


#include<memory>
void test_auto_ptr()
{
	int* pi = new int(10);
	auto_ptr<int> pi1(pi);
	auto_ptr<int> pi2(pi1);
	auto_ptr<int> pi3= pi1;
}
void test_unique_ptr()
{
	int* pi = new int(10);
	unique_ptr<int> pi1(pi);
	//unique_ptr<int> pi2(pi1);
	//unique_ptr<int> pi3 = pi1;
}
void test_shared_ptr()
{
	int *p1 = new int(1);
	shared_ptr<int> pi1(p1);
	*pi1 = 10;
	cout << *p1 << " " << *pi1 << endl;
	shared_ptr<int> pi2 = pi1;
	shared_ptr<int> pi3(pi1);
	shared_ptr<int> pi4(pi1);


	shared_ptr<int> pi5(new int);
	shared_ptr<int> pi6(pi5);
}

class A
{
public:

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

template<class T>//定制删除器
struct deleteArray
{
	void operator()(T* pa)
	{
		delete[] pa;
		pa = nullptr;
	}
};
void test_A()
{
	shared_ptr<A> sp1(new A);
	shared_ptr<A> sp2(new A[10],deleteArray<A>());
}

template<class T>
class Weak_ptr
{
public:
	Weak_ptr() 
	{
		cout << "Weak_ptr()" << endl;
	}
	Weak_ptr(const xff::Smartptr<T>& sp)
		:_ptr(sp.get_ptr())
	{
		
	}
	Weak_ptr<T>&operator=(xff::Smartptr<T>& sp)
	{
		_ptr = sp.get_ptr();
		return *this;
	}
	~Weak_ptr()
	{
		cout << "~Weak_ptr()" << endl;
	}
	T* operator->()
	{
		return _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
private:
	T* _ptr;
};
class ListNode
{
public:
	ListNode()
	{
		cout << "ListNode()" << endl;
	}

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
	int _val;
	//shared_ptr<ListNode> _spnext;
	//shared_ptr<ListNode> _spprev;

	Weak_ptr<ListNode> _spnext;
	Weak_ptr<ListNode> _spprev;
};

void test_ListNode()//循环引用问题
{
	xff::Smartptr<ListNode> sp1(new ListNode);
	xff::Smartptr<ListNode> sp2(new ListNode);
	
	sp1->_spnext = sp2;
	sp2->_spprev = sp1;
	
}

int main()
{
	//xff::test_Smartptr();
	//test_auto_ptr();
	//xff::test_auto_ptr();

	//test_unique_ptr();
	//xff::test_unique_ptr();

	//test_shared_ptr();
	//xff::test_shared_ptr();

	//xff::test_thread();//线程安全问题
	//test_ListNode();//weak_ptr

	test_A();



	system("pause");
	return 0;
}