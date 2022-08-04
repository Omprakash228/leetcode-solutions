#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    static bool hasCycle(ListNode *head)
    {
        ListNode *slowptr = head->next;
        ListNode *fastptr = head->next->next;

        while (slowptr != NULL && fastptr != NULL)
        {
            if (slowptr == fastptr)
                return true;

            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }

        return false;
    }
};

int main()
{
    ListNode *one = new ListNode(3);
    ListNode *two = new ListNode(2);
    // ListNode *three = new ListNode(0);
    // ListNode *four = new ListNode(4);

    one->next = two;
    // two->next = three;
    // three->next = four;

    ListNode *head = one;

    cout << Solution::hasCycle(head) << endl;

    return 0;
}