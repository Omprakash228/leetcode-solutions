#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

class Solution
{
public:
    static ListNode *cyclePosition(ListNode *head)
    {
        if(!head) return NULL;
        unordered_set<ListNode *> nodeValues;
        nodeValues.insert(head);

        while (head->next)
        {
            unordered_set<ListNode *>::iterator it = nodeValues.find(head->next);
            if (it != nodeValues.end())
            {
                return head->next;
            }
            else
            {
                nodeValues.insert(head->next);
                head = head->next;
            }
        }
        return NULL;
    }
};

int main()
{
    ListNode *one = new ListNode(3);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(0);
    ListNode *four = new ListNode(4);

    one->next = two;
    two->next = three;
    three->next = four;
    // four->next = three;

    ListNode *head = one;

    ListNode *result = Solution::cyclePosition(head);

    cout << result->val << endl;
    return 0;
}