/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    unordered_map<char,pair<int,int>> dict;
public:
    string alphabetBoardPath(string target) {
        string ans = "";
        if(target.size() == 0){
            return ans;
        }
        
        init();
        
        char cur = 'a';
        pair<int,int> pos(0, 0);
        
        for(char ch : target) {
            if(ch == cur){
                ans += "!";
                continue;
            }
            
            pair<int,int> nxtPos = dict[ch];
            ans += getPath(ch, pos, nxtPos);
            
            ans += "!";
            cur = ch;
            pos = nxtPos;
        }
        
        return ans;
    }
private:
    void init() {
        dict['a'] = make_pair(0, 0);
        dict['b'] = make_pair(0, 1);
        dict['c'] = make_pair(0, 2);
        dict['d'] = make_pair(0, 3);
        dict['e'] = make_pair(0, 4);
        
        dict['f'] = make_pair(1, 0);
        dict['g'] = make_pair(1, 1);
        dict['h'] = make_pair(1, 2);
        dict['i'] = make_pair(1, 3);
        dict['j'] = make_pair(1, 4);
        
        dict['k'] = make_pair(2, 0);
        dict['l'] = make_pair(2, 1);
        dict['m'] = make_pair(2, 2);
        dict['n'] = make_pair(2, 3);
        dict['o'] = make_pair(2, 4);
        
        dict['p'] = make_pair(3, 0);
        dict['q'] = make_pair(3, 1);
        dict['r'] = make_pair(3, 2);
        dict['s'] = make_pair(3, 3);
        dict['t'] = make_pair(3, 4);
        
        dict['u'] = make_pair(4, 0);
        dict['v'] = make_pair(4, 1);
        dict['w'] = make_pair(4, 2);
        dict['x'] = make_pair(4, 3);
        dict['y'] = make_pair(4, 4);
        
        dict['z'] = make_pair(5, 0);
    }
    
    string getPath(char ch, pair<int,int> curPos, pair<int,int> nxtPos) {
        if(ch == 'z') {
            return nxtPos.second == curPos.second? string(nxtPos.first - curPos.first, 'D') : string(4 - curPos.first, 'D') + string(curPos.second, 'L') + "D";
        }
        
        string res = "";
        if(nxtPos.first > curPos.first){
            string tmp(nxtPos.first - curPos.first, 'D');
            res += tmp;
        }else if(nxtPos.first < curPos.first) {
            string tmp(curPos.first - nxtPos.first, 'U');
            res += tmp;
        }

        if(nxtPos.second > curPos.second){
            string tmp(nxtPos.second - curPos.second, 'R');
            res += tmp;
        }else if(nxtPos.second < curPos.second) {
            string tmp(curPos.second - nxtPos.second, 'L');
            res += tmp;
        }
        return res;
    }
};
