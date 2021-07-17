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

//1¡¢µü´ú
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (root != NULL)
		{
			if (p->val > root->val&&q->val > root->val)
			{
				root = root->right;
			}

			else if (p->val < root->val&&q->val < root->val)
			{
				root = root->left;
			}

			else
				break;
		}

		return root;
		
    }
};

//2¡¢µÝ¹é
class Solution2 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val > root->val&&q->val > root->val)
		{
			root = lowestCommonAncestor(root->right, p,  q);
		}

		else if (p->val < root->val&&q->val < root->val)
		{
			root = lowestCommonAncestor(root->left, p, q);
		}

		return root;

	}
};

int main()
{

}