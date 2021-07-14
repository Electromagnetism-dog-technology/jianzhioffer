#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

//1、动态规划
class Solution1 {
public:
	int nthUglyNumber(int n) {
		vector<int>dp(n + 1, 0);
		dp[1] = 1;
		int index2 = 1, index3 = 1, index5 = 1;
		for (int i = 2; i <= n; i++)
		{
			int next2 = dp[index2] * 2;
			int next3 = dp[index3] * 3;
			int next5 = dp[index5] * 5;

			dp[i] = min(min(next2, next3), next5);

			if (dp[i] == next2)index2++;
			if (dp[i] == next3)index3++;
			if (dp[i] == next5)index5++;
		}

		return dp[n];
	}
};

//2、小顶堆
class Solution2
{
public:
	int nthUglyNumber(int n) {
		set<long>s;
		priority_queue<long,vector<long>,greater<long>>Q;
		vector<int>factors = { 2,3,5 };
		Q.push(1L);
		s.insert(1L);
		int ugly = 0;
		for (int i = 1; i <= n; i++)
		{
			long curr = Q.top();
			Q.pop();
			ugly = (int)curr;
			for (int factor : factors)
			{
				long next = curr * factor;
				if (!s.count(next))
				{
					s.insert(next);
					Q.push(next);
				}
			}
			
		}
		return ugly;
	}

};
int main()
{

	system("pause");
	return EXIT_SUCCESS;
}