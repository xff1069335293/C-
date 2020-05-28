#define _CRT_SECURE_NO_WARNINGS 1;
#include<iostream>
#include<assert.h>
using namespace std;
namespace xff {
	class string {
	public:
		typedef char* iterator;
		//迭代器
		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		//构造函数
		string(const char* str=""){
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//拷贝构造
		string(const string& s)
				:_str(nullptr)
				,_size(0)
				,_capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}
		//析构函数
		~string(){
			if (_str) {
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0; 
			}
		}
		
		//=
		string operator=(const string &s) {
			if (this != &s) {
				string strTmp(s);
				swap(strTmp);
			}
			return *this;
		}
		//size
		size_t  size()const {
			return _size;
		}
		//capacity
		size_t capacity()const {
			return _capacity;
		}
		//[]
		char& operator[](size_t index) {
			assert(index < _size);
			return _str[index];
		}
		//[]const
		const char& operator[](size_t index)const {
			assert(index < _size);
			return _str[index];
		}
		//c_str
		const char* c_str() {
			return _str;
		}
		void swap( string& s) {
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		//判断是否为空
		bool empty() {
			if (_size == 0) {
				return true;
			}
			return false;
		}
		//reserve预留空间
		void reserve(size_t num) {
			if (num > _capacity) {
				char* newstr = new char[num + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = num;
			}
		}
		//push_back
		void push_back(const char ch) {
			if (_size == _capacity) {
				size_t newcapacity = _capacity == 0 ? 2 : 2*_capacity;
				reserve(newcapacity);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		//operator+=()字符
		 string& operator+=(const char ch) {
			this->push_back(ch);
			return *this;
		}
		 //operator+=()字符串
		 string& operator+=(const char* str) {
			this->append(str);
			return *this;
		}
		
		//append加字符串
		void append(const char* str = "") {
			size_t len = strlen(str);
			if (len + _size > _capacity) {
				/*size_t newcapacity = _capacity = len + _size;
				char* newstr = new char[newcapacity + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;*/
				reserve(len + _size);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		//将有效字符串置0
		void clear() {
			_size = 0;
		}

		//resize重置有效字符个数
		//小于有效字符个数就截
		//大于补字符
		void resize(size_t num, const char ch ='\0') {
			if (num <= _size) {
				_size = num;
			}
			else {
				while (num - _size > 0) {
					push_back(ch);
				}
			}
		}
		//插入单个字符
		void insert(size_t pos, const char ch) {
			assert(pos <= _size);
			size_t size = _size;
			if (_size == _capacity) {
				size_t newcapacity = _capacity == 0 ? 2 : 2 * _capacity;
				reserve(newcapacity);
			}
			while (pos<=size) 
				{
					_str[size+1] = _str[size];
					--size;
				}
				_str[pos] = ch;
				++_size;	
		}
		//插入字符串
		void insert(size_t pos, const char* str) {
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size+len > _capacity) {
				reserve(_size + len);
			}
			size_t size = _size;
			while (pos <= size)
			{
				_str[size+len] = _str[size];
				--size;
			}
			strncpy(_str + pos, str, len);//不要复制这个字符串尾部的空格，不然会覆盖移动的字符
			_size += len;
		}
		//删除
		void erase(size_t pos=0,size_t num=0) {
			if (num == 0) {
				 _size = pos;
			}
			else {
				size_t m = num;
				while (m)
				{
					_str[pos + 1] = _str[pos + num + 1];
					--m;
				}
				_size -= num;
			}
		}
		bool operator==(const string& s) {
			if (*_str != *s._str)
				return false;
			if (_size != s._size)
				return false;
			if (_capacity != s._capacity)
				return false;
			return true;
		}
		bool operator!=(const string& s) {
			if (*this == s) {
				return false;
			}
			return true;
		}
		bool operator>(const string& s) {
			if (_size > s._size)
				return true;
			return false;
		}
		bool operator<(const string& s) {
			if (_size < s._size)
				return true;
			return false;
		}
		bool operator>=(const string& s) {
			if (*this < s) {
				return false;
			}
			return true;
		}
		bool operator<=(const string& s) {
			if (*this > s) {
				return false;
			}
			return true;
		}
		
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		size_t pos;
	};
	size_t pos = -1;
	//重载<<
	ostream&  operator <<(ostream& _out, const string& s) {
		for (size_t i = 0; i < s.size(); ++i) {
			_out << s[i];
		}
		return _out;
	}
	

	void test_String() {
		string s1;
		cout << s1 << endl;
		//cout << s1.size() << "  " <<s1.capacity()<< endl;
		string s2("hello");
		//s2.reserve(10);
		//cout << s2 <<" ";
		//cout << s2.size() << "  " << s2.capacity() << endl;
		string s3(s2);
		//cout << s3 << endl;
		//3.clear();
		//s3.push_back('w');
		//s3.push_back('o');
		//s3.push_back('r');
		//s3.push_back('l');
		//s3.push_back('d');
		//s3.push_back('!');
		//s3.append(" world!");
		//s3.reserve(10);
		//s3.resize(5);
		//s3 += "world";
		//s3 += '!';
		//s3.insert(0,'c');
		//s3.insert(1, 'a');
		//s3.insert(2, 'o');
		//s3.insert(3, 'f');
		//s3.insert(4, 'e');
		//s3.insert(5, 'n');
		//s3.insert(9, 'g');
		//s3.insert(7,' ');
		//s3.insert(5,"world!");
		s1.erase(1,2);
		cout << s3 << " ";
		cout << s3.size() <<"  "<<s3.capacity() <<endl;
		//cout << (s3 < s2) << endl;
		//s1 = s2;
		//cout << s1 << endl;
		//cout << s1.size() << "  " << s1.capacity() << endl;
		//cout << s1.empty() << endl;

		//迭代器访问	
		/*string::iterator it = s3.begin();
		while (it != s3.end()) {
			cout << *it << " ";
			++it;
		}
		//for
		for (auto e : s3) {
			cout << e;
		}*/
	}
}



#include<string>
int main() {
	string s1("hello");
	s1 += " world!";
	//s1.push_back('!');
	//s1.append("world!");
	//s1.reserve(16);
	//s1.resize(14,'a');
	//s1.clear();
	//s1.erase(2,4);
	//cout << s1<<" "<<s1.size()<<" "<<s1.capacity() << endl;
	xff::test_String();
	system("pause");
	return 0;
}
