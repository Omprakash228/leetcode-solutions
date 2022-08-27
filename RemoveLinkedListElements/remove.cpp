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
    static ListNode* removeElements(ListNode* head, int val) {
        ListNode* resultHead = NULL;
        ListNode* temp = NULL;
    
        while(head != NULL) {
            if(head->val != val) {
                if(temp == NULL) {
                    temp = new ListNode(head->val);
                    resultHead = temp;
                } else {
                    temp->next = new ListNode(head->val);
                    temp = temp->next;
                }
            }    
            head = head->next;       
        }
        return resultHead;
    }

    static void printList(ListNode* head) {
        while(head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(6);
    ListNode* four = new ListNode(3);
    ListNode* five = new ListNode(4);
    ListNode* six = new ListNode(5);
    ListNode* seven = new ListNode(6);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;

    ListNode* head = one;

    ListNode* result = Solution::removeElements(head, 6);

    Solution::printList(result);

    return 0;
}