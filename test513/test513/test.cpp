//vector����ʹ��
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using  namespace std;

void test_vector1() {
	vector<int> v;
	v.push_back(1);//β��
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//3�ַ�������
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
	//v.resize(2);//��0��Сɾ���ı�size��
	//v.reserve(1);	//capacity ������С��size
	v.pop_back();	//βɾ
	//vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	//v.insert(pos,999);
	//pos = find(v.begin(), v.end(), 999);
	//v.erase(pos);
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;
	//swap����
	vector<int> v1;
	v1.push_back(3);
	swap(v1, v);
	//���������ӡ
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