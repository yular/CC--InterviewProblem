/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    string dict[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> morsecodes;
        for(int i = 0; i < words.size(); ++ i){
            string code = "";
            for(int j = 0; j < words[i].size(); ++ j){
                int idx = words[i][j] - 'a';
                code += dict[idx];
            }
            
            morsecodes.insert(code);
        }
        return morsecodes.size();
    }
};
