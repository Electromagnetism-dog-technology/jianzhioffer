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
 
//1¡¢BFS
class Solution1 {
public:
	vector<int> levelOrder(TreeNode* root) {
		vector<int>res;
		if (!root)return res;
		queue<TreeNode*>q;
		q.push(root);
		while (!q.empty())
		{
			auto t = q.front();
			q.pop();
			res.push_back(t->val);
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);
		}

		return res;
	}

};



int main()
{

	system("pause");
	return EXIT_SUCCESS;
}