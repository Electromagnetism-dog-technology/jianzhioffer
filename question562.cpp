#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> bits(32, 0);
		for (auto num : nums) {
			for (int i = 0; i < 32; i++) {
				bits[i] += num & 1;
				num >>= 1;
			}
		}
		int res = 0;
		for (int i = 31; i >= 0; i--) {
			res <<= 1;
			res += bits[i] % 3;
		}
		return res;
	}
};




int main()
{

	system("pause");
	return EXIT_SUCCESS;
}