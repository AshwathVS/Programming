class Twitter {
private:
    map<int, set<int>> followers;
    map<int, vector<pair<int, int>> > tweets;
    int id=0;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(tweets.find(userId) == tweets.end()) {
            tweets.insert({userId, {}});
        }

        tweets[userId].push_back({++id, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        set<int> usrFollows = followers[userId];
        usrFollows.insert(userId);
        for(int candidate : usrFollows) {
            int cnt = 1;
            for(int i=tweets[candidate].size()-1; i>=0; i--) {
                pq.push(tweets[candidate][i]);
                cnt++;

                if(cnt > 10) break;
            }
        }

        int cnt = 0;
        while(!pq.empty() && cnt < 10) {
            res.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followers[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;

        if(followers.find(followerId) != followers.end()) {
            followers[followerId].erase(followeeId);
        }
    }
};