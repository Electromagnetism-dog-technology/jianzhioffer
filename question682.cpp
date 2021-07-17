#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q || root == p || root == q)
			return root;

		TreeNode* leftnode = lowestCommonAncestor(root->left, p, q);
		TreeNode* rightnode = lowestCommonAncestor(root->right, p, q);

		if (leftnode&&rightnode)
			return root;
		else if (leftnode)
			return leftnode;
		else if (rightnode)
			return rightnode;
		else
			return NULL;
	}
};

int main()
{

}