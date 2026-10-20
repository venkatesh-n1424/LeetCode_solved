class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        // Helper function to validate if a chunk size 'd' is valid
        auto valid = [&](int d) -> bool {
            int prev_mx = 0;
            for (int i = d; i <= n; i += d) {
                int desc = -1;
                
                // Check for descending steps in the current chunk
                for (int j = i - d; j < i - 1; ++j) {
                    if (nums[j] > nums[j + 1]) {
                        if (desc != -1) return false; // More than one drop found
                        desc = j + 1;
                    }
                }
                
                int mn, mx;
                if (desc != -1) {
                    // If rotated, the boundary condition must hold
                    if (nums[i - 1] > nums[i - d]) return false;
                    mn = nums[desc];
                    mx = nums[desc - 1];
                } else {
                    mn = nums[i - d];
                    mx = nums[i - 1];
                }
                
                // Ensure the global sequence between chunks remains sorted
                if (mn < prev_mx) return false;
                prev_mx = mx;
            }
            return true;
        };

        // Find all divisors of n in O(sqrt(n)) time
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }

        int res = 0;
        for (int d : divisors) {
            if (valid(d)) {
                res += d;
            }
        }

        return res;
    }
};