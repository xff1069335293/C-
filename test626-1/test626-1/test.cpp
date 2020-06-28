#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
static int val1 = 1;//.data 数据段	
int val2 = 2;//.data
void test1()
{
	
	static int val3 = 3;//数据段
	int val4 = 4;//栈
	int arr1[10] = { 97,2,3,4 };//栈-数组
	char arr2[] = { 'a','b','c','d','e' };//栈-数组
	char arr3[] = "abcde";//栈-数组
	const char* arr4 = "abcde";//数据段不可以改
	int* arr5 = (int*)malloc(sizeof(int) * 4);//堆
	int* arr6 = (int*)realloc(arr5, sizeof(int) * 5);//堆
	//cout << "数据段val1->" << &val1 << endl;
	//cout << "数据段val2->" << &val2 << endl;
	//cout << "数据段val3->" << &val3 << endl;
	//cout << "栈val4->" << &val4 << endl;
	//cout << sizeof(val1) << endl;
	//cout << sizeof(val2) << endl;
	//cout << sizeof(val3) << endl;
	//cout << sizeof(val4) << endl;
	//printf("%p\n", arr1);//指向第一个元素
	//printf("%p\n", &arr1+1);//跳过整个数组大小
	//printf("%c\n",*(arr2+1)-32);//B
	//printf("%p\n", arr2);//栈
	//printf("%p\n", arr3);//栈
	//printf("%s\n", arr2);//无\0,烫烫烫
	//printf("%s\n", arr3);//有\0
	//printf("%p\n", &arr3+1);//跳过整个数组大小
	//printf("%s", arr1);
	//printf("%c", *arr1);
	//字符串输出的话，遇到0结束，所以内存中读取时，char读取所以内存中97对应的是a，
	//由于我们数组本来是int类型，所以高位0存在高位，整型截断，直接输出。
	//printf("%p\n", arr4);
	//printf("%s\n", arr4);
	//printf("%p\n", &arr5);//指针的地址在栈
	//printf("%p\n", &arr5+1);//指针的地址在栈+1-》+4
	//printf("%p\n", arr5);//指针指向的空间在堆
	//printf("%p\n", arr5+1);//指针指向的空间在堆
	//printf("%p\n", &arr6);//指针的地址在栈
	//printf("%p\n", arr6);//指针指向的空间在堆



	//cout << sizeof(arr1) << endl;//40
	//cout << sizeof(arr2) << endl;//5数组
	//cout << sizeof(arr3) << endl;//6数组
	//cout << sizeof(arr4) << endl;//4指针
	//cout << sizeof(arr5) << endl;//4指针
	//cout << sizeof(arr6) << endl;//4指针


	//cout << strlen(arr2) << endl;//不确定，取决于后面空间0的位置
	//cout << strlen(arr3) << endl;//5
	//cout << strlen(arr4) << endl;//5
}
class A
{
public:
	A()
		:_data(0)
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _data;
};
void test2()
{
	/*int* arr1 = (int*)malloc(sizeof(int) * 10);
	free(arr1);
	int* arr2 = new int[10];
	delete arr2;*/

	A* a1 = (A*)malloc(sizeof(A) * 10);
	free(a1);
	A* a2 = new A[10];//自定义类型调用构造和析构
	delete[] a2;

}
void test3()
{
	//void* p = new char[0xffffffff];//64位下
	//cout << "new:" << p << endl;
}
void test4()
{
	int* arr1 = (int*)malloc(sizeof(int) * 10);
	int* arr2 = (int*)calloc(10, sizeof(int));
	int* arr3 = (int*)realloc(arr1,0x6fffffff);
	cout << arr1 << endl;
	cout << arr2 << endl;
	cout << arr3 << endl;
	cout << arr1 << endl;
}
void test5()
{
	A* a1 = (A*)malloc(sizeof(A) * 10);
	new(a1) A;
}
int main()
{
	test1();
	//test2();
	//test3();
	//test4();
	//test5();
	system("pause");
	return 0;
}


