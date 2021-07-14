#include<iostream>
#include<vector>

using namespace std;

//1��һ�ζ���
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

//2�����ζ���
class Solution {
public:
	int search(vector<int>& nums, int target)
	{
		int len = nums.size();
		if (len == 0)   return 0;
		int l_boundary, r_boundary;     // target�����ұ߽�
		int left = 0, right = len - 1;  // ���ַ�������ָ��
		// ��һ�ζ��ַ�����ұ߽�r_boundary
		while (left <= right)           // ����left=rightʱ����������ѭ����left��������һ��ʹ��left��Ϊ�ұ߽�
		{
			int mid = left + (right - left) / 2;
			if (target >= nums[mid])    // �Ⱥ���left���Ϊ��ʹleft�ƶ��ĸ����������ճ�Ϊ�ұ߽�
				left = mid + 1;
			else
				right = mid - 1;
		}
		r_boundary = left;              // �˳�ѭ��ʱleftΪ����target���ұ�Ԫ�أ�right��ӦΪ���ұߵ�target����target���ڣ�
		// ���rightλ�ò���target��˵����������target����ǰ����
		if (right >= 0 && nums[right] != target)    return 0;
		right = left;                   // ��������ָ�룻��ָ���������Ϊ�ұ߽磬�����´ζ��ֵ�����
		left = 0;

		// �ڶ��ζ��ַ������߽�l_boundary
		while (left <= right)           // ����left=rightʱ����������ѭ����right��������һ��ʹ��right��Ϊ��߽�
		{
			int mid = left + (right - left) / 2;
			if (target <= nums[mid])    // �Ⱥ���right���Ϊ��ʹright�ƶ��ĸ����������ճ�Ϊ�ұ߽�
				right = mid - 1;
			else
				left = mid + 1;
		}
		l_boundary = right;             // �˳�ѭ��ʱrightΪ����target�����Ԫ��

		return r_boundary - l_boundary - 1;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}