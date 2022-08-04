#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    static ListNode *reverseList(ListNode *head)
    {
        ListNode *reverseHead = NULL;

        while (head)
        {
            ListNode *node = new ListNode(head->val);
            node->next = reverseHead;
            reverseHead = node;
            head = head->next;
        }

        return reverseHead;
    }
};

int main()
{
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);
    ListNode *four = new ListNode(4);

    one->next = two;
    two->next = three;
    three->next = four;

    ListNode *head = NULL;

    ListNode *reverseHead = Solution::reverseList(head);

    while (reverseHead)
    {
        cout << reverseHead->val << " ";
        reverseHead = reverseHead->next;
    }

    return 0;
}