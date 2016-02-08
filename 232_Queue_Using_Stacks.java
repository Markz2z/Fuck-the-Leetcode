class MyQueue {

    Stack<Integer> stack1 = new Stack<>();
    Stack<Integer> stack2 = new Stack<>();
    boolean is_dump = false;
    
    // Push element x to the back of queue.
    public void push(int x) {
        if(!is_dump) {
            stack1.push(x);
        }else {
            dump(stack2, stack1);
            stack1.push(x);
            is_dump = false;
        }
    }

    public void dump(Stack<Integer> src, Stack<Integer> dst) {
        dst.clear();
        while(!src.isEmpty()) {
            dst.push(src.pop());
        }
    }
    
    // Removes the element from in front of queue.
    public void pop() {
        if(is_dump) {
            stack2.pop();
        }else {
            dump(stack1, stack2);
            is_dump = true;
            stack2.pop();
        }
    }

    // Get the front element.
    public int peek() {
        if(!is_dump) {
            dump(stack1, stack2);
            is_dump = true;
        }
        return stack2.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        if(stack1.isEmpty()&&stack2.isEmpty())
            return true;
        return false;
    }
}