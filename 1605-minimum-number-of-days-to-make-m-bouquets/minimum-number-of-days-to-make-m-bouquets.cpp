class Solution {
    bool check(vector<int>& bloomDay, int m, int k, int day){
        int cnt=0;
        for(int it:bloomDay){
            if(it<=day){
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt==k) {
                m--;
                cnt=0;
            }

        }
        return m<=0;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(bloomDay,m,k,mid)){
                
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