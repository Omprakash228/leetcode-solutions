#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

class Solution {
public:
    static ListNode* mergeListsPq(vector<ListNode*> lists) {
        //lambda expression
        auto cmp = [](const ListNode* a, const ListNode* b){ return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for(int i = 0; i < lists.size(); i++) {
            ListNode* t = lists[i];
            if(t != NULL)
                pq.push(t);
        }

        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(pq.size() > 0) {
            curr->next = pq.top();
            pq.pop();

            curr = curr->next;
            if(curr->next != NULL) {
                pq.push(curr->next);
            }
        }

        return head->next;
    }

    static ListNode* mergeLists(vector<ListNode*> lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];

        ListNode* result = merge2Lists(lists[0], lists[1]);

        for(int i = 2; i < lists.size(); i++) {
            result = merge2Lists(result, lists[i]);
        }

        return result;
    }

    static ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* head = new ListNode(0);
        ListNode* curr = head;

        while(list1 != NULL && list2 != NULL) {
            if(list1->val < list2->val) {
                curr->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                curr->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(list1 != NULL) {
            curr->next = list1;
        }
        if(list2 != NULL) {
            curr->next = list2;
        }
        return head->next;
    }
};

int main() {
    ListNode* one1 = new ListNode(1);
    ListNode* two1 = new ListNode(4);
    ListNode* three1 = new ListNode(5);

    one1->next = two1;
    two1->next = three1;

    ListNode* one2 = new ListNode(1);
    ListNode* two2 = new ListNode(3);
    ListNode* three2 = new ListNode(4);
    
    one2->next = two2;
    two2->next = three2;

    ListNode* one3 = new ListNode(2);
    ListNode* two3 = new ListNode(6);

    vector<ListNode*> lists{one1, one2, one3};

    ListNode* result = Solution::mergeListsPq(lists);

    while(result) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}