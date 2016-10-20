class Solution {
public:
    int lengthLongestPath(string input) {
        input+= '\n';
        int len = input.size(), ans = 0, spaceCnt = 0, curPathLen =0, dotFlag = 0;
        stack<pair<string, int> > st;
        string curDir, extension;
        for(int i = 0; i < len; i++) {
            if(input[i]!='\n') {
                if(input[i]!='\t') curDir += input[i];
                if(dotFlag) extension += input[i];
                if(input[i]=='\t') spaceCnt++;
                if(input[i]=='.') dotFlag = 1;
                continue;
            }
            while(!st.empty() && spaceCnt <= st.top().second) {
                curPathLen -= st.top().first.size();
                st.pop();
            }
            if(dotFlag) ans = max(curPathLen + (int)curDir.size() + 1, ans);
            else {
                st.push(make_pair("/"+ curDir, spaceCnt));
                curPathLen += curDir.size() + 1;
            }
            extension = "", dotFlag = 0, spaceCnt = 0, curDir = "";
        }
        return ans==0?0:ans-1;
    }
};