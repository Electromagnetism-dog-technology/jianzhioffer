#include<iostream>
#include<vector>

using namespace std;

//1、一次二分
class Solution {
public:
	int binary_search(vector<int>& nums,int left,int right, int target)
	{
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (target == nums[mid])
			{
				return binary_search(nums, 0, mid - 1, target) + binary_search(nums, mid + 1, nums.size(), target) + 1;
			}
			else if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}

		}
		return 0;
		

	}

	int search(vector<int>& nums, int target) {
		return binary_search(nums, 0, nums.size()-1, target);
	}
};

//2、两次二分
class Solution {
public:
	int search(vector<int>& nums, int target)
	{
		int len = nums.size();
		if (len == 0)   return 0;
		int l_boundary, r_boundary;     // target的左右边界
		int left = 0, right = len - 1;  // 二分法的左右指针
		// 第一次二分法求出右边界r_boundary
		while (left <= right)           // 正是left=right时的这最后这次循环，left又右移了一次使得left成为右边界
		{
			int mid = left + (right - left) / 2;
			if (target >= nums[mid])    // 等号在left这里，为了使left移动的更激进，最终成为右边界
				left = mid + 1;
			else
				right = mid - 1;
		}
		r_boundary = left;              // 退出循环时left为最右target的右边元素，right则应为最右边的target（若target存在）
		// 如果right位置不是target，说明数组中无target，提前返回
		if (right >= 0 && nums[right] != target)    return 0;
		right = left;                   // 重置左右指针；右指针可以重置为右边界，减少下次二分的区间
		left = 0;

		// 第二次二分法求出左边界l_boundary
		while (left <= right)           // 正是left=right时的这最后这次循环，right又左移了一次使得right成为左边界
		{
			int mid = left + (right - left) / 2;
			if (target <= nums[mid])    // 等号在right这里，为了使right移动的更激进，最终成为右边界
				right = mid - 1;
			else
				left = mid + 1;
		}
		l_boundary = right;             // 退出循环时right为最左target的左边元素

		return r_boundary - l_boundary - 1;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}