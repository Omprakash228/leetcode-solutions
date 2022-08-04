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
    static ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = 0;
        ListNode *tmpHead = head;

        while (tmpHead != NULL)
        {
            size++;
            tmpHead = tmpHead->next;
        }

        tmpHead = head;
        int removeIndex = size - n;

        if (size == n)
        {
            return head->next;
        }

        int index = 0;
        while (tmpHead != NULL)
        {
            if (index == removeIndex - 1)
            {
                tmpHead->next = tmpHead->next->next;
                break;
            }
            index++;
            tmpHead = tmpHead->next;
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
    // two->next = three;
    // three->next = four;
    // four->next = five;

    ListNode *head = one;

    ListNode *resultHead = Solution::removeNthFromEnd(head, 1);

    while (resultHead != NULL)
    {
        cout << resultHead->val << " ";
        resultHead = resultHead->next;
    }
    cout << endl;

    return 0;
}