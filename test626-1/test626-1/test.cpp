#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
static int val1 = 1;//.data ���ݶ�	
int val2 = 2;//.data
void test1()
{
	
	static int val3 = 3;//���ݶ�
	int val4 = 4;//ջ
	int arr1[10] = { 97,2,3,4 };//ջ-����
	char arr2[] = { 'a','b','c','d','e' };//ջ-����
	char arr3[] = "abcde";//ջ-����
	const char* arr4 = "abcde";//���ݶβ����Ը�
	int* arr5 = (int*)malloc(sizeof(int) * 4);//��
	int* arr6 = (int*)realloc(arr5, sizeof(int) * 5);//��
	//cout << "���ݶ�val1->" << &val1 << endl;
	//cout << "���ݶ�val2->" << &val2 << endl;
	//cout << "���ݶ�val3->" << &val3 << endl;
	//cout << "ջval4->" << &val4 << endl;
	//cout << sizeof(val1) << endl;
	//cout << sizeof(val2) << endl;
	//cout << sizeof(val3) << endl;
	//cout << sizeof(val4) << endl;
	//printf("%p\n", arr1);//ָ���һ��Ԫ��
	//printf("%p\n", &arr1+1);//�������������С
	//printf("%c\n",*(arr2+1)-32);//B
	//printf("%p\n", arr2);//ջ
	//printf("%p\n", arr3);//ջ
	//printf("%s\n", arr2);//��\0,������
	//printf("%s\n", arr3);//��\0
	//printf("%p\n", &arr3+1);//�������������С
	//printf("%s", arr1);
	//printf("%c", *arr1);
	//�ַ�������Ļ�������0�����������ڴ��ж�ȡʱ��char��ȡ�����ڴ���97��Ӧ����a��
	//�����������鱾����int���ͣ����Ը�λ0���ڸ�λ�����ͽضϣ�ֱ�������
	//printf("%p\n", arr4);
	//printf("%s\n", arr4);
	//printf("%p\n", &arr5);//ָ��ĵ�ַ��ջ
	//printf("%p\n", &arr5+1);//ָ��ĵ�ַ��ջ+1-��+4
	//printf("%p\n", arr5);//ָ��ָ��Ŀռ��ڶ�
	//printf("%p\n", arr5+1);//ָ��ָ��Ŀռ��ڶ�
	//printf("%p\n", &arr6);//ָ��ĵ�ַ��ջ
	//printf("%p\n", arr6);//ָ��ָ��Ŀռ��ڶ�



	//cout << sizeof(arr1) << endl;//40
	//cout << sizeof(arr2) << endl;//5����
	//cout << sizeof(arr3) << endl;//6����
	//cout << sizeof(arr4) << endl;//4ָ��
	//cout << sizeof(arr5) << endl;//4ָ��
	//cout << sizeof(arr6) << endl;//4ָ��


	//cout << strlen(arr2) << endl;//��ȷ����ȡ���ں���ռ�0��λ��
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
	A* a2 = new A[10];//�Զ������͵��ù��������
	delete[] a2;

}
void test3()
{
	//void* p = new char[0xffffffff];//64λ��
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


