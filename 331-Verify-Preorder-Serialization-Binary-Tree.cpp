class Solution {
public:
    bool isValidSerialization(string preorder) {
        int uncomplete_roots = 0, leaf_nodes = 0;
        string::iterator iter;
        for (iter = preorder.begin(); iter < preorder.end(); ++iter) {
            if (*iter != '#') ++uncomplete_roots; else ++leaf_nodes;
            if (leaf_nodes==2) {
                --uncomplete_roots;
                --leaf_nodes;
            }
            while(*iter!=',' && iter < preorder.end()) ++iter;
            if (uncomplete_roots ==0 && iter < preorder.end()) return false;
        }
        return uncomplete_roots==0 ? true : false;
    }
};