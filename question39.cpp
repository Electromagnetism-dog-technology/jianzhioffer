#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

//1¡¢¹þÏ£·¨
class Solution1 {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int>m;
		int n = nums.size();
		int res;
		for (int i = 0; i < n; i++)
		{
			m[nums[i]]++;
		}

		for (int i = 0; i < n; i++)
		{
			if (m[nums[i]] > n / 2)
			{
				res = nums[i];
			}
		}

		return res;

	}
};

//2¡¢ÅÅÐò·¨
class Solution2 {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];

	}
};


int main()
{
	vector<int>nums = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	Solution1 newsolution;
	int res = newsolution.majorityElement(nums);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}