struct cmp{
    int operator()(int a, int b){
        return a<b;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int,vector<int>, cmp> q;
            for(int i:nums) q.push(i);

            for(int i=1;i<k;i++) {
            if(!q.empty()) q.pop();
            }
            return q.top();
    }
};