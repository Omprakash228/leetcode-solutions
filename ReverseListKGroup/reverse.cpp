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
    static ListNode *reverse(ListNode *head, int k)
    {
        if (!head)
            return NULL;

        ListNode *current_node = head;
        int size = 0;

        while (current_node)
        {
            current_node = current_node->next;
            size++;
        }

        ListNode *prev = NULL;
        current_node = head;

        while (size >= k)
        {
            int gsize = k;
            ListNode *connection = prev;
            ListNode *tail = current_node;
            while (gsize > 0)
            {
                ListNode *next = current_node->next;
                current_node->next = prev;
                prev = current_node;
                current_node = next;
                gsize--;
            }

            if (connection)
            {
                connection->next = prev;
            }
            else
            {
                head = prev;
            }

            tail->next = current_node;
            prev = tail;
            size = size - k;
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
    ListNode *six = new ListNode(6);
    ListNode *seven = new ListNode(7);
    ListNode *eight = new ListNode(8);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;

    ListNode *head = one;

    ListNode *resultHead = Solution::reverse(head, 2);

    while (resultHead)
    {
        cout << resultHead->val << " ";
        resultHead = resultHead->next;
    }

    return 0;
}