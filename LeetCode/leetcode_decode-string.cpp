/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    string decodeString(string s) {
        if(!s.size())
            return s;
        string res = "", t = "[" + s + "]", tmpstr = "", tmpres = "";
        int cnt = -1, n = s.size() + 2, strcnt = 0;
        cout<<t<<endl;
        for(int i = 0; i < n; ++ i){
            if(t[i] == '['){
                cnt = cnt < 0?1:cnt;
                cntstk.push(cnt);
                cnt = -1;
            }else if(t[i] >= '0' && t[i] <= '9'){
                cnt = cnt < 0?0:cnt;
                cnt = cnt*10 + (t[i] - '0');
                if(tmpstr.size() > 0){
                    strstk.push(tmpstr);
                    tmpstr = "";
                }
            }else if(t[i] == ']'){
                strstk.push(tmpstr);
                while(i < n && t[i] == ']'){
                    strcnt = cntstk.top();
                    cntstk.pop();
                    tmpstr = strstk.top();
                    strstk.pop();
                    tmpres = "";
                    for(int j = 0; j < strcnt; ++ j)
                        tmpres += tmpstr;
                    tmpres = strstk.empty()?tmpres : strstk.top() + tmpres;
                    if(!strstk.empty())
                        strstk.pop();
                    strstk.push(tmpres);
                    ++ i;
                }
                tmpstr = "";
                -- i;
            }else{
                tmpstr += t[i];
            }
        }
        return strstk.top();
    }
private:
    stack<int> cntstk;
    stack<string> strstk;
};
