#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt){}
};

class Solution {
public: 
    static ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* low = head;
        ListNode* high = head->next;

        while(high != NULL) {
            if(low->val == high->val) {
                low->next = high->next;
                high = low->next;
            } else {
                low = high;
                high = high->next;
            }
        }

        return head;
    }
};

int main() {
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(1);
    ListNode* three = new ListNode(2);
    ListNode* four = new ListNode(3);
    ListNode* five = new ListNode(3);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    ListNode* head = one;

    ListNode* result = Solution::deleteDuplicates(head);

    while(result) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}