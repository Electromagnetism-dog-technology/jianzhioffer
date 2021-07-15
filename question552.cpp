#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//1、递归方法1 O(N^2)
class Solution1 {
public:
	int getDepth(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}

		return 1 + max(getDepth(root->left), getDepth(root->right));
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
		{
			return true;
		}

		int leftDepth = getDepth(root->left);
		int rightDepth = getDepth(root->right);

		return abs(leftDepth - rightDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
};


//2、递归方法2 O(N)
class Solution2 {
public:
	int getDepth(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}

		int leftDepth = getDepth(root->left);
		int rightDepth = getDepth(root->right);

		if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1) {
			return -1;
		}
		else {
			return max(leftDepth, rightDepth) + 1;
		}

		
	}
	bool isBalanced(TreeNode* root) {
		return getDepth(root) != -1;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}