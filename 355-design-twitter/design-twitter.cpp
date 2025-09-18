#include <bits/stdc++.h>
using namespace std;

int timeCounter = 0;

class Twitter {
    map<int, set<int>> follo;
    map<int, vector<pair<int, int>>> posts;
    // time id
public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timeCounter, tweetId});
        timeCounter++;
        return;
    }

    vector<int> getNewsFeed(int userId) {
        int count = 10;
        vector<int> ans;
        // time postid
        priority_queue<pair<int, int>> q;

        for (int i = posts[userId].size() - 1; i >= 0; i--) {
            pair<int, int> p = posts[userId][i];
            q.push({p.first, p.second});
        }

        for (int it : follo[userId]) {
            for (int i = posts[it].size() - 1; i >= 0; i--) {
                pair<int, int> p = posts[it][i];
                q.push({p.first, p.second});
            }
        }

        while (count && !q.empty()) {
            pair<int, int> p = q.top();
            q.pop();
            ans.push_back(p.second);
            count--;
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        follo[followerId].insert(followeeId);
        return;
    }

    void unfollow(int followerId, int followeeId) {
        follo[followerId].erase(followeeId);
        return;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
