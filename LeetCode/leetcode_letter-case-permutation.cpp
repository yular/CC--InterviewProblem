/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        if(S.size() == 0){
            ans.push_back("");
            return ans;
        }
        string ansS = S;
        buildLetterCasePermutation(0, ans, ansS, S);
        return ans;
    }
    
private:
    void buildLetterCasePermutation(int dep,vector<string> &ans,string ansS, string S){
        if(dep >= S.size()){
            ans.push_back(ansS);
            return ;
        }
        if(isalpha(S[dep])){
            ansS[dep] = S[dep] >= 'a' && S[dep] <= 'z' ? toupper(S[dep]) : tolower(S[dep]);
            buildLetterCasePermutation(dep + 1, ans, ansS, S);
        }
        ansS[dep] = S[dep];
        buildLetterCasePermutation(dep + 1, ans, ansS, S);
    }
};
