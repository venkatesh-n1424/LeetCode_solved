class Solution {
public:
    // int lc(string s){
    //     unordered_map<char,int> mpp;
    //     int c=INT_MIN;
    //     for(int i=0;i<s.size();i++){
    //         mpp[s[i]]++;
    //         if(mpp.size()>1){
    //             c=max(c,mpp[s[i-1]]);
    //             mpp.erase(s[i-1]);
    //         }
    //     }
    //     return max(c,mpp[s[s.size()-1]]);
    // }
    struct Node {
        int pre = 0; 
        int suf = 0;
        int maxLen = 0;
        char leftChar = 0;
        char rightChar = 0;
    };

    int n;
    vector<Node> segTree; //segmen tree size 4*n

    Node merge(const Node& L, const Node& R, int leftLen, int rightLen) {
        Node res;

        res.leftChar  = L.leftChar;
        res.rightChar = R.rightChar;

        res.pre = L.pre;
        if (L.pre == leftLen && L.rightChar == R.leftChar) {
            res.pre = L.pre + R.pre;
        }

        res.suf = R.suf;
        if (R.suf == rightLen && L.rightChar == R.leftChar) {
            res.suf = R.suf + L.suf;
        }

        res.maxLen = max(L.maxLen, R.maxLen);
        if (L.rightChar == R.leftChar) {
            res.maxLen = max(res.maxLen, L.suf + R.pre);
        }

        return res;
    }

    void buildSegmentTree(int i, int l, int r, string& s) {
        if (l == r) {
            segTree[i] = { 1, 1, 1, s[l], s[l] };
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, s);
        buildSegmentTree(2 * i + 2, mid + 1, r, s);
        segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) { //l == r == pos
            segTree[i] = { 1, 1, 1, ch, ch };
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        } else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }
        segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        //brute- O(k*n)
        //vector<int> res;
        // int k=queryIndices.size();
        // for(int i=0;i<k;i++){
        //     s[queryIndices[i]]=queryCharacters[i];
        //     res.emplace_back(lc(s));
        // }
        //optimal-segment tree-O(k*logn)
        n = s.size();
        segTree.assign(4 * n, Node()); //segmen tree size 4*n

        buildSegmentTree(0, 0, n - 1, s);

        int k = queryIndices.size();

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(0, 0, n - 1, pos, ch);
            
            result[i] = segTree[0].maxLen; //root node covers entire string
        }

        return result;
    }
};