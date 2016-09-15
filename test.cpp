#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;
 
class Solution {
public:
    void insert(ListNode* start, ListNode* end, ListNode* insert_node) {
        ListNode* cur = start->next;
        ListNode* prev = start;
        while(cur->val < insert_node->val) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = insert_node;
        insert_node->next = cur;
    }

    ListNode* insertionSortList(ListNode* head) {
        if (!head || (head && head->next == nullptr)) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head;
        while(cur->next != nullptr) {
            if (cur->val > cur->next->val) {
                ListNode* adjust_node = cur->next;
                cur->next = adjust_node->next;
                //adjust the linkedlist from dummy to adjust_node
                insert(dummy, cur, adjust_node);
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};


int main() {
    ListNode* n1 = new ListNode(8);
    ListNode* n2 = new ListNode(7);
    ListNode* n3 = new ListNode(6);
    ListNode* n4 = new ListNode(5);
    ListNode* n5 = new ListNode(4);
    ListNode* n6 = new ListNode(3);
    ListNode* n7 = new ListNode(2);
    ListNode* n8 = new ListNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = nullptr;
    Solution solution;
    n1 = solution.insertionSortList(n1);
    while(n1) {
        cout << n1->val << "  ";
        n1  = n1->next;
    }
    return 1;
}