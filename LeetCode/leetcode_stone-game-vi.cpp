/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        if(aliceValues.size() != bobValues.size() || bobValues.size() == 0) {
            return 1;
        }
        
        int n = bobValues.size();
        vector<vector<int>> stones(n);
        for(int i = 0; i < n; ++ i) {
            stones[i] = {aliceValues[i], bobValues[i]};
        }
        
        sort(stones.begin(), stones.end(), cmp);
        int aliceSum = 0, bobSum = 0;
        for(int i = 0; i < n; ++ i) {
            if((i&1) == 0) {
                aliceSum += stones[i][0];
            } else {
                bobSum += stones[i][1];
            }
        }
        
        return aliceSum > bobSum? 1 : aliceSum < bobSum? -1 : 0;
    }
private:
    struct comparator{
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return b[0] + b[1] < a[0] + a[1];
        }
    }cmp;
};
