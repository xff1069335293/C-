#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
namespace xff
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin() { return _start; }
		iterator end()	 { return _finish; }
		const_iterator cbegin()const { return _start; }	
		const_iterator cend()const	 { return _finish; }
		

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			,_endofstorage(nullptr)
		{}
		vector(int n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			resize(n, value);
		}
		template<class Inputiterator>
		vector(Inputiterator first, Inputiterator last)
		{
			size_t newcapacity = last - first;
			reserve(newcapacity);
			while (last != first)
			{
				push_back(*first);
				++first;
			}
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start =_finish =_endofstorage= nullptr;
			}
		}
		//v(v1)
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			auto it = begin();
			auto vit = v.cbegin();
			while (vit != v.cend())
			{
				*it++ = *vit++;
			}
			_finish = it;
		}
		//v=v1
		vector<T>& operator=(const vector<T>& v)
		{
			vector<T> v1(v);
			swap(v1);
			return *this;
		}
		//[]
		const T& operator[](size_t pos)
		{
			size_t oldsize = size();
			assert(pos < oldsize);
			return _start[pos];
		}
		const T& operator[](size_t pos)const { return _start[pos]; }
		void push_back(const T& x)
		{
			size_t oldcapactiy = capacity();
			size_t oldsize = size();
			if (oldsize == oldcapactiy)
			{
				size_t newcapacity = oldcapactiy == 0 ? 2 : 2 * oldcapactiy;
				reserve(newcapacity);
			}
			_start[oldsize++] = x;
			_finish = _start + oldsize;
		}
		const T front()const{return *_start;}
		const T back() {return *--_finish;}
		const size_t size()const{return _finish - _start;}
		const size_t capacity()const{return _endofstorage - _start;}
		bool empty()
		{
			if (_start == _finish)
				return true;
			return false;
		}
		void clear()
		{
			_finish=_start;
		}
		void pop_back()
		{
			if (_start != _finish)
				--_finish;
		}
		//
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		void reserve(size_t n)
		{
			size_t oldcapacity = capacity();
			if (oldcapacity<n)
			{
				T* newT = new T[n];
				size_t oldsize = size();
				for (int i = 0; i < oldsize; ++i)
				{
					newT[i] = _start[i];
				}
				_start = newT;
				_finish = newT + oldsize;
				_endofstorage = newT + n;
			}
		}
		void resize(size_t n, const T& value =T())
		{
			size_t oldsize = size();
			if (n > oldsize)
			{
				reserve(n);
				while (oldsize < n)
				{
					_start[oldsize++] = value;
				}
				_finish = _start + oldsize;
			}
			else
			{
				while (oldsize > n)
				{
					--oldsize;
				}
				_finish = _start + oldsize;
			}
		}
		iterator insert(iterator pos, const T& v)
		{
			assert(pos <= _finish);
			size_t oldsize = size();
			size_t oldcapactiy = capacity();
			size_t newsize = pos - _start;
			if (oldsize == oldcapactiy)
			{
				size_t newcapacity = oldcapactiy == 0 ? 2 : 2 * oldcapactiy;
				reserve(newcapacity);
				pos = _start + newsize;//
			}
			auto end = _finish - 1;
			while (end>=pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = v;
			++_finish;
			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			auto begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	void test_vector_int()
	{
		vector<int> v;
		//v.resize(5);
		//v.reserve(10);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		//v.pop_back();
		//vector<int> v1(v.begin(), v.end());
		vector<int> v2(v);
		vector<int> v3(6,6);
		//v.clear();
		//cout << v.front() <<" "<<v.back()<< endl;
		//v.swap(v3);
		//cout << v[0]<< endl;
		//v3 = v2;
		v.insert(v.begin() + 5, 6);
		v.insert(v.begin() + 6, 7);
		v.insert(v.begin() + 7, 8);
		v.insert(v.begin() + 8, 9);
		//v.erase(v.begin()+2);
		cout << v.size() << " " << v.capacity() << endl;
		//string s("hello");
		//vector<char> v4(s.begin(), s.end());
		for (auto e : v)
		{
			cout << e << " ";
		}
	}
	void test_vector_string()
	{
		vector<string> str;
		str.push_back("1111");
		str.push_back("2222");
		str.push_back("3333");
		str.push_back("4444");
		vector<string> str2(str);
		//str.pop_back();
		//cout << str.front() <<" "<< str.back() << endl;
		//str.reserve(10);
		//str.resize(1);
		//str.clear();
		//str.erase(str.begin()+1);
		//str.insert(str.begin()+str.size(), "a");
		//vector<string> str1(str.begin(), str.begin() + 2);
		//str.swap(str1);
		//cout << str.empty();
		cout << str.size() << " " << str.capacity() << endl;
		//str2 = str1;
		for (auto s : str)
		{
			cout << s << " ";
		}
		
	}
}


#include<vector>
void test_vector()
{
	string s("hello");
	vector<int> v{ 1,2,3,5,5 };
	vector<int> v1(2,8);
	//v.reserve(10);
	//v.resize(5);
	//v.push_back(9); 
	//cout << v.front() <<" "<<v.back()<< endl;
	//cout << v.size() <<" "<< v.capacity() << endl;
	//v.clear();
	//v.erase(v.begin(),v.begin()+2);
	//v.insert(v.end(),2);
	//v.swap(v1);
	//v.pop_back();
	//auto pos = find(v.begin(), v.end(), 5);
	//v.erase(v.begin());
	vector<char> v3(s.begin(), s.end());
	for (auto e : v3)
	{
		cout << e << " ";
	}
}

int main()
{
	//test_vector();
	xff::test_vector_int();
	//xff::test_vector_string();
	system("pause");
	return 0;
}