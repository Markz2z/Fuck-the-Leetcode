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

    ListNode* partition(ListNode* head_prev, ListNode* head, ListNode* end) {
        ListNode *cur = head->next, *left = head;
        int pivot = head->val;
        ListNode *prev = head, *left_prev = nullptr;
        while(cur && cur != end) {
            if (cur->val < pivot) {
                if (cur != left->next) {
                    swap(prev, cur, cur->next, left, left->next, left->next->next);
                }
                left_prev = left;
                left = left->next;
            }
            prev = cur;
            cur = cur->next;
        }
        swap(left_prev, left, left->next, head_prev, head, head->next);
        return head;
    }

    ListNode* sortList(ListNode* head_prev, ListNode* head, ListNode* end) {
        if (head && head->next && head != end) {
            ListNode* mid = partition(head_prev, head, end);
            sortList(head_prev, head_prev->next, mid);
            sortList(mid, mid->next, end);
        }
        return head;
    }

    ListNode* sortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        sortList(dummy, head, NULL);
        return dummy->next;
    }
};

void print(ListNode* root) {
    while(root) {
        cout << root->val << endl;
        root = root->next;
    }
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* cur = node1;

    cur->next = new ListNode(2);
    cur = cur->next;

    cur->next = new ListNode(3);
    cur = cur->next;

    cur->next = new ListNode(4);
    cur = cur->next;

    cur->next = new ListNode(5);
    cur = cur->next;

    cur->next = new ListNode(5);
    cur = cur->next;

    cur->next = new ListNode(-2);
    cur = cur->next;

    Solution s;

    print(s.sortList(node1));
    return 1;
}
