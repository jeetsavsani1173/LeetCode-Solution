//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Twitter {
  public:
    map<int,vector<pair<int,int>>> posts;
    map<int,set<int>> friendList;
    long long time; 
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto it:posts[userId]){
            pq.push(it);
        }
        
        for(auto f:friendList[userId]){
            for(auto it:posts[f]){
                pq.push(it);
            }
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            if(ans.size()==10) return ans;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            friendList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friendList[followerId].erase(followeeId);
    }
};

//{ Driver Code Starts.

int main() {
    Twitter obj;

    int total_queries;
    cin >> total_queries;
    while (total_queries--) {
        int query;
        cin >> query;

        // if query = 1, postTweet()
        // if query = 2, getNewsFeed()
        // if query = 3, follow()
        // if query = 4, unfollow()

        if (query == 1) {
            int userId, tweetId;
            cin >> userId >> tweetId;
            obj.postTweet(userId, tweetId);
        } else if (query == 2) {
            int userId;
            cin >> userId;
            vector<int> vec = obj.getNewsFeed(userId);
            for (int a : vec) cout << a << " ";
            cout << endl;
        } else if (query == 3) {
            int follower, followee;
            cin >> follower >> followee;
            obj.follow(follower, followee);
        } else {
            int follower, followee;
            cin >> follower >> followee;
            obj.unfollow(follower, followee);
        }
    }
    return 0;
}
// } Driver Code Ends