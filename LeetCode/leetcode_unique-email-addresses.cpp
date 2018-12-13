/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        if(emails.size() == 0){
            return 0;
        }
        unordered_set<string> emailList;
        for(int i = 0; i < emails.size(); ++ i){
            emailList.insert(getActualEmail(emails[i]));
        }
        return emailList.size();
    }
    
private:
    string getActualEmail(string email){
        string actualEmail = "";
        int posOfTag = 0;
        for(int i = 0; i < email.size(); ++ i){
            if(email[i] == '@'){
                break;
            }
            if(email[i] == '.'){
                continue;
            }
            if(email[i] == '+'){
                posOfTag = email.find("@");
                break;
            }
            actualEmail += email[i];
        }
        actualEmail += email.substr(posOfTag);
        return actualEmail;
    }
};
