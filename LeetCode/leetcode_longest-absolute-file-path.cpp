/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> dirlen(100);
        int ans = 0;
        if(input.size() == 0)
            return ans;
        int prelen = 0, curlen = 0, tcnt = 0;
        dirlen[0] = 0;
        input += '\n';
        for(int i = 0; i < input.size(); ++ i){
            tcnt = 0;
            while(i < input.size() && input[i] == '\t'){
                ++ tcnt;
                ++ i;
            }
            prelen = dirlen[tcnt];
            bool isfile = false;
            curlen = 0;
            while(i < input.size() && input[i] != '\n'){
                if(input[i] == '.')
                    isfile = true;
                ++ i;
                ++ curlen;
            }
            if(isfile){
                ans = max(ans, prelen + curlen + tcnt);
            }else
                dirlen[tcnt + 1] = prelen + curlen;
        }
        return ans;
    }
};
