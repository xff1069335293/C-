#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<functional>//greater<T>()降序,less<T>()升序
#include<algorithm>
#include<assert.h>
using namespace std;
namespace xff
{
	template<class T>
	 struct _list_node 
	{
		 _list_node(const T& x=T())
			 :_prev(nullptr)
			 ,_next(nullptr)
			 ,_data(x)
		 {}
		 _list_node<T>* _prev;
		 _list_node<T>* _next;
		 T _data;
	};

	 template<class T, class Ref, class Ptr>
	 struct _list_iterator
	 {
		 typedef _list_node<T> Node;
		 typedef _list_iterator<T, Ref, Ptr> Self;
		 Node* _node;
		 _list_iterator(Node* node)
			 :_node(node)
		 {}
		 Ref operator*()
		 {
			 return _node->_data;
		 }
		 Ptr operator->()
		 {
			 return &_node->_data;
		 }
		 Self& operator++()
		 {
			 _node = _node->_next;
			 return *this;
		 }
		 bool operator!=(const Self& it)
		 {
			 return _node != it._node;
		 }
	 };

	 struct Date
	 {
		 int _year = 1900;
		 int _month = 1;
		 int _day = 1;
	 };

	template<class T>
	class list
	{
	public:
		typedef _list_node<T> Node;
		typedef _list_iterator<T,T&,T*> iterator;
		typedef _list_iterator<T,const T&,const T*> const_iterator;
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}

