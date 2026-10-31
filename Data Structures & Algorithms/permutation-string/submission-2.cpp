class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        short s1_n = s1.size(), s2_n = s2.size();
        array<short, 26> short_count{}, long_count{};
        if (s1_n <= s2_n) {
            for (char c: s1) {
                short_count[c - 'a']++;
            }
            for (short i = 0; i < s1_n; i++) {
                long_count[s2[i] - 'a']++;
            }
            for (short i = s1_n; i < s2_n; i++) {
                if (short_count == long_count) {
                    return true;
                }
                long_count[s2[i] - 'a']++;
                long_count[s2[i - s1_n] - 'a']--;
            }
            return short_count == long_count;
        } else {
            return false;
        }
    }
};
