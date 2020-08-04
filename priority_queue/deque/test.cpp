#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
namespace xff
{
	
	template<class T,class Container = vector<T>,class compare = Less<T>>
	class priority_queue//Ä¬ÈÏ´ó¶Ñ
	{
	public:
		void Adjustup()
		{
			compare com;
			int child = _con.size() - 1;
			int parent = (child - 1) >> 1;
			while (child)
			{
				if (com(_con[parent],_con[child]))
				{
					::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) >> 1;
				}
				else
				{
					break;
				}
			}
		}
		void Adjustdown()
		{
			compare com;
			int parent = 0;
			int child = 2 * parent + 1;
			while (child<_con.size())
			{
				if (child + 1 < _con.size() && com(_con[child] , _con[child + 1]))
				{
					++child;
				}
				if (com(_con[parent] , _con[child]))
				{
					::swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T&val)
		{
			_con.push_back(val);
			Adjustup();
		}
		void pop()
		{
			::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			Adjustdown();
		}
		const T& top()
		{
			return _con[0];
		}
		const size_t size() 
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};

	template<class T>
	struct Less
	{
		bool operator()(const T& val1,const T& val2)
		{
			return val1 < val2;
		}
	};
	void test_priority_queue()
	{
		priority_queue<int,vector<int>,Less<int>> pq;
		pq.push(1);
		pq.push(9);
		pq.push(2);
		pq.push(4);
		pq.push(0);
		pq.push(-1);
		pq.push(9);
		pq.push(6);
		cout << pq.top() << " " << pq.size() << endl;
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}


#include<deque>
void test_deque() {
	deque<int> dq;
	dq.push_back(3);
	dq.push_back(4);
	dq.push_front(2);
	dq.push_front(1);
	for (int i = 0; i < dq.size(); ++i) {
		cout << dq[i] << " ";
	}
	cout << endl;
	cout << dq.empty() <<" "<<dq.size() << endl;
	cout << dq.front() <<" "<<dq.back() << endl;
}

#include<queue>
#include<functional>
void test_priority_queue()
{
	priority_queue<int,vector<int>,less<int>>pq;
	//priority_queue<int> pq;
	pq.push(1);
	pq.push(9);
	pq.push(2);
	pq.push(4);
	pq.push(0);
	pq.push(-1);
	pq.push(9);
	pq.push(6);
	cout << pq.top() << " " << pq.size() << endl;
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main() {
	//test_deque();
	test_priority_queue();
	xff::test_priority_queue();
	system("pause");
	return 0;
}