#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		return dfs(0, postorder.size()-1,postorder);
	}

	bool dfs(int left, int right, vector<int>& postorder)
	{
		if (left >= right) return true;//ÍË³öÌõ¼þ
		int k=left;
		int root = postorder[right];
		while (k < right && postorder[k] < root) k++;

		for (int i = k; i < right; i++)
		{
			if (postorder[i] < root)
				return false;
		}

		return dfs(left, k - 1, postorder) && dfs(k, right - 1, postorder);

	}
};


int main()
{
	vector<int>postorder = { 4, 8, 6, 12, 16, 14, 10 };
	Solution newsolution;
	bool res = newsolution.verifyPostorder(postorder);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}