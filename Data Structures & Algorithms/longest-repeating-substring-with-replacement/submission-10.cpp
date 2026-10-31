class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        array<int, 26> char_map{};        
        int ret = 0;

        int l = 0, maxc = 0;

        for (int r = 0; r < n; r++) {
            char_map[s[r] - 'A']++;
            maxc = max(maxc, char_map[s[r] - 'A']);

            while ((r - l + 1) - maxc > k) {
                char_map[s[l] - 'A']--;
                l++;
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
