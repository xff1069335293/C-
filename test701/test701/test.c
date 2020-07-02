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
		 node* next;//必须加上struct，此时还没重命名
	}node;*/
	/*typedef struct node
	{
		int data;
		struct node* next;
	}node;*/
	/*struct node
	{
		int data;
		struct node next;//不能直接包含自身，引发递归定义了/
	};*/
	/*typedef struct stu//(不声明时为匿名结构体)
	{
		int data;
	}s7;*///重命名
	//s1 s2;//重命名
	//struct stu s2;
	/* struct stu//(不声明时为匿名结构体)
	{
		int data;

	}s5;//定义一个自定义类型的变量
	 s5.data;*/
	 /*struct //(不声明时为匿名结构体)
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
		printf("小端机\n");
	}
	else
	{
		printf("大端机\n");
	}
	printf("%d\n", sizeof(u1));
}
void test4()
{
	enum day
	{
		HOUR,
		MINUTE,//递推
		SECOND=5,//可以给数据大小
	};
	printf("%d\n", HOUR);
	printf("%d\n", MINUTE);
	printf("%d\n", SECOND);
}
int main()
{
	//test1();//结构体
	//test2();//位段(位域)
	//test3();//联合体共用内存空间，大小为数据类型大的所占的空间。
	//test4();//枚举常量
	system("pause");
	return 0;
}