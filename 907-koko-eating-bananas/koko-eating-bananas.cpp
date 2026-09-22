class Solution {
public:
    int bs(vector<int>& piles,int& h,int l,int r){
        if(l==r) return l;
        int k=(l+r)/2;
        int hrs=0;
        for(const int& pile:piles){
            hrs+=(pile+k-1)/k;
        }
        if(hrs<=h) return bs(piles,h,l,k);
        return bs(piles,h,k+1,r);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_ele = *max_element(piles.begin(),piles.end());
        return bs(piles,h,1,max_ele);
    }
};