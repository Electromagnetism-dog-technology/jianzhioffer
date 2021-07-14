#include<iostream>
#include<vector>

using namespace std;

//1¡¢¶þ·Ö·¨
class Solution {
public:
	int binary_search(vector<int>& nums, int left, int right)
	{
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid]!=mid)
			{
				right=mid-1;
			}
			
			else
			{
				left=mid+1;
			}

		}
		return left;


	}

	int missingNumber(vector<int>& nums) {
		return binary_search(nums, 0, nums.size() - 1);
	}
};


int main()
{

	system("pause");
	return EXIT_SUCCESS;
}