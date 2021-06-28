#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<string>res;
	vector<int>vis;

	void backtrack(string s, int i, string perm, int n)
	{
		if (i == n)
		{
			res.push_back(perm);
			return;
		}
			
		for (int j = 0; j < n; j++)
		{
			if (vis[j] || (j > 0 && !vis[j - 1] && s[j] == s[j - 1]))
				//为了防止重复字符造成得到重复的排列，因此先将字符串排列了一下。
				//这样同样的字符就在一起了，当你回溯的时候，若当前字符和上一个字符一样，说明该字符已经在上一次回溯中排列过一次了，因此直接跳过
			{
				continue;
			}

			vis[j] = true;
			perm.push_back(s[j]);
			backtrack(s, i+1, perm, n);
			perm.pop_back();
			vis[j] = false;
		}

		
	}

	vector<string> permutation(string s) {
		int n = s.size();
		vis.resize(n);
		sort(s.begin(), s.end());
		string perm;
		backtrack(s, 0, perm, n);
		return res;
	}
};


int main()
{
	string s = "aac";
	Solution newsolution;
	vector<string>res = newsolution.permutation(s);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}