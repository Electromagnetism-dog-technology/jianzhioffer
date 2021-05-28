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

//1��BFS
class Solution1 {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
		{
			return true;
		}

		queue<TreeNode*>q;
		q.push(root->left);
		q.push(root->right);

		while (!q.empty())
		{
			TreeNode* leftnode = q.front();
			q.pop();
			TreeNode* rightnode = q.front();
			q.pop();

			if (!leftnode && !rightnode)// ��ڵ�Ϊ�ա��ҽڵ�Ϊ�գ���ʱ˵���ǶԳƵ�
			{
				continue;
			}

			if (!leftnode ||!rightnode || rightnode->val != leftnode->val)
			{
				return false;
			}

			q.push(leftnode->left);
			q.push(rightnode->right);
			q.push(leftnode->right);
			q.push(rightnode->left);

		}

		return true;
	}
};

//2��DFS
class Solution2 {
public:

		bool isSymmetric(TreeNode* root) {
			return dfs(root, root);
		}

		bool dfs(TreeNode* root1, TreeNode* root2)
		{
			if (!root1 && !root2) return true;              //���ڵ㶼Ϊ�գ��Գ�
			else if (!root1 || !root2 || root1->val != root2->val) return false;        //����һ�ڵ�Ϊ�գ����߽ڵ�ֵ����ȣ����Գ�

			return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
		}

	
};


int main()
{
	system("pause");
	return EXIT_SUCCESS;
}