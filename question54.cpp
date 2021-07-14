#include<iostream>
#include<vector>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//1.中序遍历（使用数组）
class Solution {
public:
	vector<int>res;
	void DFS(TreeNode* root)
	{
		if (root == NULL)
			return;
		else
		{
			DFS(root->left);
			res.push_back(root->val);
			DFS(root->right);
		}
		
	}
	int kthLargest(TreeNode* root, int k) {
		
		DFS(root);
		return res[res.size() - k];
	}
};

//2.逆中序遍历（不使用数组）
class Solution {
public:
	int res=0,count=0;
	void DFS(TreeNode* root,int k)
	{
		if (root == NULL)
			return;
		else
		{
			DFS(root->right,k);
			if (++count == k)
				res = root->val;
			DFS(root->left, k);
		}

	}
	int kthLargest(TreeNode* root, int k) {

		DFS(root,k);
		return res;
	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}