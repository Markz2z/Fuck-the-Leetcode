/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists) {

    		int len = lists.size();

    		//save the head num for each list
    		int* array = (int*) malloc (sizeof(int) * len);
    		ListNode** current_node_list = (ListNode**)malloc(sizeof(int) * len);

    		//init current node list
    		for(int i=0;i<len;i++) {
    			current_node_list[i] = lists[i];
    		}

    		int max_list_index = -1;
    		int min = 0;
    		ListNode* merge_list_head = NULL;
    		ListNode* meger_list_cur = NULL;

    		max_list_index = generate_head(lists);
    		if(max_list_index!=-1) {
    			merge_list_head = current_node_list[max_list_index];
    			current_node_list[max_list_index] = current_node_list[max_list_index]->next;
    		}
	    }
	    return NULL;
    }
};