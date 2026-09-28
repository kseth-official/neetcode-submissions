class Twitter {
public:
    Twitter() : time(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Priority queue to merge k sorted lists: tuple of (timestamp, tweetId, userId, index_in_user_tweets)
        priority_queue<tuple<int, int, int, int>> pq;
        
        auto addLatest = [&](int uid) {
            if (userTweets.find(uid) != userTweets.end() && !userTweets[uid].empty()) {
                int idx = userTweets[uid].size() - 1;
                pq.push({userTweets[uid][idx].first, userTweets[uid][idx].second, uid, idx});
            }
        };
        
        // Tweets from the user themselves
        addLatest(userId);
        
        // Tweets from followees
        if (following.find(userId) != following.end()) {
            for (int fId : following[userId]) {
                addLatest(fId);
            }
        }
        
        vector<int> feed;
        while (!pq.empty() && feed.size() < 10) {
            auto [t, tweetId, uid, idx] = pq.top();
            pq.pop();
            feed.push_back(tweetId);
            
            if (idx > 0) {
                pq.push({userTweets[uid][idx - 1].first, userTweets[uid][idx - 1].second, uid, idx - 1});
            }
        }
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (following.find(followerId) != following.end()) {
            following[followerId].erase(followeeId);
        }
    }

private:
    int time;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> userTweets; // userId -> list of (timestamp, tweetId)
};