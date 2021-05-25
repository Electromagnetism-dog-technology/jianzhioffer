#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	/*
	ʾ����
	+018293.983490E+20138
	
	*/
	//�����и��ӣ���ʾ��ֵ���ַ���ǰ������ж���ո�
	
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
			res|= scan_un_num(s, cur); //����һλ���֣��������һ���� '.',������Բ��ٸ�����
		}

		if (cur < s.size() && (s[cur] == 'E')|| (s[cur] == 'e'))
		{
			++cur;
			res = scan_num(s, cur)&&res;//�������Ҫ������
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