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
//		str = const_cast<char*>(s.c_str());
//	}
//};

//class Solution {
//public:
//	void replaceSpace(char *str, int length) {
//		if (str == NULL)
//			return;
//		int CountOfBlanks = 0;
//		int Originallength = 0;
//		for (int i = 0; str[i] != '\0'; i++)
//		{
//			Originallength++;
//			if (str[i] == ' ')
//				++CountOfBlanks;
//		}
//		int len = Originallength + 2 * CountOfBlanks;
//		if (len + 1>length)
//			return;
//
//		char*pStr1 = str + Originallength;//复制结束符‘\0’
//		char*pStr2 = str + len;
//		while (pStr1<pStr2)
//		{
//			if (*pStr1 == ' ')
//			{
//				*pStr2-- = '0';
//				*pStr2-- = '2';
//				*pStr2-- = '%';
//			}
//			else
//			{
//				*pStr2-- = *pStr1;
//			}
//			--pStr1;
//		}
//	}
//};

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length<0)
			return;
		int orignallength = 0;
		int countofbalnk = 0;
		for (int i = 0; str[i] != '\0'; i++){
			orignallength++;
			if (str[i] == ' ')
				countofbalnk++;
		}
		int newlength = orignallength + countofbalnk * 2;//插入后的长度

		//char *str2 = (char *)malloc(sizeof(char)*newlength);
		////char *str2 = new char[orignallength + 2 * countofblank];
		//for(int i=0,j=0;str[i]!='\0';i++)
		//{
		//    if(str[i]==' '){
		//        str2[j]='%';
		//        str2[j+1]='2';
		//        str2[j+2]='0';
		//        j=j+3;
		//    }
		//    else{
		//        str2[j]=str[i];
		//        j++;
		//    }
		//}
		//str=str2;

		int pOrignallength = orignallength;
		int pNewlength = newlength;
		while (pOrignallength >= 0 && pNewlength>pOrignallength)
		{
			if (str[pOrignallength] == ' ')
			{
				str[pNewlength--] = '0';
				str[pNewlength--] = '2';
				str[pNewlength--] = '%';
			}
			else
			{
				str[pNewlength--] = str[pOrignallength];
			}
			pOrignallength--;
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