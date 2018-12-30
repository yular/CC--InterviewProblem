/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        if(limit == 0 || people.size() == 0){
            return ans;
        }
        
        sort(people.begin(), people.end());
        int tailIdx = people.size() - 1, headIdx = 0;
        while(headIdx <= tailIdx){
            ++ ans;
            if(people[tailIdx] == limit){
                -- tailIdx;
                continue;
            }
            if(people[tailIdx] + people[headIdx] <= limit){
                ++ headIdx;
            }
            -- tailIdx;
        }
        return ans;
    }
};
