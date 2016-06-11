/*
*
* Tag: HashMap & Sort
* Time: getNewsFeed: O(nlgn); Add/Remove Followers: O(1)
* Space: O(n)
*/
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        followship.clear();
        posttweets.clear();
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        posttweets[userId].push_back(make_pair(tweetId, timestamp ++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans, userlist;
        vector<pair<int,int>> tmp;
        int tot = 0, id = 0;
        tot = posttweets[userId].size();
        userlist.resize(followship[userId].size() + 1);
        userlist[id ++] = userId;
        unordered_set<int>::iterator it = followship[userId].begin();
        for(; it != followship[userId].end(); ++ it, ++ id){
            tot += posttweets[*it].size();
            userlist[id] = *it;
        }
        tmp.resize(tot);
        id = 0;
        for(int i = 0; i < userlist.size(); ++ i){
            for(int j = 0; j < posttweets[userlist[i]].size(); ++ j){
                tmp[id ++] = posttweets[userlist[i]][j];
            }
        }
        ans.resize(min(10, (int)tmp.size()));
        sort(tmp.begin(), tmp.end(), cmpfunc);
        for(int i = 0; i < ans.size(); ++ i){
            ans[i] = tmp[i].first;
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return ;
        followship[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followship[followerId].erase(followeeId);
    }
private:
    struct cmp{
	   bool operator() (const pair<int, int> &a, const pair<int, int> &b){
	        return b.second < a.second; 
	   }
	}cmpfunc;
private:
    unordered_map<int,unordered_set<int> > followship;
    unordered_map<int,vector<pair<int,int>> > posttweets;
    int timestamp;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
