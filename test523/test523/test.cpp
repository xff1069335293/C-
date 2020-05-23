//listʹ��
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<vector>

using namespace std;
void print_list(const list<int> &l) {
	list<int>::const_iterator cit = l.cbegin();
	while (cit != l.cend()) {
		cout << *cit<<" ";
		++cit;
	}
	cout << endl;
}
void list_test() {
	list<int> l1;
	list<int> l2(5, 10);
	list<int> l3(l2);
	list<int> l4(l2.begin(), l2.end());
	/*for (auto& v1 : l1) {
		cout << v1 << endl;
	}
	//��Χfor
	for (auto& v2 : l2) {
		cout << v2;
	}
	//������
	list<int>::iterator it = l3.begin();
	while (it != l3.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//const
	print_list(l4);*/
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(3);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_front(0);
	l1.pop_back();
	list<int>::iterator pos = find(l1.begin(), l1.end(),2);
	if (pos != l1.end()) {
		l1.insert(pos, 2);
		//l1.erase(pos);
	}

	//���������
	list<int>::reverse_iterator rit = l1.rend();
	while (rit != l1.rbegin()) {
		--rit;
		cout << *rit << " ";
		
	}
	cout << endl;
	//ɾ���������ظ��ֻ��һ����Чֵ��
	l1.unique();
	for (auto& v6 : l1) {
		cout << v6 << " ";
	}
	cout << endl;
	/*for (auto& v2 : l2) {
		cout << v2 << " ";
	}
	cout << endl;
	//������������
	l1.swap(l2);
	for (auto& v3 : l1) {
		cout << v3 << " ";
	}
	cout << endl;
	for (auto& v4 : l2) {
		cout << v4 << " ";
	}
	cout << endl;
	//����ͷ����ֵ
	cout << l1.front() << endl;
	//β����ֵ
	cout << l1.back() << endl;
	cout << l1.size() << endl;
	//�������
	l1.clear();
	for (auto& v5 : l1) {
		cout << v5 << " ";
	}
	cout << l1.size() << endl;*/
}
//������ʧЧ����
void vector_test() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 2);
	if (pos != v1.end()) {
		v1.insert(pos, 6);
		//v1.erase(pos);
	}

	//���������
	vector<int>::reverse_iterator rit = v1.rend();
	while (rit != v1.rbegin()) {
		--rit;
		cout << *rit << " ";
	}
	cout << endl;
}

int main() {
	
	list_test();
	//vector_test();
	system("pause");
	return 0;
}