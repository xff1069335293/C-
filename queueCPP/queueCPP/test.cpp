#define _CRT_SECURE_NO_WARNINGS 1
#include<list>
#include<iostream>
#include<string>
using namespace std;
namespace xff {
	template<class T>
	class queue {
	public:
		queue(){}
		~queue(){}
		void push(const T&val)  { _q.push_back(val);  }
		void pop()				{ _q.pop_front();     }
		T& front()				{ return  _q.front(); }
		T& back()				{ return _q.back();	  }
		const T& front()const	{ return  _q.front(); }
		const T& back() const	{ return _q.back();   }
		bool empty()			{ return _q.empty();  }
		const size_t size()const{ return _q.size();   }
	private:
		list<T> _q;
	};
	void mytest() {
		queue<string> q;
		q.push("hello");
		q.push("right");
		q.push("string");
		q.push("left");
		cout << q.front() << " " << q.back() << endl;
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
		cout << q.empty() << " " << q.size() << endl;
	}
}
#include<queue>
void sys_test() {
	queue<string> q;
	q.push("hello");
	q.push("right");
	q.push("string");
	q.push("left");
	cout << q.front() << " " << q.back() << endl;
	while (!q.empty()) {
		cout << q.front() <<" ";
		q.pop();
	}
	cout << endl;
	cout << q.empty() << " " << q.size() << endl;
}
int main() {
	//sys_test();
	xff::mytest();
	system("pause");
	return 0;
}