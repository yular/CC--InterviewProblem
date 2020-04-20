/*
*
* Tag: Data Structure, Queue
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if(croakOfFrogs.size()%5 != 0) {
            return -1;
        }
        
        int ans = 0, cnt = 0;
        vector<int> q(4, 0);
        for(char c : croakOfFrogs) {
            switch(c){
                case 'c':
                    ++ q[0];
                    ++ cnt;
                    ans = max(ans, cnt);
                    break;
                case 'r':
                    if(q[0] <= 0) {
                        return -1;
                    }
                    -- q[0];
                    ++ q[1];
                    break;
                case 'o':
                    if(q[1] <= 0) {
                        return -1;
                    }
                    -- q[1];
                    ++ q[2];
                    break;
                case 'a':
                    if(q[2] <= 0) {
                        return -1;
                    }
                    -- q[2];
                    ++ q[3];
                    break;
                case 'k':
                    if(q[3] <= 0) {
                        return -1;
                    }
                    -- q[3];
                    -- cnt;
                    break;
                default:
                    return -1;
            }
        }
        
        for(int c : q) {
            if(c != 0) {
                return -1;
            }
        }
        return ans;
    }
};
