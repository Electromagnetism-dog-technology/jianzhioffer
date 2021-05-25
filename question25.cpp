#include<iostream>
#include<string>
#include<vector>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//1¡¢µÝ¹é·¨
class Solution1 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
		{
			return l2;
		}

		else if (l2 == NULL)
		{
			return l1;
		}

		else if (l1->val <= l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}

		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};

//2¡¢·ÇµÝ¹é
class Solution2 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* cur = head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		if (l1) cur->next = l1;
		else cur->next = l2;
		return head->next;
	}
};


int main()
{
	system("pause");
	return EXIT_SUCCESS;
}