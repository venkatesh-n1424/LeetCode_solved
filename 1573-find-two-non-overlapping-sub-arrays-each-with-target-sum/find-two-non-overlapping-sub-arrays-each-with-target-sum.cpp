class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
         int n = arr.size();
        int ps = 0; // Prefix sum
        int res = 2e9; // Using a large number as infinity (safe upper bound)
        vector<int> dp(n, 2e9); // dp[r] stores the min length of a valid subarray found in arr[0...r]
        
        int l = 0; // Left pointer for the sliding window
        for (int r = 0; r < n; ++r) {
            ps += arr[r];
            
            // Shrink window if the current sum exceeds target
            while (ps > target && l <= r) {
                ps -= arr[l];
                l++;
            }
            
            // Carry forward the minimum length from the previous index
            if (r > 0) {
                dp[r] = dp[r - 1];
            }
            
            // If a valid window is found
            if (ps == target) {
                int current_len = r - l + 1;
                
                // If a valid subarray exists to the left of our current window
                if (l > 0 && dp[l - 1] != 2e9) {
                    res = min(res, current_len + dp[l - 1]);
                }
                
                // Update DP table for the current index with the minimum length seen so far
                dp[r] = min(dp[r], current_len);
            }
        }
        
        return res >= 2e9 ? -1 : res;
    }
};