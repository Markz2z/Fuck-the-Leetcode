void moveZeroes(int* nums, int numsSize) {
	int zeros = 0;
	int pivot = -1;
	int i = 0;
	int temp = 0;
	while(i<numsSize) {
		if(nums[i]!=0 && pivot!=-1) {
			temp = nums[i];
			nums[i] = 0;
			nums[pivot] = temp;
			pivot++;
		}
		if(nums[i]==0) {
			zeros++;
			if(pivot==-1) {
				pivot = i;
			}
		}
		i++;
	}
}