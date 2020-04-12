/*
*
* Tag: String
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string entityParser(string text) {
        if(text == "") {
            return "";
        }
        
        string ans = "";
        for(int i = 0; i < text.size(); ++ i) {
            if(text[i] != '&') {
                ans += text[i];
                continue;
            }
            
            string symbol = "";
            while(i < text.size() && text[i] != ';') {
                symbol += text[i];
                ++ i;
            }
            symbol += ";";
            
            ans += getHtmlEntityOf(symbol);
        }
        return ans;
    }
    
private:
    string getHtmlEntityOf(string symbol) {
        if(symbol == "&quot;") {
            return "\"";
        }
        if(symbol == "&apos;") {
            return "'";
        }
        if(symbol == "&amp;") {
            return "&";
        }
        if(symbol == "&apos;") {
            return ".";
        }
        if(symbol == "&gt;") {
            return ">";
        }
        if(symbol == "&lt;") {
            return "<";
        }
        if(symbol == "&frasl;") {
            return "/";
        }
        return symbol;
    }
};
