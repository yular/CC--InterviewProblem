/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        if(logs.size() == 0) {
            return 0;
        }
        
        int ans = 0;
        for(string log : logs){
            if(log[0] == '.') {
                if(log.size() == 3 && ans > 0) {
                    -- ans;
                }
            } else {
                ++ ans;
            }
            //cout<<ans<<endl;
        }
        return abs(ans);
    }
};
