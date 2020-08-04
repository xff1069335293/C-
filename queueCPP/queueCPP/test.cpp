#define _CRT_SECURE_NO_WARNINGS 1
#include<list>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
namespace xff {
	template<class T,class Container>
	class queue {
	public:
		void push(const T&val)  { _q.push_back(val);  }
		void pop()				{ _q.pop_front();     }
		T& front()				{ return  _q.front(); }
		T& back()				{ return _q.back();	  }
		const T& front()const	{ return  _q.front(); }
		const T& back() const	{ return _q.back();   }
		bool empty()			{ return _q.empty();  }
		const size_t size()const{ return _q.size();   }
	private:
		Container _q;
	};
	void mytest() {
		queue<string,list<string>> q;
		//queue<string, vector<string>> q;//vector中没有pop_front()接口
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
void deque_test()
{
	deque<int> d;
	d.push_back(2);
	d.push_front(1);
	d.push_back(3);
	d.push_back(5);
	cout << d.front() << " " << d.back() << endl;
	deque<int>::iterator pos = find(d.begin(),d.end(),3);
	d.insert(pos, 5);
	for (auto&e : d)
	{
		cout << e << " ";
	}
	cout << endl;
}

#include<time.h>
void test()
{
	deque<int> d;
	vector<int> v;
	const int n = 100000;
	int* a1 = new int[n];
	int* a2 = new int[n];
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		int val = rand();
		d.push_back(val);
		v.push_back(val);
	}
	size_t begin1 = clock();
	sort(d.begin(), d.end());
	size_t end1 = clock(); 

	size_t begin2 = clock();
	sort(v.begin(), v.end());
	size_t end2 = clock();

	cout <<"deque->"<<end1 - begin1 << endl;
	cout << "vector->" << end2 - begin2 << endl;
}
int main() {
	//sys_test();
	//xff::mytest();
	//deque_test();
	test();
	system("pause");
	return 0;
}

