typedef pair<int ,int> Ttweets;
typedef unordered_map<int, vector<Ttweets> > Tuser2msg_map;
typedef unordered_map<int, vector<int> > Tfollow_map;
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter(): global_idx(0) { }
    
    inline int generate_idx() {
        return global_idx++;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        Tuser2msg_map::iterator iter;
        int idx = generate_idx();
        if ((iter = user2msg.find(userId)) != user2msg.end()) {
            iter->second.push_back(Ttweets(idx, tweetId));
        } else {
            vector<Ttweets> tweet_list;
            tweet_list.push_back(pair<int, int>(idx, tweetId));
            user2msg.insert(pair<int, vector<Ttweets> >(userId, tweet_list));
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Ttweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        Tuser2msg_map::iterator iter1;
        vector<int> new_Ttweets;
        if ((iter1 = user2msg.find(userId)) == user2msg.end()) {
            vector<Ttweets> v;
            user2msg.insert(pair<int, vector<Ttweets> >(userId, v));
            iter1 = user2msg.find(userId);
        }
        vector<Ttweets> tweet_list = iter1->second;
        auto func = [](Ttweets a, Ttweets b) {return a.first < b.first;};
        priority_queue<Ttweets, vector<Ttweets>, decltype(func)> feeds(func);
        for (auto i = 0; i < tweet_list.size();++i) feeds.push(tweet_list[i]);

        Tfollow_map::iterator map_iter = follow_map.find(userId);
        if (map_iter!=follow_map.end()) {
            vector<int> follow_list = map_iter->second;
            for (auto i = 0; i < follow_list.size(); ++i) {
                Tuser2msg_map::iterator iter = user2msg.find(follow_list[i]);
                if (iter!=user2msg.end()) {
                    vector<Ttweets> l = iter->second;
                    for (auto j = 0; j < l.size(); ++j) feeds.push(l[j]);
                }
            }
        }
        for (int i = 0; !feeds.empty() && i < 10; ++i) {
            new_Ttweets.push_back(feeds.top().second);
            feeds.pop();
        }
        return new_Ttweets;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId==followeeId) return;
        Tfollow_map::iterator iter;
        if ((iter = follow_map.find(followerId))!=follow_map.end()) {
            if (find(iter->second.begin(), iter->second.end(), followeeId)!=iter->second.end()) return;
            iter->second.push_back(followeeId);
        } else {
            vector<int> follow_list;
            follow_list.push_back(followeeId);
            follow_map.insert(pair<int, vector<int> >(followerId, follow_list));
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        Tfollow_map::iterator iter;
        if ((iter = follow_map.find(followerId))!= follow_map.end()) {
            vector<int>::iterator inner_iter = find(iter->second.begin(), iter->second.end(), followeeId);
            if (inner_iter!=iter->second.end()) {
                iter->second.erase(inner_iter);
            }
        }
    }
private:
    Tuser2msg_map user2msg;
    Tfollow_map follow_map;
    int global_idx;
};