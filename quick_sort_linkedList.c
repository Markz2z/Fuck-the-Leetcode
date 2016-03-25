#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
    int val;
    struct Node* next;
}Node;

Node* swap(Node** node1_prev, Node** node1, Node** node1_succ, Node** node2_prev, Node** node2, Node** node2_succ) {
    if(node1_prev && *node1_prev && node2 && *node2) {
        (*node1_prev)->next = *node2;
    }
    if(node1_succ && *node1_succ && node2 && *node2) {
        (*node2)->next = *node1_succ;
    }

    if(node2_prev && *node2_prev && node1 && *node1) {
        (*node2_prev)->next = *node1;
    }

    if(node2_succ && *node2_succ && node1 && *node1) {
        (*node1)->next = *node2_succ;
    }
}

Node* partition(Node* prev, Node** ptr_head, Node* tail) {
    Node* head = *ptr_head;
    int pivot = head->val;
    Node* cur_min_prev = prev;
    Node* cur_min = head;
    Node* cur_min_succ = head->next;
    Node* mid = NULL;

    Node* cur = head->next;
    Node* cur_prev = head;
    Node* cur_succ = cur->next==NULL?NULL:cur->next;
    Node* real_tail = NULL;
    while(cur!=tail) {
        if(cur->val < pivot) {
            cur_min_prev = cur_min;
            cur_min = cur_min->next;
            cur_min_succ = cur_min->next;

            swap(&cur_min_prev, &cur_min, &cur_min_succ, &cur_prev, &cur, &cur_succ);
            /*cur_min_prev->next = cur;
            cur->next = cur_min_succ;
            cur_prev->next = cur_min;
            cur_min->next = cur_succ;
            cur = cur_min;
            cur_min = cur_min_prev->next;*/
        }
        real_tail = cur;
        cur = cur->next;
    }
    
    cur_min_prev->next = head;
    head->next = cur_min_succ;
    cur_min->next = head->next;
    mid = head;
    head = cur_min;

    if(prev) 
        prev->next = head;
    if(tail)
        real_tail->next = tail;
    return mid;
}

void quicksort(Node* prev, Node* head, Node* tail) {
    if(head && head->next) {
       Node* mid = partition(prev, &head, tail);
       quicksort(prev, head, mid);
       quicksort(mid, mid->next, tail);
    }
}

Node* create_node(int val) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->val = val;
    ptr->next = NULL;
    return ptr;
}

Node* create_list(int arr[], int len) {
    int i = 0;
    Node* head = NULL;
    Node* cur = NULL;
    if(len>=1) {
        head = create_node(arr[0]);
        cur = head;
    }
    
    for(i=1;i<len;++i) {
       cur->next = create_node(arr[i]);
       cur = cur->next;
    }
    return head;
}

void print(Node* head) {
    while(head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}

int main() {
    int arr[5] = {1,3,5,2,-5};
    Node* head = create_list(arr, 5);
    quicksort(NULL, head, NULL);
    print(head);
    return 1;
}


