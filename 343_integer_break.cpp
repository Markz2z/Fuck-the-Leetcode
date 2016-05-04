class Solution {
public:
    int integerBreak(int n) {
        int count[n+1];
        count[0] = 0;
        count[1] = 1;
        count[2] = 1;
        int max  = 2;
        if(n<=2)
            return count[n];
        for(int i=2;i<=n;++i) {
            int cal = 0;
            max = 0;
            for(int j=1;j<=i-1;j++) {
                cal = count[j] * (i-j);
                max = max < cal ? cal : max;
            }
            if(i<n) {
                count[i] = max > i ? max : i;
            }else {
                count[i] = max;
            }
        }
        return count[n];
    }
};