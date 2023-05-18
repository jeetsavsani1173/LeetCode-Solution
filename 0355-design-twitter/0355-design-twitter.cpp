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

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */