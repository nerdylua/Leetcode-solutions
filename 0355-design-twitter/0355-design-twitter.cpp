class Twitter {
public:
    int timestamp;
    Twitter() {
        timestamp = 0;
    }

    unordered_map<int, vector<pair<int, int>>> tweets;
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, timestamp++});
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> feed;

        for (auto tweet : tweets[userId]) {
            feed.push_back(tweet);
        }

        for (int followeeId : following[userId]) {
            for (auto tweet : tweets[followeeId]) {
                feed.push_back(tweet);
            }
        }

        sort(feed.begin(), feed.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        vector<int> result;
        for (int i = 0; i < min(10, (int)feed.size()); ++i) {
            result.push_back(feed[i].first);  
        }
        return result;
    }

    unordered_map<int, unordered_set<int>> following; 
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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