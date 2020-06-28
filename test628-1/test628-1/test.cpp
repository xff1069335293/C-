#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//函数模板
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
	//ret = add(a1, a2);//存在非模板函数直接调用非函数模板。
	//ret = add(d1, d2);  //不存在非函数模板，隐式实例化，根据参数自己匹配。
	//ret = add(a1, d2);//参数类型不统一时，不能调用函数模板，调用非函数模板。
	//ret = add((double)a1, d2);//强转->函数模板,而非函数模板可以自己转化
	//ret = add<int>(a1, d2);//显示实例化->函数模板
 	cout << ret << endl;
}
#include<string>
//类模板
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
//template<class T>//类外定义时要加模板参数列表
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