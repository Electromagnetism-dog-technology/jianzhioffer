#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int i = 1, j = 2, s = 3;
		vector<vector<int>>res;
		while (i < j)
		{
			if (s == target)
			{
				vector<int>vec;
				for (int k = i; k <= j; k++)
				{
					vec.push_back(k);
				}
				res.push_back(vec);
				s -= i;
				i++;
			}

			else if (s > target)
			{
				s -= i;
				i++;
			}
			else
			{
				j++;
				s += j;
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