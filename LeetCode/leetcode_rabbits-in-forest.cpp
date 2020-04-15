/*
*
* Tag: Greedy + Hash
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.size() == 0) {
            return 0;
        }
        
        sort(answers.begin(), answers.end());
        
        int ans = 0;
        for(int i = 0; i < answers.size(); ++ i) {
            if(answers[i] == 0) {
                ++ ans;
                continue;
            }
            int cnt = 1;
            while(i + cnt < answers.size() && answers[i + cnt] == answers[i] && cnt < answers[i] + 1) {
                ++ cnt;
            }
            ans += (answers[i] + 1);
            i += cnt - 1;
        }
        return ans;
    }
};
