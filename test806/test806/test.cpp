#define _CRT_SECURE_NO_WARNINGS 1
//������
//�쳣
#include<string>
#include<iostream>
using namespace std;
double Div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw string("��0����");//�׳�������ʱ����	
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
		cout << "����" << endl;
		_lk.lock();
	}
	~LockGuard()
	{
		cout << "����" << endl;
		_lk.unlock();
	}
	LockGuard(const LockGuard<Lock>& ld) = delete;
	LockGuard<Lock>operator=(const LockGuard<Lock>& ld) = delete;
private:
	Lock& _lk;  //����������
};

void Fun1()
{
	/*mutex mtx;
	mtx.lock();

	cout << Div() << endl; //������쳣�����������

	mtx.unlock();*/

	mutex mtx;
	
	LockGuard<mutex> ld(mtx);
	try
	{
		cout << Div() << endl;
	}
	catch (const string& msg)   //�������ջ����û�о�һ��һ���ң�ֱ��mainû���˳�
	{							//�ҵ��ͼ������յ�ǰ�����б�����ִ��
		cout << msg << endl;
	}
	catch (const std::exception&e)
	{
		cout << e.what() << endl;
	}
	cout << "Fun1()" << endl;
}
void test1() 
{
	try
	{
		Fun1();
	}
	catch (const string& msg)//��׽�б�����ж��
	{
		cout << msg << endl;
	}
	catch (...)
	{
		cout << "δ֪�쳣"<< endl;//����δ��ȡ�������
	}
}


void Fun2()//�쳣��ȫ����,����Դй©��
{
	cout << "new int[100]" << endl;

	try
	{
		cout << Div() << endl;
	}
	catch (...)     //����취�������쳣��������Դ����֮�������׳�ԭ���쳣��
	{
		cout << "delete[] " << endl;
		throw;
	}
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
		cout << "δ֪�쳣" << endl;
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
	int _errid;     //������
	string _errmsg; //��������
};

class SqlException :public Exception
{

};

class Network :public Exception
{

};
void test3()//
{

}
int main()
{
	//test1();
	//test2();
	system("pause");
	return 0;
}