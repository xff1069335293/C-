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
		iterator rbegin() {	//最后一个字符
			return _str+_size-1;
		}
		iterator end() {
			return _str + _size;
		}
		iterator rend() {	//第一个字符的前一个
			return --_str;
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
			this->swap(tmp);
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
		string operator=(string s) {
			this->swap(s);
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
		string& insert(size_t pos, const char ch) {
			assert(pos < _size);
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
				return *this;
		}
		//插入字符串
		string& insert(size_t pos, const char* str) {
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size+len > _capacity) {
				reserve(_size + len);
			}
			int size = _size;
			while ((int)pos <= size)//无符号-1是最大值，容易死循环
			{
				_str[size+len] = _str[size];
				--size;
			}
			strncpy(_str + pos, str, len);//不要复制这个字符串尾部的空格，不然会覆盖移动的字符
			_size += len;
			return *this;
		}
		//删除
		//大于等于pos到_size全删
		//小于保留余下的，并且移动
		string& erase(size_t pos,size_t len = npos) {
			assert(pos < _size);
			if (len>=_size-pos) {
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t i = pos+len;
				while (i <= _size) {
					_str[pos++] = _str[i++];	
				}
				_size -= len;
			}
			return *this;
		}
		//find字符
		size_t find(const char ch, size_t pos = 0) {
			for (size_t i = pos; i < _size; ++i) {
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}
		//find字符串
		size_t find(const char* str, size_t pos = 0) {
			size_t len = strlen(str);
			size_t dst = pos;
			while (dst<_size) {
				size_t src = 0;
				pos = dst;
				while (src<len&&_str[dst] == str[src]) {
					++src;
					++dst;
				}
				if (src == len) {
					return pos;
				}
				++dst;
			}
			return npos;
		}
		bool operator==(const string& s) {
			int ret = strcmp(_str, s._str);
			if (ret == 0)
				return true;
			return false;
		}
		bool operator!=(const string& s) {
			if (*this == s) {
				return false;
			}
			return true;
		}
		bool operator>(const string& s) {
			int ret = strcmp(_str, s._str);
			if (ret > 0)
				return true;
			return false;
		}
		bool operator<(const string& s) {
			int ret = strcmp(_str, s._str);
			if (ret < 0)
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
		 const string substr(size_t pos, size_t n=npos) {
			assert(pos < _size);
			if (_size-pos<n) {
				n = _size - pos;
			}
			
			char* newstr = new char[n + 1];
			strncpy(newstr,_str + pos, n);
			newstr[n] = '\0';
			string s(newstr);
			delete[] newstr;
			return s;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		const static size_t npos;
	};
	const size_t string::npos = -1;
	//重载<<
	ostream&  operator <<(ostream& _out, const string& s) {
		for (size_t i = 0; i < s.size(); ++i) {
			_out << s[i];
		}
		return _out;
	}
	//重载>>
	istream&  operator >>(istream& _in, string& s) {
		while (1) {
			char ch;
			ch = _in.get();//输入的全接收，包括空格换行
			if (ch == '\n') {
				break;
			}
			else
			{
				s += ch;
			}
		}	
		return _in;
	}
	void test_String1() {
		string s1;
		//cout << s1 << endl;
		string s2("hello");
		//cout << s2 << endl;
		//cout << s2.size() << "  " << s2.capacity() << endl;
		string s3;
		s3 = s2;
		cout << s3 << endl;
		//cin >> s1;
		//cout << s1 << "  " <<s1.empty()<<endl;
		s2 += "world";
		cout << s2 << endl;
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
		//s2.reserve(15);
		//s2.reserve(3);
		//cout << s2 << endl;
		//cout << s2.size() << "  " << s2.capacity() << endl;
		//s3.resize(2);
		//s3.resize(10);
		//cout << s3 << endl;
		//cout << s3.size() << "  " << s3.capacity() << endl;
		//s3.push_back(' ');
		//cout << s3 << " ";
		//cout << s3.size() << "  " << s3.capacity() << endl;
		//s3.append("world!");
		//cout << s3 << " ";
		//cout << s3.size() << "  " << s3.capacity() << endl;
		//s3.insert(0,"a");
		//s3.insert(10, "abc");
		//s3.insert(5,"a");
		//s3.insert(1, 'a');
		//s3.erase(2, 8);
		//s3.erase(0);
		//s3.erase(2, 2);
		//cout << s3 << " ";
		//cout << s3.size() << "  " << s3.capacity() << endl;
		//size_t num1 =s3.find('l');
		//size_t num2 = s2.find("q",1);
		//cout << num1 << " " << num2 << endl;
		//cout << (s3>=s2)<< endl;
		cout << s3.substr(2, 2);
	}
}


#include<string>
int main() {
	string s1("hello");
	//cout<<s1.substr(2);
	//s1.insert(5,"ac");
	//s1 += " world!";
	//s1.push_back(' ');
	//s1.append("world!");
	//s1.reserve(18);
	//s1.resize(14,'a');
	//s1.clear();
	//s1.erase();
	//cout << s1.substr(2);
	//cout << s1 << endl;
	//int num = s1.find('e');
	//cout << s1<<" "<<s1.size()<<" "<<s1.capacity() <<endl;
	//cout << num;
	/*string::iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it;
		++it;
		}
	cout << endl;
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend()) {
		cout << *rit;
		++rit;
	}*/
	xff::test_String1();
	system("pause");
	return 0;
}


