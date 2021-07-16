#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
	unordered_set<int> ss;
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++) {
			int find = target - nums[i];
			if (find < 0) return vector<int>();
			if (ss.count(find) != 0) return vector<int>{nums[i], find};
			ss.insert(nums[i]);
		}

		return vector<int>();
	}
};





int main()
{

	system("pause");
	return EXIT_SUCCESS;
}