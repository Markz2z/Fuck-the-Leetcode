class Solution {
public:
	inline void swap(int* num1, int* num2) {
		if (num1 && num2) {
		    int tmp = *num1;
		    *num1 = *num2;
		    *num2 = tmp;
	    }
	}

    void nextPermutation(vector<int>& nums) {
        int len = nums.size(), j;
        if (len==1) return;
        if (len==2) {
        	swap(&nums[0], &nums[1]);
        	return;
        }
        auto t = [](int* a, int* b) {return *a > *b;};
        priority_queue<int*, vector<int*>, decltype(t)> q(t);
        for (j = len-1 ; j >= 0; --j) {
        	q.push(&nums[j]);
        	if (q.top()==&nums[j]) {
        		q.pop();
        		swap(q.top(), &nums[j]);
        		break;
        	}
        }
        if (j==-1) {
        	int front = nums[0];
        	for (int i = 1; i < len; ++i) nums[i-1] = nums[i];
        	nums[len-1] = front;
        }
    }
};