class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.size(), t_len = t.size();
        if (t_len > s_len) {
            return "";
        }
        if (t_len == 1) {
            if (s.contains(t)) {
                return t;
            } else {
                return "";
            }
        }
        unordered_map<char, int> s_map, t_map;
        for (char c : t) {
            t_map[c]++;
        }
        int match = 0;
        int t_u_chars = t_map.size();
        int shortest_win_start = -1;
        int shortest_win_len = INT_MAX;
        int l = 0;

        for (int r = 0; r < s_len; r++) { 
            char c = s[r];
            s_map[c]++;

            if (t_map.count(c) && s_map[c] == t_map[c]) {
                match++;
            }
            while (match == t_u_chars) {
                if ((r - l + 1) < shortest_win_len) {
                    shortest_win_start = l;
                    shortest_win_len = r - l + 1;
                }

                char in_c = s[l];
                s_map[in_c]--;
                if (t_map.count(in_c) && s_map[in_c] < t_map[in_c]) {
                    match--;
                }
                l++;
            }
        }
        if (shortest_win_len == INT_MAX) {
            return "";
        } else {
            return s.substr(shortest_win_start, shortest_win_len);
        }

    }
};
