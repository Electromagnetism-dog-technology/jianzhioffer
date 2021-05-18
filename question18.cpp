#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//1、初始解法，未考虑头结点
class Solution1 {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		ListNode* l1 = head;
		while (l1->next != NULL)
		{
			if (l1->next->val == val)
			{
				l1->next = l1->next->next;

			}
			l1 = l1->next;

		}

		return head;
	}
};

//2、考虑头结点
class Solution2 {
public:
	ListNode* deleteNode(ListNode* head, int val) {


		if (head->val == val)
		{
			return head->next;
		}


		ListNode *l1 = head;

		while (l1->next->val != val)
		{
			l1 = l1->next;
		}
		l1->next = l1->next->next;

		return head;
	}
};


int main()
{

	system("pause");
	return EXIT_SUCCESS;
}