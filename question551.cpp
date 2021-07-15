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

//1¡¢DFS
class Solution1 {
public:
	int getDepth(TreeNode* root) {
		if (root == NULL)return 0;
		int leftdepth = getDepth(root->left);
		int rightdepth = getDepth(root->right);
		int depth = 1 + max(leftdepth , rightdepth);
		return depth;

	}

	int maxDepth(TreeNode* root) {
		return getDepth(root);
	}
};

//2¡¢BFS
class Solution2 {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)return 0;
		queue<TreeNode*>Q;
		Q.push(root);
		int res = 0;
		while (!Q.empty())
		{
			int n = Q.size();
			res++;
			while (n--)
			{
				TreeNode* tmp = Q.front();
				Q.pop();
				if (tmp->left)Q.push(tmp->left);
				if (tmp->right)Q.push(tmp->right);
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