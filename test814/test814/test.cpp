#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//���������

//1.ֻ���ڶ��ϴ����Ķ���
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
	
private:
	HeapOnly(){}

	//C++98 ֻ������ʵ��
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
	//HeapOnly hp(*p);//��������ҲҪɾ��������Ȼ��ͨ��Ĭ�Ͽ������죬�������ջ�ϵĶ���
}

//2.ֻ����ջ�ϴ�������
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
	//���캯��˽�л�
	//StackOnly st1(StackOnly::CreateObject());
	//StackOnly* p = new StackOnly;

	//����New
	StackOnly s;
	//StackOnly* p = new StackOnly;
	//ȱ��
	static StackOnly ss;//�ھ�̬��
}

//3.���ܿ���
class CopyBan
{
public:
	CopyBan(){}
private:

	//C++98 ����Ȩ������Ϊ˽��
	//CopyBan(const CopyBan&);
	//CopyBan& operator=(const CopyBan&);

	//C++11		ɾ��Ĭ�Ͽ��������븳ֵ
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator=(const CopyBan&) = delete;
};
void test_copyban()
{
	CopyBan c1;
	//CopyBan c2 = c1;
}

//4.���Լ̳�
class NonInherit //final���ξͲ��ܼ̳���
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
//�����Լ̳�
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
//	/*NewNonInherit(const NonInherit& n = NonInherit::GetInstance())//���ڻ��๹�캯��˽�У��޷����ʣ������޷�ʵ�ֿ�������
//	{
//		cout << "NewNonInherit <- NonInherit" << endl;
//	}*/
//private:
//};

void test_noninherit()
{
	//���Լ̳еİ汾
	//NonInherit n ;
	//NewNonInherit nn(n);

	//�����Լ̳еİ汾
	//NonInherit n = NonInherit::GetInstance();
	//NewNonInherit nn(n);
}

#include<mutex>
#include<thread>
#include<vector>
#include<windows.h>
//����ģʽ һ����ֻ����ȫ��ֻ��һ������
//����ģʽ->�ӳټ���
namespace Lazyman {
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			if (_pinst == NULL) //˫���->       ����ÿ�μ�������ΪֻҪʵ����������֮��Ͳ����ȥ��
			{					//������ҪΪ�˱�����һ�ζ��߳�ʵ������������⣬�������ͻᴴ���������
				_mtx.lock();
				if (_pinst == NULL)
					_pinst = new Singleton;
				_mtx.unlock();
			}
			return _pinst;
		}

		//��������
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
		//C++11ɾ��Ĭ�Ͽ����͸�ֵ
		//Singleton&operator=(const Singleton&) = delete;
		//Singleton(const Singleton&) = delete;
	private:
		Singleton()
		{
			cout << "Singleton() " << endl;
		}
		static Singleton* _pinst;

		//C++98˽�л�Ĭ�Ͽ����͸�ֵ
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

//����ģʽ->main֮ǰ����
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
	Singleton Singleton::_inst; //��main����֮ǰ�������������̰߳�ȫ������
								//ԭ��C�����������main������ʼǰִ�к���, ��gcc�У�����ʹ��attribute�ؼ���

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