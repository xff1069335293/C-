//String类的使用
//实现string类
//深拷贝
#include<iostream>
#include<string>
namespace xff {
	class String {
	public:
		//构造函数
		String()
		:_str(new char[1]){
			*_str ='\0';
		}
		String(const char* str )
			:_str(new char[strlen(str)+1]) {
			
		}
		//析构函数
		//~String();
		//=重载
		//String operator=(char* str2) 
		//<<
		//friend std::ostream& operator<<(std::ostream& _out, const xff::String s);
		void Test_String() {
			
			std::cout << _str << std::endl;
		}
	private:
		char* _str;
	};
}
void Test_string() {
	using namespace std;
	string s1("hello");
	cout << s1 << endl;
	//cout << s1.size() << endl;	//有效字符个数
	//cout << s1.length() << endl;//有效字符个数
	//cout << s1.capacity() << endl;//容量
	//cout << s1.empty() << endl;//是否为空
	//s1.clear();//清空有效字符串
	//s1.reserve(15);//改变容量，小于等于容量就不变，大于的话就扩容
	//s1.resize(1,'!');//增加有效字符到n个，或者减小但n，增加时指定字符的话就就用指定字符填充，没有指定用\0，小于有效字符的话就删除。
	s1.push_back('!');
	s1.pop_back();
	s1[0] = 'H';//[]
	//三种遍历方式
	//for+[]
	/*for (int i = 0; i < s1.size(); ++i) {
		cout << s1[i] << " ";
	}*/
	//迭代器
	/*string::iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it << "-";
		++it;
	}*/
	//范围for
	/*for (auto& a : s1) {
		cout << (char)(a+1)<< " ";
	}*/
	s1.append(" world!");//字符串结尾追加一个字符串
	string str(".cpp");
	s1 += str;	//字符串结尾追加一个字符串
	cout << s1.c_str() << endl;
	//cout << s1 << endl;
	cout << s1.find('.') << endl;//从位置向后找某个字符，返回它的下标。
	string str1;
	str1=s1.substr(s1.find('.'),s1.size()-1);//
	cout << str1.c_str() << endl;
	//cout << s1.rfind('l') << endl;
	//cout << s1.size() << endl;	//有效字符个数
	//cout << s1.capacity() << endl;//有效字符个数
	
}
int main() {
	//xff::String s("hello");
	//s.Test_String();
	Test_string();
	system("pause");
	return 0;
}