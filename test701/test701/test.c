#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#pragma pack(n) //n=1 2 4 8 16
void test1()
{
	typedef struct
	{
		int i;
	}s;
	typedef struct 
	{
		char c1;//1
		char c2;//1
		int i;//4
	}s1;//8
	typedef struct 
	{
		char c1;//1
		int i;//4
		char c2;//1
	}s2;//12
	typedef struct 
	{
		char c2;//1
		double d;//8
		int i;//4
	}s3;//24
	typedef struct
	{
		char c1;//1
		s s;//4
		double i;//8
	}s8;//16
	typedef struct 
	{
		char c1;//1
		s1 s1;//8
		int i;//4
	}s4;//16
	typedef struct
	{
		char c1;//1
		int i;//4
		s3 s3;//24
	}s7;//32
	printf("s->%d\n", sizeof(s));
	printf("s1->%d\n", sizeof(s1));
	printf("s2->%d\n", sizeof(s2));
	printf("s3->%d\n", sizeof(s3));
	printf("s4->%d\n", sizeof(s4));
	printf("s7->%d\n", sizeof(s7));
	printf("s8->%d\n", sizeof(s8));
	printf("char->%d\n", sizeof(char));//1
	printf("short->%d\n", sizeof(short));//2
	printf("int->%d\n", sizeof(int));//4
	printf("long->%d\n", sizeof(long));//4
	printf("char*->%d\n", sizeof(char*));//4
	printf("double->%d\n", sizeof(double));//8
	printf("long long->%d\n", sizeof(long long));//8

	/*typedef struct node
	{
		int data;
		 node* next;//�������struct����ʱ��û������
	}node;*/
	/*typedef struct node
	{
		int data;
		struct node* next;
	}node;*/
	/*struct node
	{
		int data;
		struct node next;//����ֱ�Ӱ������������ݹ鶨����/
	};*/
	/*typedef struct stu//(������ʱΪ�����ṹ��)
	{
		int data;
	}s7;*///������
	//s1 s2;//������
	//struct stu s2;
	/* struct stu//(������ʱΪ�����ṹ��)
	{
		int data;

	}s5;//����һ���Զ������͵ı���
	 s5.data;*/
	 /*struct //(������ʱΪ�����ṹ��)
	 {
		 int data;
	 }s6;
	 s6.data;*/
}
void test2()
{
	struct A
	{
		int _b : 5;//4
		int _c : 4;//4
	};//4
	struct B
	{
		char _a : 3;
		char _b : 4;//1
		char _c : 5;//2
		int _d : 5;//4
	};//8
	struct C
	{
		char _a : 3;
		char _b : 4;//1
		char _c1 : 5;//2
		char _c2 : 5;//3
		char _c3 : 5;//4
		char _c4 : 5;//5
		int _d : 5;//9
	};//12
	printf("%d\n",sizeof(struct A));//4
	printf("%d\n", sizeof(struct B));//8
	printf("%d\n", sizeof(struct C));//12
}
void test3()
{
	union un1
	{
		char c;
		int i;
	}u1;
	union un2
	{
		char c[5];
		int i;
	}u2;
	printf("%d\n", sizeof(u1));//4
	printf("%d\n", sizeof(u2));//8
	u1.i = 1;
	if (u1.c == 1)
	{
		printf("С�˻�\n");
	}
	else
	{
		printf("��˻�\n");
	}
	printf("%d\n", sizeof(u1));
}
void test4()
{
	enum day
	{
		HOUR,
		MINUTE,//����
		SECOND=5,//���Ը����ݴ�С
	};
	printf("%d\n", HOUR);
	printf("%d\n", MINUTE);
	printf("%d\n", SECOND);
}
int main()
{
	//test1();//�ṹ��
	//test2();//λ��(λ��)
	//test3();//�����干���ڴ�ռ䣬��СΪ�������ʹ����ռ�Ŀռ䡣
	//test4();//ö�ٳ���
	system("pause");
	return 0;
}