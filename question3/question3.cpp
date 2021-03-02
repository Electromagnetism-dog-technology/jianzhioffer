#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//1、暴力法（超出时间限制）
class Solution1 {
public:
	int findRepeatNumber(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (nums[i] == nums[j])
				{
					return nums[i];
				}
			}
		}
		return 0;
	}
};

//2、哈希法（一遍过）
class Solution2 {
public:
	int findRepeatNumber(vector<int>& nums) {
		int len = nums.size();
		unordered_map<int, int>m;
		for (int i = 0; i < len; i++)
		{
			m[nums[i]]++;
			if (m[nums[i]] > 1)
			{
				return nums[i];
			}
		}
		return 0;
	}
};

int main()
{
	vector<int>nums = { 2, 3, 1, 0, 2, 5, 3 };
	Solution2 newsolution;
	int res = newsolution.findRepeatNumber(nums);
	cout << res << endl;
	system("puase");
	return EXIT_SUCCESS;
}