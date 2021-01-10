/*
*
* Tag: Greedy + Stack
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int maximumGain(string s, int x, int y, char a = 'a', char b = 'b') {
        if(s.size() < 2) {
            return 0;
        }
        if (y > x) {
            swap(x, y);
            swap(a, b);
        }
        
        int ans = 0;
        calPoints(s, x, a, b, ans);
        calPoints(s, y, b, a, ans);
        return ans;
    }
private:
    void calPoints(string &s, int x, char a, char b, int &ans) {
        string stk;
        for (auto ch : s) {
            if (!stk.empty() && stk.back() == a && ch == b) {
                ans += x;
                stk.pop_back();
            } else
                stk.push_back(ch);
        }
        
        s = stk;
        return;
    }
};
