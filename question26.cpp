#include<iostream>
#include<string>
#include<vector>
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
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == NULL || B == NULL)
			return false;
		bool res = false;
		if (A->val == B->val)
		{
			res = compareStructure(A, B);
		}
		
		if (res == false)
			res = isSubStructure(A->left, B) || isSubStructure(A->right, B);

		return res;

	}

	bool compareStructure(TreeNode* A, TreeNode* B) {
		if (B == NULL)
			return true;
		else if (A == NULL || A->val != B->val)
			return false;
		
		return compareStructure(A->left, B->left) && compareStructure(A->right, B->right);
	}
};

//2¡¢BFS
class Solution2 {
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == NULL || B == NULL)
			return false;
		bool res = false;
		
		queue<TreeNode*>q;
		q.push(A);
		while (!q.empty())
		{
			auto node = q.front();
			q.pop();
			if (node->val == B->val)
			{
				res = compareStructure(node, B);
			}

			if (res == false)
			{
				if (node->left != NULL)
					q.push(node->left);
				if (node->right != NULL)
					q.push(node->right);

			}
				
			
		}
		return res;

	}

	bool compareStructure(TreeNode* A, TreeNode* B) {
		if (B == NULL)
			return true;
		else if (A == NULL || A->val != B->val)
			return false;

		return compareStructure(A->left, B->left) && compareStructure(A->right, B->right);
	}
};


int main()
{
	system("pause");
	return EXIT_SUCCESS;
}