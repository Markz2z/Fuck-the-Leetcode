/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int * returnSize = (int *)malloc(sizeof(int)*2);
    int i = 0, result = 0;
    while(i<numsSize) {
    	i++;
    	result ^= nums[i];
    }
}