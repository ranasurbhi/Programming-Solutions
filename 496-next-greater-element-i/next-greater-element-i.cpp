class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int,int>ansmap;
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<nums2.size();i++)
        {
            while(!st.empty() && nums2[i]>st.top())
            {
                ansmap[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        for(auto it:nums1)
        {
            if(ansmap[it]==0)
                ans.push_back(-1);
            else
                ans.push_back(ansmap[it]);     
        }
        return ans;
    }
};