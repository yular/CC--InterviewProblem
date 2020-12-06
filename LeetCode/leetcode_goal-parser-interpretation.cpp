/*
*
* Tag: string
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    string interpret(string command) {
        if(command == "") {
            return "";
        }
        
        string ans = "";
        for(int i = 0; i < command.size(); ++ i) {
            if(command[i] == 'G') {
                ans += "G";
            } else if(command[i] == '(') {
                if(command[i + 1] == ')') {
                    ans += "o";
                    ++ i;
                } else {
                    ans += "al";
                    i += 3;
                }
            }
        }
        return ans;
    }
};
