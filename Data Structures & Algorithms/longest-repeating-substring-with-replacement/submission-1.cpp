class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n < k + 1) {
            return n;
        }
        int l = 0;
        int r = 1;
        array<int, 26> char_map;
        int cur_large = s[0] - 'A';
        char_map[cur_large]++;
        int ret = 0;
        while (r < n) {
            char_map[s[r] - 'A']++;
            if (char_map[cur_large] + k < r - l + 1) {
                cur_large = max_element(char_map.begin(), char_map.end()) - char_map.begin();
                ret = max(ret, r - l);
                while (l < r && char_map[cur_large] + k < r - l + 1) {
                    int rev_char = s[l] - 'A';
                    char_map[rev_char]--;
                    if (rev_char == cur_large) {
                        cur_large = max_element(char_map.begin(), char_map.end()) - char_map.begin();
                    }
                    l++;
                }
            }
            r++;
        }
        ret = max(ret, r - l);
        return ret;
    }
};
