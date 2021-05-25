#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	/*
	示例：
	+018293.983490E+20138
	
	*/
	//本题有个坑，表示数值的字符的前后可以有多个空格
	
	bool scan_un_num(const string &s, int &cur)
	{
		int first = cur;
		while (cur < s.size() && s[cur] >= '0' && s[cur] <= '9') {
			++cur;
		}
		return cur - first;
	}

	bool scan_num(const string &s, int &cur)
	{
		if (cur < s.size() && (s[cur] == '+' || s[cur] == '-'))
			++cur;
		return scan_un_num(s, cur);

	}

	bool isNumber(string s) {
		if (s.size() == 0)
			return false;
		int cur = 0;
		
		while (cur<s.size()&&s[cur] == ' ')
		{
			++cur;
		}

		bool res = scan_num(s, cur);

		if (cur < s.size() && s[cur] == '.')
		{
			++cur;
			res|= scan_un_num(s, cur); //至少一位数字，后面跟着一个点 '.',后面可以不再跟数字
		}

		if (cur < s.size() && (s[cur] == 'E')|| (s[cur] == 'e'))
		{
			++cur;
			res = scan_num(s, cur)&&res;//后面必须要跟数字
		}

		while (cur < s.size() && s[cur] == ' ') {
			++cur;
		}
		return res && (cur == s.size());
	}
};


int main()
{
	Solution newsolution;
	string s;
	bool res = newsolution.isNumber(s);
	system("pause");
	return EXIT_SUCCESS;
}