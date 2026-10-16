const int MOD = 1e9 + 7;

struct Node {
    long long sum = 0;
    long long sum_of_squares = 0;
    long long lazy = 0;
};

class ST {
public:
    std::vector<Node> st;

    ST(int n) {
        st.resize(4 * n);
    }

    void apply(int node, int l, int r, long long val) {
        long long s = st[node].sum;
        long long sq = st[node].sum_of_squares;
        long long length = r - l + 1;

        // Update sum: (s + length * val) % MOD
        st[node].sum = (s + (length * val) % MOD) % MOD;

        // Update sum of squares: (sq + 2 * val * s + length * val^2) % MOD
        long long term1 = (2 * val % MOD * s) % MOD;
        long long term2 = (((length * val) % MOD) * val) % MOD;
        st[node].sum_of_squares = (sq + term1 + term2) % MOD;

        // Update lazy tag
        st[node].lazy = (st[node].lazy + val) % MOD;
    }

    void update(int node, int l, int r, int ql, int qr) {
        // Base Case: Current segment is completely within the query range
        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        // Push lazy value down to children (Lazy Propagation) using struct fields
        long long lazy = st[node].lazy;
        int mid = l + (r - l) / 2;
        if (lazy > 0 && l != r) {
            apply(node * 2, l, mid, lazy);
            apply(node * 2 + 1, mid + 1, r, lazy);
            st[node].lazy = 0; // Clear the lazy value of the parent
        }

        // Recurse for left and right children
        if (ql <= mid) {
            update(node * 2, l, mid, ql, qr);
        }
        if (qr > mid) {
            update(node * 2 + 1, mid + 1, r, ql, qr);
        }

        // Merge/Combine the results from children back into the parent
        auto& left = st[node * 2];
        auto& right = st[node * 2 + 1];
        st[node].sum = (left.sum + right.sum) % MOD;
        st[node].sum_of_squares = (left.sum_of_squares + right.sum_of_squares) % MOD;
    }
};
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        // int mod=1e9+7;
        // int n=nums.size(),res=0;
        // for(int i=0;i<n;i++){
        //     unordered_set<int> s;
        //     for(int j=i;j<n;j++){
        //         // TC-O(n^3)
        //         // unordered_set<int> s;
        //         // for(int k=i;k<=j;k++)
        //         //     if(!s.contains(nums[k])) s.insert(nums[k]);
        //         // res+=pow(s.size(),2);
        //         //TC-O(n^2)
        //         if(!s.contains(nums[j])) s.insert(nums[j]);
        //         res=(res+(long)pow(s.size(),2))%mod;
        //     }
        // }
        // return res;
       int n = nums.size();
        ST st(n); 
        std::unordered_map<int, int> last;
        long long res = 0;

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            
            // Get the last occurrence index, default to -1 if not found
            int p = last.count(num) ? last[num] : -1;
            
            // Update the segment tree in the range [p + 1, i]
            st.update(1, 0, n - 1, p + 1, i);
            
            // Accumulate the current sum of squares state of the root node
            res = (res + st.st[1].sum_of_squares) % MOD;
            
            // Update the last seen position of the current number
            last[num] = i;
        }

        return res;
    }
};