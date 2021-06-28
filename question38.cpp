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
				//Ϊ�˷�ֹ�ظ��ַ���ɵõ��ظ������У�����Ƚ��ַ���������һ�¡�
				//����ͬ�����ַ�����һ���ˣ�������ݵ�ʱ������ǰ�ַ�����һ���ַ�һ����˵�����ַ��Ѿ�����һ�λ��������й�һ���ˣ����ֱ������
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