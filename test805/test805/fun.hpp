#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
void AddFun1(int x1, int x2);

template<class T>
void AddFun2(T& x1, T& x2)
{
	cout << "AddFun2->(T& x1, T& x2) " << endl;
}


