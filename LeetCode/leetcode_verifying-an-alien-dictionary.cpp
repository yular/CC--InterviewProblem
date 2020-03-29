/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() == 0) {
            return true;
        }
        
        vector<int> dict(26, 0);
        for(int i = 0; i < order.size(); ++ i) {
            int idx = order[i] - 'a';
            dict[idx] = i;
        }
        
        for(int i = 1; i < words.size(); ++ i) {
            bool allEqual = true;
            for(int j = 0; j < min(words[i - 1].size(), words[i].size()); ++ j) {
                int idx1 = words[i - 1][j] - 'a', idx2 = words[i][j] - 'a';
                if(dict[idx1] < dict[idx2]) {
                    allEqual = false;
                    break;
                }
                if(dict[idx1] > dict[idx2]) {
                    return false;
                }
            }
            if(words[i - 1].size() > words[i].size() && allEqual) {
                return false;
            }
        }
        return true;
    }
};
