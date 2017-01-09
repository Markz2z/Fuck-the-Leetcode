class Solution {
public:
    void replace(string& str, char c) {
        int i = 0, k = 0;
	    for (; i < str.size(); ++i) {
		    if (str[i]!=c) {
			    str[k++] = str[i];
			}
		}
		str.erase(k, str.size() - k);
	}

    string removeDuplicateLetters(string s) {
	    string result = "";
		unordered_map<char, int> count_map;
		unordered_map<char, int>::iterator iter;
		while (s.size() > 0) {
		    count_map.clear();
			for (int i = 0; i < s.size(); ++i) {
	   	        if ((iter = count_map.find(s[i])) == count_map.end()) {
			        count_map.insert(pair<char, int>(s[i], 1));
			    } else {
			        iter->second++;
			    }
	 	    }
		    int min = 0;
		    for (int j = 0; j < s.size(); ++j) {
			    if (s[j] < s[min]) min = j;
				--count_map[s[j]];
				if (count_map[s[j]] == 0) {
				    result += s[min];
					char tmp = s[min];
					s = s.substr(min+1);
					replace(s, tmp);
					break;
				}
			}
		}
		return result;
	}
};
