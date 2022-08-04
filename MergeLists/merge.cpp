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
    static ListNode *merge(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *head;
        ListNode *prev;

        if (list1->val < list2->val)
        {
            prev = head = list1;
            list1 = list1->next;
        }
        else
        {
            prev = head = list2;
            list2 = list2->next;
        }

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                prev->next = list1;
                list1 = list1->next;
            }
            else
            {
                prev->next = list2;
                list2 = list2->next;
            }

            prev = prev->next;
        }

        while (list1)
        {
            prev->next = list1;
            list1 = list1->next;
            prev = prev->next;
        }

        while (list2)
        {
            prev->next = list2;
            list2 = list2->next;
            prev = prev->next;
        }

        return head;
    }
};

int main()
{
    ListNode *one1 = new ListNode(1);
    ListNode *two1 = new ListNode(2);
    ListNode *three1 = new ListNode(3);

    one1->next = two1;
    two1->next = three1;

    ListNode *one2 = new ListNode(1);
    ListNode *two2 = new ListNode(3);
    ListNode *three2 = new ListNode(4);

    one2->next = two2;
    two2->next = three2;

    ListNode *list1 = one1;
    ListNode *list2 = one2;

    ListNode *result = Solution::merge(list1, list2);

    while (result)
    {
        cout << result->val << endl;
        result = result->next;
    }

    return 0;
}