inline int min(int num1, int num2) {
	return num1 > num2 ? num2 : num1;
}

double findKthInArrays(int *array1, int len1, int *array2, int len2, int k) {
	if (len1 > len2)
		return findKthInArrays(array2, len2, array1, len1, k);
	if (!len1)
		return array2[k - 1];
	if (k == 1)
		return min(array1[0], array2[0]);
	int pa = min(k / 2, len1), pb = k - pa;
	if(array1[pa - 1] < array2[pb - 1])
		return findKthInArrays(array1 + pa, len1 - pa, array2, len2, k - pa);
	else if(array1[pa - 1] > array2[pb - 1]) {
		return findKthInArrays(array1, len1, array2 + pb, len2 - pb, k - pb);
	}else {
		return array1[pa - 1];
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int total = nums1Size + nums2Size;
	if(total & 0x01) {
		return findKthInArrays(nums1, nums1Size, nums2, nums2Size, total/2+1);
	}else {
		return (findKthInArrays(nums1, nums1Size, nums2, nums2Size, total/2)
					+ findKthInArrays(nums1, nums1Size, nums2, nums2Size, total/2+1))/2;
	}
}