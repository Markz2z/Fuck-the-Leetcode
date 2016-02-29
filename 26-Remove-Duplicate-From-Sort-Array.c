int removeDuplicates(int* nums, int numsSize) {
	if(numsSize>0) {
		int i = 1;
		int cur = nums[0];
		int pos = 1;
		while(i<numsSize) {
			if(nums[i] != cur) {
				cur = nums[i];
				if(pos != i) {
					nums[pos] = nums[i];
				}
				++pos;
			}else {
				nums[i] = 0;
			}
			++i;
		}
		return pos;
	}
	return numsSize;
}