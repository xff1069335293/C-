//ϵͳʵ��
#define _CRT_SECURE_NO_WARNINGS 1;
#include<iostream>
#include<string>
using namespace std;
void Test_string() {
	using namespace std;
	string s1("hello");
	cout << s1 << endl;
	//cout << s1.size() << endl;	//��Ч�ַ�����
	//cout << s1.length() << endl;//��Ч�ַ�����
	//cout << s1.capacity() << endl;//����
	//cout << s1.empty() << endl;//�Ƿ�Ϊ��
	//s1.clear();//�����Ч�ַ���
	//s1.reserve(15);//�ı�������С�ڵ��������Ͳ��䣬���ڵĻ�������
	//s1.resize(1,'!');//������Ч�ַ���n�������߼�С��n������ʱָ���ַ��Ļ��;���ָ���ַ���䣬û��ָ����\0��С����Ч�ַ��Ļ���ɾ����
	s1.push_back('!');
	s1.pop_back();
	s1[0] = 'H';//[]
	//���ֱ�����ʽ
	//for+[]
	for (int i = 0; i < s1.size(); ++i) {
		cout << s1[i] << " ";
	}
	//������
	string::iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it << "-";
		++it;
	}
	//��Χfor
	for (auto& a : s1) {
		cout << (char)(a+1)<< " ";
	}
	s1.append(" world!");//�ַ�����β׷��һ���ַ���
	string str(".cpp");
	s1 += str;	//�ַ�����β׷��һ���ַ���
	cout << s1.c_str() << endl;
	//cout << s1 << endl;
	cout << s1.find('.') << endl;//��λ�������ĳ���ַ������������±ꡣ
	string str1;
	str1=s1.substr(s1.find('.'),s1.size()-1);//
	cout << str1.c_str() << endl;
	//cout << s1.rfind('l') << endl;
	//cout << s1.size() << endl;	//��Ч�ַ�����
	//cout << s1.capacity() << endl;//��Ч�ַ�����
	//getline(cin, str1);
	//cout << str1 << endl;
	//cout << str << endl;
	//cout << operator==(str, s1) << endl;

}

int main() {
	Test_string();
	system("pause");
	return 0;
}