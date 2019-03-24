/*
*
* Tag: Hash
* Time: O(nm) where m is the average length of strings in given array
* Space: O(1)
*/
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        if(A.size() == 0){
            return ans;
        }
        
        vector<int> letterCnt = getLetterCnt(A[0]);
        for(int i = 1; i < A.size(); ++ i){
            vector<int> curLetterCnt = getLetterCnt(A[i]);
            letterCnt = mergeLetterCnt(letterCnt, curLetterCnt);
        }
        
        for(int i = 0; i < letterCnt.size(); ++ i){
            while(letterCnt[i] > 0) {
                string s = "";
                s += (i + 'a');
                ans.push_back(s);
                -- letterCnt[i];
            }
        }
        return ans;
    }
private:
    vector<int> getLetterCnt(string str){
        vector<int> cnt(26, 0);
        for(char letter : str){
            ++ cnt[letter - 'a'];
        }
        return cnt;
    }
    
    vector<int> mergeLetterCnt(vector<int> &cntA, vector<int> &cntB){
        vector<int> cnt(26, 0);
        for(int i = 0; i < 26; ++ i){
            cnt[i] = min(cntA[i], cntB[i]);
        }
        return cnt;
    }
};
