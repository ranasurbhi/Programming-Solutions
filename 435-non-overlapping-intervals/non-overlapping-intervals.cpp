#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1];  
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int count = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if ((ans.back())[1] <= intervals[i][0]) {
                ans.push_back(intervals[i]);
            } else {
                count++;  
            }
        }

        
        // cout << "Sorted intervals: ";
        // for (auto& i : intervals)
        //     cout << "[" << i[0] << "," << i[1] << "] ";
        // cout << "\nNon-overlapping intervals: ";
        // for (auto& i : ans)
        //     cout << "[" << i[0] << "," << i[1] << "] ";
        // cout << "\n";

        return count;
    }
};
