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


//1、计算链表长度
class Solution1 {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
		int len = 0;
		ListNode* tail = head;
		while (head->next != NULL)
		{
			len++;
			head = head->next;
		}
		int step = len - k;
		for (int i = 0; i < step; i++)
		{
			tail = tail->next;
		}

		return tail;
    }
};

//2、无需计算长度，快慢指针
class Solution2 {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* l1 = head;
		ListNode* l2 = head;

		for (int i = 0; i < k; i++)
		{
			l1 = l1->next;
		}

		while (l1 != NULL)
		{
			l2 = l2->next;
			l1 = l1->next;
		}

		return l2;
	}
};

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}