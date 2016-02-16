/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        HashSet<ListNode> setA = new HashSet<>();
        HashSet<ListNode> setB = new HashSet<>();
        if(headA!=null && headB!=null) {
	        while(headA.next!=null && headB.next!=null){
	        	setA.add(headA);
	        	setB.add(headB);
	        	if(setB.contains(headA))
	        		return headA;
	        	if(setA.contains(headB))
	        		return headB;
	        	headA = headA.next;
	        	headB = headB.next;
	        }
	        if(headA!=null) {
	        	setA.add(headA);
	        	headA = headA.next;
	        	if(setB.contains(headA))
	        		return headA;
	        }
	        if(headB!=null) {
	        	setA.add(headA);
	        	headA = headA.next;
	        	if(setB.contains(headA))
	        		return headA;
	        }
	    }
        return null;
    }
}