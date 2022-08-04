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
    static ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *prev = NULL;
        ListNode *current_node = head;

        while (left > 1)
        {
            prev = current_node;
            current_node = current_node->next;
            left--;
            right--;
        }

        ListNode *connection = prev;
        ListNode *tail = current_node;

        while (right > 0)
        {
            ListNode *next = current_node->next;
            current_node->next = prev;
            prev = current_node;
            current_node = next;
            right--;
        }

        if (connection)
            connection->next = prev;
        else
            head = prev;

        tail->next = current_node;
        return head;
    }
};

int main()
{
    ListNode *one = new ListNode(3);
    ListNode *two = new ListNode(5);
    // ListNode *three = new ListNode(3);
    // ListNode *four = new ListNode(4);
    // ListNode *five = new ListNode(5);
    // ListNode *six = new ListNode(6);
    // ListNode *seven = new ListNode(7);
    // ListNode *eight = new ListNode(8);

    one->next = two;
    // two->next = three;
    // three->next = four;
    // four->next = five;
    // five->next = six;
    // six->next = seven;
    // seven->next = eight;

    ListNode *head = one;

    ListNode *reverseHead = Solution::reverseBetween(head, 1, 2);

    while (reverseHead)
    {
        cout << reverseHead->val << " ";
        reverseHead = reverseHead->next;
    }

    return 0;
}