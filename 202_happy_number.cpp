class Solution {
public:
	int get_square(std::stack<int>& stack) {
		int sum = 0;
		int top = 0;
		while(stack.size()>0) {
			top = stack.top();
			sum += top * top;
			stack.pop();
		}
		return sum;
	}

	void store_in_stack(int num, std::stack<int>& stack_) {
		while(num>0) {
			stack_.push(num%10);
			num /= 10;
		}
	}

	bool is_contain(int num, std::vector<int> used) {
		for(std::vector<int>::iterator iter=used.begin();iter<used.end();++iter) {
			if(num==*iter)
				return true;
		}
		return false;
	}

    bool isHappy(int n) {
    	std::vector<int> used;
    	used.push_back(n);
    	std::stack<int> stack;
    	store_in_stack(n, stack);
    	int cal_num = get_square(stack);
    	while(cal_num>1 && !is_contain(cal_num, used)) {
    		used.push_back(cal_num);
    		store_in_stack(cal_num, stack);
    		cal_num = get_square(stack);
    	}
    	if(cal_num == 1) {
    		return true;
    	}else {
    		return false;
    	}
    }
};