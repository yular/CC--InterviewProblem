/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        if(boxTypes.size() == 0) {
            return 0;
        }
        
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int cnt = 0;
        long long ans = 0;
        for(int i = 0; i < boxTypes.size() && cnt < truckSize; ++ i) {
            int n = boxTypes[i][0];
            if(cnt + n > truckSize) {
                ans += (truckSize - cnt)*boxTypes[i][1];
                cnt = truckSize;
            } else {
                ans += n*boxTypes[i][1];
                cnt += n;
            }
        }
        return ans;
    }
private:
    struct comparator{
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return b[1] < a[1];
        }
    }cmp;
};
