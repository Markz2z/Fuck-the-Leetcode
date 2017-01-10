class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size()!=t.size()) return false;
        if (s.size()<=1) return true;
        map<char, char> map_;
        set<char> set_;
        map<char, char>::iterator iter;
        for (int i = 0; i < s.size(); ++i) {
            if ((iter = map_.find(s[i]))==map_.end()) {
                if (set_.find(t[i])!=set_.end()) return false;
                set_.insert(t[i]);
                map_.insert(pair<char, char>(s[i], t[i]));
            } else {
                if (iter->second!=t[i]) return false;
            }
        }
        return true;
    }
};