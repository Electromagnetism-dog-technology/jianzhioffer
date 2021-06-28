#include<iostream>
#include<vector>


using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
	vector<int>v1;
	vector<vector<int>>res;

	void dfs(TreeNode* root, int target) {
		if (root == NULL)
			return;
		target -= root->val;

		v1.push_back(root->val);

		if (root->left == NULL && root->right == NULL && target == 0)
		{
			res.push_back(v1);
		}

		dfs(root->left, target);
		dfs(root->right, target);

		v1.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int target) {
		dfs(root, target);
		return res;
	}
};


int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}