/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans(queries.size(), 0);
        if(words.size() == 0) {
            return ans;
        }
        
        vector<int> freqCnt(12, 0);
        for(string word : words) {
            int cnt = getFrequencyOf(word);
            ++ freqCnt[cnt];
        }
        vector<int> accumulatedCnt(12, 0);
        for(int i = 10; i >= 0; -- i){
            accumulatedCnt[i] = accumulatedCnt[i + 1] + freqCnt[i + 1];
        }
        
        for(int i = 0; i < queries.size(); ++ i) {
            int cnt = getFrequencyOf(queries[i]);
            ans[i] = accumulatedCnt[cnt];
        }
        return ans;
    }
private:
    int getFrequencyOf(string word) {
        char curChar = 'z';
        int cnt = 0;
        for(char ch : word) {
            if(curChar == ch) {
                ++ cnt;
            } else if(curChar > ch) {
                curChar = ch;
                cnt = 1;
            }
        }
        return cnt;
    }
};
