#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		vector<int>dp(len, 0);
		dp[0] = nums[0];
		int maxnum = nums[0];
		for (int i = 1; i < len; i++)
		{
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			maxnum = max(dp[i], maxnum);
		}
		return maxnum;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}