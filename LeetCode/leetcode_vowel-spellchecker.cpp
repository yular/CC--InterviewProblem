/*
*
* Tag: Hash
* Time: O(nm) where m is the average length of strings.
* Space: O(n)
*/

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans(queries.size(), "");
        if(wordlist.size() == 0) {
            return ans;
        }
        
        unordered_map<string,string> lowercaseDict;
        unordered_map<string, int> dict;
        unordered_map<string, string> vowelDict;
        for(int i = 0; i < wordlist.size(); ++ i){
            string word = wordlist[i];
            if(dict.count(word) == 0){
                dict[word] = i;
            }
            string lowercaseWord = getLowercaseWord(word);
            if(lowercaseDict.count(lowercaseWord) == 0){
                lowercaseDict[lowercaseWord] = word;
            }
            string vowelWord = getVowelWord(lowercaseWord);
            if(vowelDict.count(vowelWord) == 0){
                vowelDict[vowelWord] = word;
            }
        }
        
        for(int i = 0; i < queries.size(); ++ i){
            if(dict.count(queries[i]) != 0){
                ans[i] = queries[i];
                continue;
            }
            string lowercaseWord = getLowercaseWord(queries[i]);
            if(lowercaseDict.count(lowercaseWord) != 0){
                ans[i] = lowercaseDict[lowercaseWord];
                continue;
            }
            string vowelWord = getVowelWord(lowercaseWord);
            if(vowelDict.count(vowelWord) != 0) {
                ans[i] = vowelDict[vowelWord];
                continue;
            }
            
            ans[i] = "";
        }
        return ans;
    }
private:
    string getLowercaseWord(string word) {
        string res = word;
        for(int i = 0; i < word.size(); ++ i){
                res[i] = tolower(res[i]);
        }
        return res;
    }

    string getVowelWord(string word) {
        string res = word;
        for(int i = 0; i < word.size(); ++ i){
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                res[i] = '*';
            }
        }
        return res;
    }
};
