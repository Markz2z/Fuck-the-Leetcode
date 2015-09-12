class Solution {
public:
    int numSquares(int n) {
        if(n>1){
            int count[n+1];
            int temp[n+1];
            count[0] = 0;
            count[1] = 1;
            int sqrt_res = 0;
            for(int i=2;i<=n;i++){
                sqrt_res = sqrt(i);
                for(int j=1;j<=sqrt_res;j++){
                    temp[j] = 1 + count[i-j*j];
                }
                count[i] = temp[1];
                for(int j=2;j<=sqrt_res;j++){
                    if(temp[j]<count[i]){
                        count[i] = temp[j];
                    }
                }
                for(int j=1;j<=sqrt_res;j++){
                    temp[j] = 0;
                }
            }
            return count[n];
        }else if(n==1){
            return 1;
        }else{
            throw new std::exception();
        }
    }

};
