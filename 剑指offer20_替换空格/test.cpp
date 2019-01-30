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
		str = const_cast<char*>(s.c_str());
	}
};

void TestFunc(){

}

int main(){
	TestFunc();
	system("pause");
	return 0;
}