int singleNumber(int* nums, int numsSize) {
	int result = 0, i = 0;
	while(i<numsSize) {
		result ^= nums[i];
		i++;
	}
	return result;
}