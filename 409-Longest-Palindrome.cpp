class Solution {
public:
    int longestPalindrome(string s) {
        int size = s.size();
        int max = 0, i;
        bool single = false;
        if (size <= 1) return size;
        int map[256];
        memset(map, 0, sizeof(int) * 256);
        for (i = 0; i < size; ++i) {
        	++map[s[i]];
        }
        for (i = 0; i < 256; ++i) {
            max += map[i] / 2 * 2;
            single = single ? single : map[i] % 2 ? true : false;
        }
        max = single ? ++max : max;
        return max;
    }
};