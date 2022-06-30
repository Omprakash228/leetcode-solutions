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
        static bool isPalindrome(ListNode* head) {
            ListNode* reversed_head;
            ListNode* current = head;

            while(current != NULL) {
                ListNode* new_node = new ListNode(current->val);
                new_node->next = reversed_head;
                reversed_head = new_node;
                current = current->next;
            }

            while(head != NULL && reversed_head != NULL) {
                if(head -> val != reversed_head -> val)
                    return false;
                head = head -> next;
                reversed_head = reversed_head -> next;
            }
            return true;
        }

        static void printList(ListNode* head) {
            while(head != NULL) {
                cout << head->val << "\t";
                head = head->next;
            }
            cout << endl;
        }
};


int main() {
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    // ListNode* three = new ListNode(2);
    // ListNode* four = new ListNode(1);

    one->next = two;
    // two->next = three;
    // three->next = four;

    ListNode* head = one;
    cout << Solution::isPalindrome(head);
    return 0;
}