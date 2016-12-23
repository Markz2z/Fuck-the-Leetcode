#include "iostream"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void swap(ListNode* node1_prev, ListNode* node1, ListNode* node1_succ, 
        ListNode* node2_prev, ListNode* node2, ListNode* node2_succ) {
        if (!node1 || !node2 || node1 == node2) return;
        if (node1_succ == node2) {
            node1_prev->next = node2;
            node2->next = node1;
            node1->next = node2_succ;
        } else if (node2_succ == node1) {
            node2_prev->next = node1;
            node1->next = node2;
            node2->next = node1_succ;
        } else {
            node1_prev->next = node2;
            node2->next = node1_succ;
            node2_prev->next = node1;
            node1->next = node2_succ;
        }
    }

    ListNode* partition(ListNode* head_prev, ListNode* end) {
        ListNode *head = head_prev->next;
        if (!head) return nullptr;
        ListNode *cur = head->next, *left = head, *prev = head, *left_prev = head_prev;
        int pivot = head->val;
        while(cur && cur != end) {
            if (cur->val < pivot) {
                swap(prev, cur, cur->next, left, left->next, left->next->next);
                left_prev = left;
                left = left->next;
            }
            prev = cur;
            cur = cur->next;
        }
        swap(left_prev, left, left->next, head_prev, head, head->next);
        return head;
    }

    ListNode* sortList(ListNode* head_prev, ListNode* end) {
        ListNode* head = head_prev->next;
        if (head && head->next && head != end) {
            ListNode* mid = partition(head_prev, end);
            sortList(head_prev, mid);
            sortList(mid, end);
        }
        return head;
    }

    ListNode* sortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        sortList(dummy, NULL);
        return dummy->next;
    }
};