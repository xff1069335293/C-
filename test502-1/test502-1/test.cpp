//5.2��Ͷ�����ƪ
#include<iostream>
using namespace std;
//��ʼ���б�
//class B {
//public:
//	B(int a,char b)
//		:_a(a)
//		,_b(b)
//	{
//		cout << "B()" << endl;
//	}
//private:
//	int _a;//4
//	char _b;//1
//};
//class A {
//public:
//	A(int year,int month,int day,int hour,char b,int c)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		,_b(hour,b)
//		,_c(c)
//		,_d(1)
//	
//	{
//		cout << "A()" << endl;
//	}
//	/*class D {///�ڲ���
//	public:
//		D() {
//			_h;//���Է��ʾ�̬��Ա����
//		}
//	private:
//		int _g;
//	};*/
//
//	void Display() {
//		cout << _year << _month << _day << endl;
//	}
//private:
//	int _year;//4
//	int _month;//4
//	int _day;//4
//	static int _h;//4�ھ�̬���������㵽A���С����
//	//�����ʼ���ĳ�Ա����
//	B _b;//�ڴ����֮����8
//	int& _c;//4
//	const int _d;//4
//	
//};
//int A::_h = 1;
//class C
//{
//public:
//	explicit C(int j, int w, int z)
//		//:_f(f)//���� �����޷���ʼ����̬����
//		:_j(j)
//		, _w(w)
//		,_z(z)
//	{}
//	void Display() {
//		cout << _j <<_w<<_z<< endl;
//	}
//private:
//	static int _f;//��̬�������ڣ���̬���洢
//	int _j;
//	int _k;
//	int _w;
//	int _z;
//};
//int C::_f = 1;


//class A {
//public:
//	A() { 
//		cout << "A()" << endl;
//		++_scount;
//	}
//	A(const A& t) { 
//		cout << "A()����" << endl;
//		++_scount; 
//	}
//	static int GetACount() { return _scount; }
//private:
//	static int _scount;
//};
//int A::_scount = 0;
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}
int main() {
	//char a= 'a';
	//A d(0,0,0,a,0,0);
	//d.Display();
	//C c(1,2,3);
	//c.Display();
	//C d = (1,2);
	//d.Display();
	//cout << sizeof(A) << endl;
	//cout << sizeof(C) << endl;//1
	//TestA();
	system("pause");
	return 0;
}
