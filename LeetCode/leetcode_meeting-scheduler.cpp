/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        if(duration == 0) {
            return {};
        }
        
        sort(slots1.begin(), slots1.end(), cmp);
        sort(slots2.begin(), slots2.end(), cmp);
        
        vector<int> ans;
        int n = slots1.size(), m = slots2.size();
        for(int i = 0, j = 0; i < n && j < m;){
            if(slots1[i][1] <= slots2[j][0]) {
                ++ i;
                continue;
            }
            if(slots2[j][1] <= slots1[i][0]) {
                ++ j;
                continue;
            }
            int startTime = 0, endTime = 0;
            if(slots1[i][0] >= slots2[j][0] && slots1[i][0] <= slots2[j][1]) {
                startTime = slots1[i][0];
                endTime = min(slots1[i][1], slots2[j][1]);
                ++ j;
            } else if(slots2[j][0] >= slots1[i][0] && slots2[j][0] <= slots1[i][1]) {
                startTime = slots2[j][0];
                endTime = min(slots1[i][1], slots2[j][1]);
                ++ i;
            }
            if(endTime - startTime >= duration) {
                ans.resize(2);
                ans[0] = startTime, ans[1] = startTime + duration;
                break;
            }
        }
        return ans;
    }
private:
    struct comparator {
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        }
    }cmp;
};
