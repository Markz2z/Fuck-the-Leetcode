class Solution {
public:
    inline int min(int n1, int n2, int n3) {
        int min1 = n1 < n2 ? n1 : n2;
        return min1 < n3 ? min1 : n3;
    }

    int nthUglyNumber(int n) {
        if (n<=0) return 0;
        vector<int> cnt(n);
        int x1 = 0, x2 = 0,x3 = 0;
        cnt[0] = 1;
        for (int i = 1; i < n; ++i) {
            cnt[i] = min(cnt[x1] * 2, cnt[x2] * 3, cnt[x3] * 5);
            if (cnt[i]==cnt[x1] * 2) ++x1;
            else if (cnt[i]==cnt[x2] * 3) ++x2;
            else ++x3;
            if (cnt[i]==cnt[i-1]) --i;
        }
        return cnt[n-1];
    }
};