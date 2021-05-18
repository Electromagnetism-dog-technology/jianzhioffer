#include<iostream>
#include<string>
#include<regex>
using namespace std;

//1�����ⷨ
class Solution1 {
public:
	bool isMatch(string s, string p) {
		return regex_match(s, regex(p));
	}


};

//2����̬�滮
//��� p�ĵ� j ���ַ���һ��Сд��ĸ����ô���Ǳ����� s��ƥ��һ����ͬ��Сд��ĸ
//��� p �ĵ� j ���ַ��� *
//������ֻ�������������
//ƥ�� s ĩβ��һ���ַ��������ַ��ӵ���������ϻ����Լ�������ƥ�䣻
//��ƥ���ַ�����������ӵ������ٽ���ƥ�䡣
//��̬�滮�ı߽�����Ϊ f[0][0] = true�����������ַ����ǿ���ƥ��ġ�
//����Ϊ��
//����� j ���ַ��� *��if(matches(s[i], p[j - 1])), f[i][j] = f[i - 1][j] | f[i][j - 2]; else f[i][j] = f[i][j - 2];
//����� j ���ַ����� *��if(matches(s[i], p[j])), f[i][j] = f[i - 1][j - 1] ; else false;
class Solution2 {
public:
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();

		auto matches = [&](int i, int j)
		{
			if (i == 0)
			{
				return false;
			}
			if (p[j - 1] == '.')
			{
				return true;
			}
			
			return s[i - 1] == p[j - 1];
		};

		vector<vector<int>>dp(m+1, vector<int>(n+1));
		dp[0][0] = true;

		for (int i = 0; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (p[j - 1] == '*')
				{
					dp[i][j] |= dp[i][j - 2];
					if (matches(i, j - 1))
					{
						dp[i][j] |= dp[i - 1][j];
					}
				}

				else
				{
					if (matches(i, j))
					{
						dp[i][j] |= dp[i - 1][j-1];
					}
					
				}

				
			}
		}

		return dp[m][n];


		
	}


};

int main()
{
	string s = "aab", p = "c*a*b";
	Solution2 newsolution;
	bool res = newsolution.isMatch(s, p);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}