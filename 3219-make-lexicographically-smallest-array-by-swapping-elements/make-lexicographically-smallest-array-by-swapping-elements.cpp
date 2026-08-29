class UF {
public:
    unordered_map<int, int> par;
    int limit;

    UF(const vector<int>& nums, int limit) {
        this->limit = limit;
        for (int x : nums) {
            par[x] = x;
        }
    }

    int find(int x) {
        if (par[x] != x) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    void unionNodes(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (abs(pa - pb) <= limit) {
            par[pa] = pb;
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        UF uf(nums, limit);
        
        vector<int> s = nums;
        sort(s.begin(), s.end());
        
        for (int i = 1; i < n; ++i) {
            uf.unionNodes(s[i - 1], s[i]);
        }
        
        // Maps component ID to a multiset (equivalent to SortedList)
        unordered_map<int, multiset<int>> comp_s1;
        vector<int> res(n);
        
        for (int i = 0; i < n; ++i) {
            int c = uf.find(nums[i]);
            res[i] = c;
            comp_s1[c].insert(nums[i]);
        }
        
        for (int i = 0; i < n; ++i) {
            int c = res[i];
            // Get the smallest element (equivalent to pop(0) in SortedList)
            auto it = comp_s1[c].begin();
            res[i] = *it;
            comp_s1[c].erase(it);
        }
        
        return res;
    }
};