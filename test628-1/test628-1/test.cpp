#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//����ģ��
int add(int x, int y)
{
	return x + y;
}
template<typename T>
T add(const T& x,const T& y)
{
	return x + y;
}
void test1()
{
	int ret = 0;
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	//ret = add(a1, a2);//���ڷ�ģ�庯��ֱ�ӵ��÷Ǻ���ģ�塣
	//ret = add(d1, d2);  //�����ڷǺ���ģ�壬��ʽʵ���������ݲ����Լ�ƥ�䡣
	//ret = add(a1, d2);//�������Ͳ�ͳһʱ�����ܵ��ú���ģ�壬���÷Ǻ���ģ�塣
	//ret = add((double)a1, d2);//ǿת->����ģ��,���Ǻ���ģ������Լ�ת��
	//ret = add<int>(a1, d2);//��ʾʵ����->����ģ��
 	cout << ret << endl;
}
#include<string>
//��ģ��
namespace xff
{
template<class T>
class vector
{
public:
	vector(const T& val = T())
	{
		_val = val;
		cout <<"T->" <<_val << endl;
	}
	~vector()
	{

	}
private:
	T _val;

};
//template<class T>//���ⶨ��ʱҪ��ģ������б�
//vector<T>::~vector()
//{
//
//}
}

void test2()
{
	xff::vector<int> v1(10);
	xff::vector<string> v2("hello");
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}