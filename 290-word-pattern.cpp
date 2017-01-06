list<string> tokenize(string text, string sep){
    int last_pos=0;
    int pos=0;
    list<string> listWords;
    while(true){
        pos=text.find_first_of(sep,last_pos);
        if(pos==string::npos){
            break;
        }else{
            listWords.push_back(text.substr(last_pos,pos-last_pos));
            last_pos=pos+1;
        }
    };
    if (pos!=last_pose) listWords.push_back(text.substr(last_pos,pos-last_pos));
    return listWords;
}

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        list<string> words = tokenize(str, " ");
        map<char, string> map_;
        set<string> set_;
        if (words.size()!=pattern.size()) return false;
        if (words.size()==1) return true;
        list<string>::iterator iter;
        map<char, string>::iterator idx;
        int i;
        for (i=0, iter=words.begin(); i < words.size() && iter!=words.end(); ++i, ++iter) {
            if ((idx = map_.find(pattern[i])) == map_.end()) {
                if (set_.find(*iter)!=set_.end()) return false;
                set_.insert(*iter);
                map_.insert(pair<char, string>(pattern[i], *iter));
            } else {
                if (idx->second.compare(*iter)!=0) return false;
            }
        }
        return true;
    }
};