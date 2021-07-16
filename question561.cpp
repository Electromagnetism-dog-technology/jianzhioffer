#include<iostream>
#include<vector>
#include<map>

using namespace std;

//1、哈希表
class Solution1 {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		map<int, int>m;
		int n = nums.size();
		vector<int>res(2, 0);
		for (int i = 0; i < n; i++)
		{
			m[nums[i]]++;
		}
		for (int i = 0; i < n; i++)
		{
			if (m[nums[i]] == 1)
			{
				res.push_back(nums[i]);
			}
		}

		return res;
	}
};

//2、位运算
class Solution2 {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int x = 0, y = 0,n=0,m=1;

		//异或操作，得到只出现一次的两个数
		for (int num : nums)
		{
			n ^= num;
		}

		//找到两个数不相等的位
		while ((n&m) == 0)
		{
			m <<= 1;
		}

		//分组异或
		for (int num : nums)
		{
			if (num&m)x ^= num;
			else y ^= num;
		}

		return { x,y };
	}
};


int main()
{

	system("pause");
	return EXIT_SUCCESS;
}