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

//1、BFS
class Solution1 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>res;
		if (!root)return res;
		queue<TreeNode*>q;
		q.push(root);
		while (!q.empty())
		{
			vector<int>vec;
			int len = q.size();
			for (int i = 0; i < len; i++)
			{
				auto t = q.front();
				q.pop();
				vec.push_back(t->val);
				if (t->left)q.push(t->left);
				if (t->right)q.push(t->right);
			}

			// 当前res.size()为偶数时无需翻转，否则要翻转
			if (res.size() & 1)
			{
				reverse(vec.begin(), vec.end());
			}

			res.push_back(vec);
		}

		return res;
	}

};

//2、DFS
class Solution2 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		dfs(root, res, 0);
		return res;
	}
	void dfs(TreeNode* root, vector<vector<int>>& res, int level)
	{
		if (!root) return;
		if (level >= res.size()) res.push_back(vector<int>());

		if (level % 2 == 0)
			res[level].push_back(root->val);
		else
			res[level].insert(res[level].begin(), root->val); //如果为奇数行则insert到前面

		dfs(root->left, res, level + 1);
		dfs(root->right, res, level + 1);
	
		
	}
};



int main()
{

	system("pause");
	return EXIT_SUCCESS;
}