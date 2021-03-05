#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//1°¢≤ªΩË÷˙’ª
class Solution1 {
public:
	vector<int> reversePrint(ListNode* head) {
		int len = 0;
		ListNode* head1 = head;
		stack<int>st;
		while (head1 != NULL)
		{
			st.push(head1->val);
			head1 = head1->next;
			len++;
		}

		/*vector<int>res(len,0);

		for (int i = 0; i< len; i++)
		{
			
			res[i] = st.top();
			st.pop();
		}*/
		vector<int>res;
		while (!st.empty())
		{
			res.push_back(st.top());
			st.pop();
		}

		return res;
	}
};

//2°¢vectorµÙÕ∑∑®£®≤ªΩË÷˙’ª£©
class Solution2 {
public:
	vector<int> reversePrint(ListNode* head) {
		int len = 0;
		ListNode* head1 = head;

		while (head1 != NULL)
		{
			head1 = head1->next;
			len++;
		}

		vector<int>res(len, 0);

		for (int i = len - 1; i--; i >= 0)
		{
			res[i] = head->val;
			head = head->next;
		}

		return res;
	}
};

//3°¢µ›πÈ∑®
class Solution3 {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int>res;
		if (head == NULL)
			return res;
		res = reversePrint(head->next);
		res.push_back(head->val);
		return res;
	}
};

int main()
{
	Solution1 newsolution;
	vector<int>res = newsolution.reversePrint(head);
	system("puase");
	return EXIT_SUCCESS;
}