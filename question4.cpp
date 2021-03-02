#include<iostream>
#include<vector>

using namespace std;

//1¡¢¶þ·Ö·¨
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		int len = matrix.size();
		
		if (len == 0)
		{
			return false;
		}
		for (int i = 0; i < len; i++)
		{
			int wid = matrix[0].size();
			if (searchNumber(matrix[i], 0, wid - 1, target))
			{
				return true;
			}
			
		}

		return false;
	}

	bool searchNumber(vector<int>& matrix, int left, int right, int target)
	{
		
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (target == matrix[mid])
			{
				return true;
			}
			else if (target > matrix[mid])
			{
				return searchNumber(matrix, mid + 1, right, target);
			}
			else
			{
				return searchNumber(matrix, 0, mid - 1, target);
			}

			
		}
		return false;
		
	}

	
};


int main()
{
	vector<vector<int>> matrix = {};
	/*vector<vector<int>> matrix=
	{
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};*/

	int target = 5;
	Solution newsolution;
	bool res = newsolution.findNumberIn2DArray(matrix, target);
	cout << res << endl;

	system("pause");
	return EXIT_SUCCESS;
}