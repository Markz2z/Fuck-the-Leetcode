class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() { }

    void push(int x) {
        if (min_.empty()) min_.push_back(x);
        else if (x <= getMin()) min_.push_back(x);
        nums_.push_back(x);
    }

    void pop() {
        if (nums_.back()==min_.back()) min_.pop_back();
        nums_.pop_back();
    }

    int top() {
        return nums_.back();
    }

    int getMin() {
        return min_.back();
    }
private:
    vector<int> nums_;
    vector<int> min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */