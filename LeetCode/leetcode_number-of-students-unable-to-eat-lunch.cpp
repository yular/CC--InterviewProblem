/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        if(students.size() != sandwiches.size()) {
            return 0;
        }
        
        int cnt[2] = {0, 0};
        for(int i = 0; i < students.size(); ++ i) {
            if(students[i] == 0) {
                ++ cnt[0];
            } else {
                ++ cnt[1];
            }
        }
        for(int i = 0; i < sandwiches.size(); ++ i) {
            if(cnt[sandwiches[i]] == 0) {
                break;
            }
            -- cnt[sandwiches[i]];
        }
        return cnt[0] + cnt[1];
    }
};
