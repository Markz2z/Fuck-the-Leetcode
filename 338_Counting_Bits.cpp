class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        if(num>=0) {
            int count[num+1];
            int i = 0;
            while(i<=num) {
                if(i==0){
                    count[i] = 0;
                    result.push_back(i);
                }else if(i==1) {
                    count[i] = 1;
                    result.push_back(i);
                }else {
                    if(i%2) {
                        count[i] = count[i>>1] + 1;
                    }else {
                        count[i] = count[i>>1];
                    }
                    result.push_back(count[i]);
                }
                ++i;
            }
        }
        return result;
    }
};