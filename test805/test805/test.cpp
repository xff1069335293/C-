#include"fun.hpp"


//�����Ͳ���
template<class T, size_t N = 10>
class Array
{
public:
private:
	T _a[N];
};
void test1()
{
	Array<int> a1;//10
	Array<int,100> a2;//100
}

//����ģ���ػ�
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}

template<>
bool IsEqual<const char*>(const char*& left,const char*& right)
{
	return strcmp(left, right) == 0;
}
	

void test2()
{
	int a = 1, b = 2;
	cout << IsEqual(a, b) << endl;


	const char* p1 = "hello";
	char p3[6] = "hello";
	const char *p2 = p3;
	cout << IsEqual(p1, p2) << endl;
}

//��ģ���ػ�(ȫ�ػ�/ƫ�ػ�)
template<class T1 ,class T2>
class Test
{
public:
	Test()
	{
		cout << "ԭ����->Test<T1,T2>" << endl;
	}
};

//ȫ�ػ�
template<>
class Test<int,char>
{
public:
	Test()
	{
		cout << "ȫ�ػ�->Test<int,char>" << endl;
	}
};

//ȫ�ػ�ָ������
template<class T1, class T2>
class Test<T1*, T2*>
{
public:
	Test()
	{
		cout << "ƫ�ػ�ָ������->TestTest<T1*, T2*>" << endl;
	}
};

//ƫ�ػ���������
template<class T1, class T2>
class Test<T1&, T2&>
{
public:
	Test()
	{
		cout << "ƫ�ػ�������->Test<T1&, T2&>" << endl;
	}
};
//ƫ�ػ�
template<class T>
class Test<int, T>
{
public:
	Test()
	{
		cout << "ƫ�ػ�->Test<int,T>" << endl;
	}
};
void test3()
{
	Test<int, int> t1;
	Test<int, char> t2;
	Test<int, double> t3;
	Test<int*, int*> t4;
	Test<int&, int&> t5;
}


void test4()
{
	int x1 = 1, x2 = 2;
	double d1 = 1.0, d2 = 2.0;
	AddFun1(x1, x2);
	AddFun2(x1, x2);
	AddFun2(d1, d2);
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	system("pause");
	return 0;
}