#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
namespace xff
{
	template<class T>
	class Smartptr
	{
	public:
		Smartptr(T* ptr)
			:_ptr(ptr)
			,_p(new int(1))
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
			if (--*_p == 0 && _ptr)
			{
				delete _ptr;
				cout << "~Smartptr():" << _ptr << endl;
				_ptr = nullptr;
				_p = nullptr;
			}	
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
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
				if (--(*_p) == 0)//如果当前对象还管理着其他资源，要判断去除本次计数之后的数据，考虑释放问题。
				{
					delete _ptr;
					delete _p;
					_p = _ptr = nullptr;
				}
				_ptr = tmp._ptr;
				_p = tmp._p;
				++*_p;
			}
			return *this;
		}
		Smartptr(Smartptr<T>& tmp)
			:_ptr(tmp._ptr)
			,_p(tmp._p)	
		{
			++*_p;
		}
		

	
	private:
		T* _ptr;
		//static int _count;
		//用静态变量的话，同类型多个对象就不能区分了
		int* _p;
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
int main()
{
	//xff::test_Smartptr();
	//test_auto_ptr();
	//xff::test_auto_ptr();

	//test_unique_ptr();
	//xff::test_unique_ptr();

	//test_shared_ptr();
	//xff::test_shared_ptr();

	


	system("pause");
	return 0;
}