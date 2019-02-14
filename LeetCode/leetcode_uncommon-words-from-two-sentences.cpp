/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> ans;
        string str = A + " " + B;
        vector<string> allWords = stringToVector(str);
        unordered_map<string,int> wordCnt;
        for(string word : allWords) {
            ++ wordCnt[word];
        }
        
        for(auto it = wordCnt.begin(); it != wordCnt.end(); ++ it){
            if(it->second == 1){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
private:
    vector<string> stringToVector(string str){
        istringstream iss(str);
        vector<std::string> ans((istream_iterator<std::string>(iss)),
                                 istream_iterator<std::string>());

        return ans;
    }
};
