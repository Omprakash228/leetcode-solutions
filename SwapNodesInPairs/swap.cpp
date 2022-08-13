#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

class Solution
{
public:
    static ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *second = head->next;
        ListNode *first = head;
        ListNode *prev = NULL;

        head = second;

        while (first != NULL && second != NULL)
        {
            first->next = second->next;
            second->next = first;
            if (prev != NULL)
                prev->next = second;

            if (first->next == NULL)
                return head;

            prev = first;
            first = first->next;
            second = first->next;
        }

        return head;
    }
};

int main()
{
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);
    ListNode *four = new ListNode(4);
    ListNode *five = new ListNode(5);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    ListNode *head = one;

    ListNode *newHead = Solution::swapPairs(head);

    while (newHead != NULL)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    return 0;
}