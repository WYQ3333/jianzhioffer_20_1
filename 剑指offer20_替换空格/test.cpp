#include<iostream>
using namespace std;
#include<string>

//class Solution {
//public:
//	void replaceSpace(char *str, int length) {
//		string s = "";
//		char *cur = str;
//		while (*cur != '\0'){
//			if (*cur != ' '){
//				s.push_back(*cur);
//			}
//			if (*cur == ' '){
//				s.push_back('%');
//				s.push_back('2');
//				s.push_back('0');
//			}
//			++cur;
//		}
//		s.push_back('\0');
//		_str = const_cast<char*>(s.c_str());
//	}
//public:
//	char* _str;
//};

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL)
			return;
		int CountOfBlanks = 0;
		int Originallength = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			Originallength++;
			if (str[i] == ' ')
				++CountOfBlanks;
		}
		int len = Originallength + 2 * CountOfBlanks;
		if (len + 1>length)
			return;

		char*pStr1 = str + Originallength;//复制结束符‘\0’
		char*pStr2 = str + len;
		while (pStr1<pStr2)
		{
			if (*pStr1 == ' ')
			{
				*pStr2-- = '0';
				*pStr2-- = '2';
				*pStr2-- = '%';
			}
			else
			{
				*pStr2-- = *pStr1;
			}
			--pStr1;
		}
	}
};

void TestFunc(){
	char *str = "Hello world";
	Solution s;
	s.replaceSpace(str, strlen(str));
	//strlen计算长度不包括'\0'
	cout << str<< endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}