		 const_iterator cbegin() const
		{	
			return const_iterator(_head->_next);
		}
		const_iterator cend() const
		{
			return const_iterator(_head);
		}
	public:
		//创建结点
		void create()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
		}

		//构造
		list()
			:_head(nullptr)
		{
			create();
		}
		//拷贝构造
		list(const list<T>& ls)
		{
			create();
			const_iterator cit = ls.cbegin();
			while (cit != ls.cend())
			{
				push_back(*cit);
				++cit;
			}
		}
		/*list<T>& operator=(const list<T>& ls)
		{
			if (this != &ls)
			{
				list<T> tmp(ls);//现代写法
				swap(tmp);
				
				//clear();
				//for (auto e:ls)
				//{
				//	push_back(e);
				//}
				
			}
			return *this;
		}*/
		//赋值
		list<T>& operator=( list<T> ls)
		{
			std::swap(_head, ls._head);
			return *this;
		}
		//析构
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		//前插
		iterator  insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(val);
			newnode->_next = cur;
			newnode->_prev = prev;
			prev->_next = newnode;
			cur->_prev = newnode;
			return iterator(newnode);
		}
		//删除当前结点
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* next = cur->_next;

			cur->_prev->_next = next;
			next->_prev = cur->_prev;
			delete cur;
			return iterator(next);
		}
		//尾插
		void push_back(const T&	x)
		{
			insert(end(), x);
			/*Node* cur = new Node(x);
			Node* tail = _head->_prev;
			tail->_next = cur;
			cur->_prev = tail;
			cur->_next = _head;
			_head->_prev = cur;*/
		}
		//头插
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		//尾删
		void pop_back()
		{
			//erase(--end());
			erase(_head->_prev);
		}
		//头删
		void pop_front()
		{
			erase(begin());
		}
		
		//是否为空
		bool empty()
		{
			return _head == _head->_next;
		}
		//清空
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}

		}
		//交换
		void swap( list<T>& ls)
		{
			::swap(_head, ls._head);
		}
		//返回结点个数
		size_t size()const
		{
			size_t count = 0;
			const_iterator it = cbegin();
			while (it != cend())
			{
				++count;
				++it;
			}
			return count;
		}
		//返回尾部节点的值
		T& back() const
		{
			assert(_head->_next != _head);
			return _head->_prev->_data;
		}
		//返回尾部节点的值
		T& front() const
		{
			assert(_head->_next != _head);
			return _head->_next->_data;
		}
		void printf()
		{
			const_iterator it = cbegin();
			while (it != cend())
			{
				cout << *it <<" ";
				++it;
			}
			cout << endl;
		}
	private:
		Node* _head;
	};
	void test1()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		/*
		l.push_front(4);
		l.push_front(3);
		l.push_front(2);
		l.push_front(1);
		*/
		l.printf();
		/*list<int>::iterator lit = l.begin();
		while (lit != l.end())
		{
			cout << *lit << " ";
			++lit;
		}
		cout << endl;*/
		/*list<int>::const_iterator lit = l.cbegin();//const迭代器
		while (lit != l.cend())
		{
			
			cout << *lit << " ";
			++lit;
		}
		cout << endl;*/
	}
	
	void test2()
	{
		Date* d = new Date;
		d->_day;
		list<Date> lt;
		lt.push_back(Date());
		lt.push_back(Date());
		list<Date>::iterator it = lt.begin();
		list<Date>::iterator end = lt.end();
		while (it != end)
		{
			cout << (*it)._year << " " << (*it)._month << " " << (*it)._day <<endl;
			//cout << it->_year << " " << it->_month << " " << it->_day <<endl;
			++it;
		}
		cout<<endl;
	}

	void test3()
	{
		list<int> ls;
		ls.push_back(3);
		ls.push_back(4);
		ls.push_back(6);
		//ls.printf();
		ls.push_front(2);
		ls.push_front(1);
		//list<int>::iterator it = ls.begin();
		//ls.erase(it);
		//cout << ls.front() <<" "<<ls.back()<<" "<<ls.size()<< endl;
		//ls.clear();
		ls.printf();

		list<int> ls1(ls);
		ls1.printf();
		ls1.push_back(7);
		ls1.push_back(8);
		ls1.push_back(9);
		
		list<int> ls3;
		ls3 = ls1;
		ls3.printf();

		ls3.swap(ls);
		ls3.printf();

		ls3.pop_back();
		ls3.printf();

		ls3.pop_front();
		ls3.printf();
		cout << ls3.empty() << endl;
		ls3.pop_front();
		ls3.pop_front();
		ls3.pop_front();
		ls3.printf();

		cout << ls3.empty() << endl;
	}
	
}
#include<list>
void test()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	list<int> l2(l1);//拷贝构造
	list<int> l3(l2.begin(), l2.end());
	list<int> l4(2, 10);
	//l1 = l4;
	//l1.swap(l4);//链表内容交换
	//list<int>::iterator pos = find(l1.begin(),l1.end(),3);
	//l1.erase(pos);
	//l1.erase(l1.begin(), --l1.end());//物理上非连续存储不能直接通过+来控制范围
	//l1.insert(pos, 5);
	//l1.pop_back();//尾删
	//l1.pop_front();//头删
	l1.push_back(5);//尾插
	l1.push_front(0);//头插
	//l1.resize(10,6);//大于原来的没写就补0，不然就补data
	//l1.resize(2);//删除到当前大小
	//l1.clear();//清空链表
	//l1.unique();//删除连续相同的数据，12355-》1235||12535 -》12535
	//l1.sort(greater<int>());//降序，（sort）默认升序
	//l1.reverse();//逆置
	//std::sort(l1.begin(), l1.end());//std库里面的sort适用于连续存储的空间排序，默认升序。
	//cout << l1.front() << " " << l1.back() << endl;//返回头部/尾部数据
	//l1.emplace(l1.begin(),100);//和insert类似，但是避免产生了临时变量
	//l1.remove(6);//删除val，调用该对象的析构
	cout << l1.size() <<" "<< l1.empty()<< endl;//输出数据个数/是否为空
	for (auto& e : l1)
	{
		cout << e <<" ";
	}
	/*list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << *it <<" ";
		++it;
	}
	cout << endl;*/

}
int main()
{
	//xff::test1();//迭代器接口测试
	//xff::test2();//自定义类型
	//xff::test3();//自己实现接口测试
	//test();//系统接口
	system("pause");
	return 0;
}