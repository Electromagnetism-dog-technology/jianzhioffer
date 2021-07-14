#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1¡¢»¬¶¯´°¿Ú
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int start = 0, end = 0, length = 0, res = 0;
		int n = s.size();
		
		while (end < n)
		{
			
			for (int i = start; i < end; i++)
			{
				if (s[i] == s[end])
				{
					start=i+1;
					length = end - start;
					break;
				}
			}

			end++;
			length++;
			res = max(length, res);
		}

		return res;
	}
};

//2¡¢hash·¨
class Solution2 {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> m(128, -1);
		int res = 0, left = -1;
		for (int i = 0; i < s.size(); ++i) {
			left = max(left, m[s[i]]);
			m[s[i]] = i;
			res = max(res, i - left);
		}
		return res;

	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}