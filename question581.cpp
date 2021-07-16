#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Ë«Ö¸Õë
class Solution {
public:
	string reverseWords(string s) {
		int start = s.size() - 1;
		int end = s.size() - 1;
		string result = "";
		while (start >= 0)
		{
			while (s[start] == ' ')
			{
				--start;
				--end;
				if (start < 0) //±ÜÃâstart¼õÎª-1ºóÈÔ·ÃÎÊs[start]
				{
					break;
				}
			}
			if (start < 0) //±ÜÃâstart¼õÎª-1ºóÈÔ·ÃÎÊs[start]
			{
				break;
			}
			while (s[start] != ' ')
			{
				--start;
				if (start < 0) //±ÜÃâstart¼õÎª-1ºóÈÔ·ÃÎÊs[start]
				{
					break;
				}
			}
			result = result + s.substr(start + 1, end - start) + " ";
			end = start;
		}
		return result.substr(0, result.size() - 1);

	}
};



int main()
{

	system("pause");
	return EXIT_SUCCESS;
}