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
	ListNode* reverseList(ListNode* head) {
		ListNode *tail = head;
		while (head==NULL||head->next == NULL)
		{
			return head;
		}

		
		tail = reverseList(head->next);

		head->next->next = head;
		head->next = NULL;

		return tail;
	}
};

//2¡¢µü´ú·¨
class Solution2 {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *tail = head;
		ListNode *pre = NULL;

		while (tail != NULL)
		{
			ListNode *node = tail->next;
			tail->next = pre;
			pre = tail;
			tail = node;
		}

		return pre;
	}
};

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}