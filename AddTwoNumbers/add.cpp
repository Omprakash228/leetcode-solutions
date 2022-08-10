#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(nullptr) {}
};

class Solution
{
public:
    static ListNode *add(ListNode *l1, ListNode *l2)
    {
        ListNode *rl1 = reverse(l1);
        ListNode *rl2 = reverse(l2);
        ListNode *resultHead = NULL;
        ListNode *prev = NULL;

        int carry = 0;

        while (rl1 != NULL || rl2 != NULL)
        {
            int sum = carry;

            if (rl1 != NULL)
            {
                sum += rl1->val;
                rl1 = rl1->next;
            }

            if (rl2 != NULL)
            {
                sum += rl2->val;
                rl2 = rl2->next;
            }

            carry = sum / 10;
            sum = sum % 10;

            resultHead = new ListNode(sum);
            resultHead->next = prev;
            prev = resultHead;
        }
        if (carry != 0)
        {
            resultHead = new ListNode(carry);
            resultHead->next = prev;
        }

        return resultHead;
    }

    static ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *next = NULL;

        while (head != NULL)
        {
            next = head->next;

            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    static void printList(ListNode *head)
    {
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
    }
};

int main()
{
    // ListNode* a = new ListNode(7);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(4);
    ListNode *d = new ListNode(3);
    // a->next = b;
    b->next = c;
    c->next = d;

    ListNode *e = new ListNode(5);
    ListNode *f = new ListNode(6);
    ListNode *g = new ListNode(4);
    e->next = f;
    f->next = g;

    ListNode *head1 = b;
    ListNode *head2 = e;

    ListNode *result = Solution::add(head1, head2);
    Solution::printList(result);

    return 0;
}
