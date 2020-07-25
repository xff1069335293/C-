#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
namespace xff
{
	template<class T>
	class stack
	{
	public:
		stack(){}
		~stack(){}
		void push(const T&val) { _s.push_back(val); }
		void pop()			{ _s.pop_back(); }
		T& top()			{ return _s.back(); }
		const T& top()const { return _s.back(); }
		size_t size()const	{ return _s.size(); }
		bool empty()const	{ return _s.empty(); }
	private:
		vector<T> _s;
	};
	void test_my()
	{
		stack<int> s;
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
		while (!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
		cout << s.empty() <<" "<<s.size()<< endl;
	}
}
void test_s_sys()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << s.empty() <<" "<<s.size()<<endl;
	stack<int> s1;
	s1.swap(s);
	cout << s1.top() << endl;
	//cout << s.top() << endl;
}
int main()
{
	//test_s_sys();
	xff::test_my();
	system("pause");
	return 0;
}