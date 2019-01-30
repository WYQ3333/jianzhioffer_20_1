#include<iostream>
using namespace std;
#include<string>

class Solution {
public:
	void replaceSpace(char *str, int length) {
		string s = "";
		char *cur = str;
		while (*cur != '\0'){
			if (*cur != ' '){
				s.push_back(*cur);
			}
			if (*cur == ' '){
				s.push_back('%');
				s.push_back('2');
				s.push_back('0');
			}
			++cur;
		}
		s.push_back('\0');
		_str = const_cast<char*>(s.c_str());
	}
public:
	char* _str;
};

void TestFunc(){
	char *str = "Hello world";
	Solution s;
	s.replaceSpace(str, strlen(str));
	//strlen计算长度不包括'\0'
	cout << s._str<< endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}