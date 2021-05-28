#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

//1¡¢BFS
class Solution1 {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}

		queue<TreeNode*>q;

		q.push(root);

		while (!q.empty())
		{
			TreeNode* node = q.front();
			q.pop();
			swap(node->left, node->right);
			if (node->left != NULL)
				q.push(node->left);

			if (node->right != NULL)
				q.push(node->right);
		}

		return root;
	}
};

//2¡¢DFS
class Solution2 {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}

		swap(root->left, root->right);

		mirrorTree(root->left);

		mirrorTree(root->right);

		return root;
	}
};

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int main()
{
	system("pause");
	return EXIT_SUCCESS;
}