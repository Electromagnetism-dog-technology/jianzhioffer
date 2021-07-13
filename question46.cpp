#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	int translateNum(int num) {
		string nums = to_string(num);
		int len = nums.size();
		vector<int>dp(len + 1);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i < len + 1; i++)
		{
			if (nums[i - 2] == '1' || (nums[i - 2] == '2'&&nums[i - 1] < '6'))
			{
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			else
				dp[i] = dp[i - 1];
		}
		return dp[len];
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}