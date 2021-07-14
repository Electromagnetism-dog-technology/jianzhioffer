#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//1¡¢¹þÏ£·¨
class Solution {
public:
	char firstUniqChar(string s) {
		int len = s.size();
		char res = ' ';
		unordered_map<char, int>m;
		for (int i = 0; i < len; i++)
		{
			m[s[i]]++;
		}

		for (int i = 0; i < len; i++)
		{
			if (m[s[i]] > 0)
			{
				res = s[i];
				break;
			}
		}

		return res;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}