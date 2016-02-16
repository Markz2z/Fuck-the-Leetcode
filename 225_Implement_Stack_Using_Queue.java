class MyStack {

    Queue<Integer> queue1 = new LinkedList<Integer>();
    Queue<Integer> queue2 = new LinkedList<Integer>();
    boolean is_dump = false;
    int top_ = 0;
    
    public void dump(Queue<Integer>q1, Queue<Integer> q2){
        while(!q1.isEmpty()){
            top_ = q1.poll();
            q2.offer(top_);
        }
    }
    
    // Push element x onto stack.
    public void push(int x) {
        if(is_dump){
            dump(queue2, queue1);
            is_dump = false;
        }
        queue1.offer(x);
    }

    public void pop_element(Queue<Integer>q1, Queue<Integer> q2) {
        while(q1.size()>1){
            top_ = q1.poll();
            q2.offer(top_);
        }
        q1.clear();
    }
    
    // Removes the element on top of the stack.
    public void pop() {
        if(!is_dump){
            pop_element(queue1, queue2);
            is_dump = true;
        }else{
            pop_element(queue2, queue1);
            is_dump = false;
        }
    }

    // Get the top element.
    public int top() {
        if(!is_dump){
            dump(queue1, queue2);
            is_dump = true;
        }
        return top_;
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return queue1.isEmpty() && queue2.isEmpty();
    }
}