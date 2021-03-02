#include<iostream>
#include<vector>
#include<string>

using namespace std;

//1���������ַ���
class Solution1 {
public:
	string replaceSpace(string s) {
		string res = "";
		for (auto &c : s)
		{
			if (c != ' ')
			{
				res.push_back(c);
			}

			else
			{
				res.push_back('%');
				res.push_back('2');
				res.push_back('0');
			}
				
		}

		return res;
	}
};

//2��ԭ���޸�
class Solution2 {
public:
	string replaceSpace(string s) {
		int len1 = s.size();
		int cnt = 0;
		for (int i = 0; i < len1; i++)
		{
			if (s[i] == ' ')
				cnt++;
		}

		int len2 = len1 + cnt * 2;
		// �޸� s ����
		s.resize(len2);

		for (int i = len1 - 1, j = len2 - 1; i < j; i--, j--)
		{
			if (s[i] != ' ')
				s[j] = s[i];
			else
			{
				s[j - 2] = '%';
				s[j - 1] = '2';
				s[j] = '0';
				j -= 2;
			}
		}

		return s;
	}
};

int main()
{
	string s = "Hello world";
	Solution2 newsolution;
	string res = newsolution.replaceSpace(s);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}