#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        
        ListNode* reverse_head = head;
        ListNode* curr_node = head->next;
        reverse_head->next = NULL;
        
        while(curr_node) {
            ListNode* next_node = curr_node->next;
            
            curr_node->next = reverse_head;
            reverse_head = curr_node;
            curr_node = next_node;
        }
        
        return reverse_head;
    }
};

void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << endl;
        head = head->next;
    }
}


int main() {
    ListNode* head;
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);

    one->next = two;
    two->next = three;

    head = one;

    ListNode* reversed_head = Solution::reverseList(head);
    printList(reversed_head);

    return 0;
}