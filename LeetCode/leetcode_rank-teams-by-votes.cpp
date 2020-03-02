/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if(votes.size() == 0 || votes[0].size() == 0){
            return "";
        }
        
        vector<vector<int>> ranks(26, vector<int>(26, 0));
        for(string vote : votes){
            for(int i = 0; i < vote.size(); ++ i){
                ++ ranks[(int)(vote[i] - 'A')][i];
            }
        }
        
        vector<pair<char, vector<int>>> teams(ranks.size());
        for(int i = 0; i < ranks.size(); ++ i){
            teams[i] = make_pair('A' + i, ranks[i]);
        }
        
        sort(teams.begin(), teams.end(), cmp);
        
        string ans = "";
        for(int i = 0; i < votes[0].size(); ++ i) {
            ans += teams[i].first;
        }
        return ans;
    }
    
private:
    struct comparator {
        bool operator() (const pair<char, vector<int>> &a, const pair<char, vector<int>> &b){
            for(int i = 0; i < a.second.size(); ++ i){
                if(a.second[i] != b.second[i]) {
                    return b.second[i] < a.second[i];
                }
            }
            return a.first < b.first;
        }
    }cmp;
};
