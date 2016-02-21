void merge(int* nums1, int m, int* nums2, int n) {
    int *res = (int *)malloc(sizeof(int) * (m+n));
    int i = 0, j = 0, k = 0;
    while(i<m && j < n) {
        res[k++] = nums1[i] > nums2[j] ? nums2[j++] : nums1[i++];
    }
    while(i<m)
        res[k++] = nums1[i++];
    while(j<n)
        res[k++] = nums2[j++];
    memcpy(nums1, res, sizeof(int) * (m+n));
}