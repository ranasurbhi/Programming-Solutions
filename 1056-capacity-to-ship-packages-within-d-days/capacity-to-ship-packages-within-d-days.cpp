class Solution {
    bool check(vector<int>&weights, int days, int cap){
        int cnt=1;
        int summ=0;
        for(int it:weights){
            summ+=it;
            if(summ>cap){
                summ=it;
                cnt++;
            }
        }
        return cnt<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r=0;
        for(int it:weights){
            r+=it;
        }
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(weights,days,mid)){
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