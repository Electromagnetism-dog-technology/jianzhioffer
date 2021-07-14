#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		int begin = 0, end = 1,res=0;
		while (end < n)
		{
			if (nums[begin] > nums[end])
			{
				res++;
				end++;
			}
			else
			{
				begin++;
				end++;
			}
				
		}

		return res;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}