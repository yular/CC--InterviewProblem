/*
*
* Tag: Binary Search
* Time: O(n) + O(lgn)
* Space: O(n)
*/

class TopVotedCandidate {
private:
    vector<pair<int,int>> voteBoard;
    unordered_map<int,int> voteCnt;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int n = times.size();
        voteBoard.resize(n);
        int maxVote = 0, winner = 0;
        for(int i = 0; i < n; ++ i) {
            ++ voteCnt[persons[i]];
            if(voteCnt[persons[i]] >= maxVote) {
                maxVote = voteCnt[persons[i]];
                winner = persons[i];
            }
            voteBoard[i] = make_pair(winner, times[i]);
        }
    }
    
    int q(int t) {
        int n = voteBoard.size();
        if(t >= voteBoard[n - 1].second) {
            return voteBoard[n - 1].first;
        }
        
        int ans = 0, l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r)>>1;
            if(voteBoard[mid].second == t) {
                ans = mid;
                break;
            } else if(voteBoard[mid].second < t) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return voteBoard[ans].first;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
