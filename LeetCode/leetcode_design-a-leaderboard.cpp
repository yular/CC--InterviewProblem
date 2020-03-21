/*
*
* Tag: Map, Hash
* Time: O(lgn)
* Space: O(n)
*/

class Leaderboard {
private:
    map<int,int> scoreCnt;
    unordered_map<int,int> playerScore;

public:
    Leaderboard() {
        scoreCnt.clear();
        playerScore.clear();
    }
    
    void addScore(int playerId, int score) {
        if(playerScore.count(playerId) > 0) {
            -- scoreCnt[playerScore[playerId]];
        }
        
        playerScore[playerId] += score;
        ++ scoreCnt[playerScore[playerId]];
    }
    
    int top(int k) {
        int sum = 0, cnt = 0;
        for(auto it = scoreCnt.rbegin(); it != scoreCnt.rend(); ++ it) {
            if(cnt + it->second > k) {
                sum += (k - cnt)*(it->first);
                break;
            }
            sum += (it->first)*(it->second);
            cnt += it->second;
        }
        return sum;
    }
    
    void reset(int playerId) {
        if(playerScore.count(playerId) == 0) {
            return;
        }
        
        -- scoreCnt[playerScore[playerId]];
        ++ scoreCnt[0];
        playerScore[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
