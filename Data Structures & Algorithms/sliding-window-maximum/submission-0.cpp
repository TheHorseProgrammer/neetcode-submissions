class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (k >= n) {
            return {*max_element(nums.begin(), nums.end())};
        }
        map<int, int> window;
        vector<int> ret(n - k + 1);
        for (int i = 0; i < n; i++) {
            window[nums[i]]++;
            if (i >= k) {
                window[nums[i - k]]--;
                if (window[nums[i - k]] == 0) {
                    window.erase(nums[i - k]);
                }
            }
            if (i >= k - 1) {
                ret[i - k + 1] = window.rbegin()->first;
            }
        }
        return ret;
    }
};
