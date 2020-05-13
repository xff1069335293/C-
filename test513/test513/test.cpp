//vector基本使用
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using  namespace std;

void test_vector1() {
	vector<int> v;
	v.push_back(1);//尾插
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//3种方法遍历
	/*for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	for (auto& e : v) {
		cout << e << " ";
	}
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		*it += 1;
		cout << *it << " ";
		++it;
	}
	vector<int>::const_iterator it = v.begin();
	while (it != v.end()) {
		
		cout << *it << " ";
		++it;
	}*/
	//v.resize(2);//大补0，小删，改变size，
	//v.reserve(1);	//capacity 扩容最小是size
	v.pop_back();	//尾删
	//vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	//v.insert(pos,999);
	//pos = find(v.begin(), v.end(), 999);
	//v.erase(pos);
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;
	//swap函数
	vector<int> v1;
	v1.push_back(3);
	swap(v1, v);
	//反向遍历打印
	vector<int>::reverse_iterator  rit = v.rbegin();
	while (rit != v.rend()) {
		cout << *rit << " ";
		++rit;
	}
}


int main() {
	test_vector1();
	system("pause");
	return 0;
}