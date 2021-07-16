#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1¡¢¹þÏ£·¨
class Solution {
public:
	bool isStraight(vector<int>& nums) {
		vector<bool>vec(15, false);
		int minval = 14, maxval = 0;
		for (int num : nums)
		{
			if (num == 0)
				continue;
			if (vec[num] == true)
				return false;

			vec[num] = true;

			
			minval = min(minval, num);
			maxval = max(maxval, num);
		}

		return (maxval - minval + 1) <= 5;
	}
};
int main()
{

}