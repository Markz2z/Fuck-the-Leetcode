
public class LRU{
    public static void main(String[] args){
        LRUCache cache = new LRUCache(5);
        cache.set(1, 10);
        cache.set(2, 20);
        cache.print();
    }
}

class LRUCache {

	Node head;
	Node tail;
	Node free;
	int  used;
	int capacity;

	class Node {
		Node next;
		int  val;
		int  key;
		Node() {
			this.val = -1;
			this.next = null;
		}
	}

    public LRUCache(int capacity) {
    	head = new Node();
    	Node temp = head;
    	this.capacity = capacity;
    	this.used = 0;
    	if(capacity>1) {
    		while(capacity>1) {
    			temp.next = new Node();
    			temp = temp.next;
    			capacity--;
    		}
    	}
    	tail = temp;
    	free = head;
    }

    public int get(int key) {
    	Node var = head;
        while(var!=free) {
        	if(var.key==key)
        		return var.value;
        	var = var.next;
        }
        return -1;
    }
    
    public void set(int key, int value) {
        if(this.used<this.capacity) {
        	free.key = key;
        	free.value = value;
        	free = free.next;
        	used++;
        }
    }

    public void print() {
    	Node var = head;
    	while(var!=free) {
    		System.out.println("key:" + var.key +" val:" + var.val);
    		var = var.next;
    	}
    }
}