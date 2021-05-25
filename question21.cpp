#include<iostream>
#include<string>
#include<vector>

using namespace std;

//1、快慢双指针法
class Solution1 {
public:
	vector<int> exchange(vector<int>& nums) {
		int n = nums.size();
		int low = 0, fast = 0;
		while (fast < n)
		{
			if (nums[fast] % 2 == 1)//也可以写成if (nums[fast] & 1)
			{
				swap(nums[low], nums[fast]);
				low++;
			}
			fast++;
		}

		return nums;
	}
};

//2、首尾双指针法
class Solution2 {
public:
	vector<int> exchange(vector<int>& nums) {
		//双指针
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			while (l < r && nums[l] % 2 == 1) l++;
			while (l < r && nums[r] % 2 == 0) r--;
			if (l < r) {
				int t = nums[l];
				nums[l] = nums[r];
				nums[r] = t;
			}
		}
		return nums;
	}
};


int main()
{
	vector<int>nums = { 1, 2, 3, 4 };
	Solution1 newsolution;
	nums = newsolution.exchange(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	system("pause");
	return EXIT_SUCCESS;
}