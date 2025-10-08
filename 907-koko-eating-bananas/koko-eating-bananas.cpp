class Solution {
    bool finished(vector<int>&piles, int k, int h){
        long long res=0;
        for(int it:piles){
            res+=ceil(it/(k*1.0));

        }
        return res<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(finished(piles,mid,h)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};