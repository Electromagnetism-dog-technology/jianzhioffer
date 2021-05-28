#include<iostream>
#include<string>
#include<vector>


using namespace std;


class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return {};
		}

		int rows = matrix.size(), columns = matrix[0].size();
		vector<int> order;
		int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
		while (left <= right && top <= bottom) {
			for (int j = left; j <= right; j++) {
				order.push_back(matrix[top][j]);
			}
			for (int i = top + 1; i <= bottom; i++) {
				order.push_back(matrix[i][right]);
			}
			if (left < right && top < bottom) {
				for (int j = right - 1; j > left; j--) {
					order.push_back(matrix[bottom][j]);
				}
				for (int i = bottom; i > top; i--) {
					order.push_back(matrix[i][left]);
				}
			}
			left++;
			right--;
			top++;
			bottom--;
		}
		return order;
	}
};


int main()
{
	vector<vector<int>>matrix = { {1,2,3}, {4,5,6} ,{7,8,9} };
	Solution newsolution;
	vector<int> res = newsolution.spiralOrder(matrix);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << "";
	}
	system("pause");
	return EXIT_SUCCESS;
}