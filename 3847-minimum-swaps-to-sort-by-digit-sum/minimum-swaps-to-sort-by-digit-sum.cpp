class Solution {
public:
     int helper(int x) {
        int total = 0;
        while (x > 0) {
            total += x % 10;
            x /= 10;
        }
        return total;
    }
    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> initial;
        for (int i = 0; i < nums.size(); ++i) {
            initial[nums[i]] = i;
        }

        // Custom stable sort logic matching Python's dual sort approach
        stable_sort(nums.begin(), nums.end(), [this](int a, int b) {
            int sumA = helper(a);
            int sumB = helper(b);
            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a < b; // Fallback to value sorting if digit sums are equal
        });

        unordered_set<int> visited;
        int res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (visited.count(i)) {
                continue;
            }

            int j = i;
            int steps = 0;
            while (!visited.count(j)) {
                visited.insert(j);
                steps++;
                j = initial[nums[j]];
            }
            res += (steps - 1);
        }

        return res;
    }
};