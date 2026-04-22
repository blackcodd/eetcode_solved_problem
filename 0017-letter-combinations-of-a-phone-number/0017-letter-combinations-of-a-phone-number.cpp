class Solution {
private:
    void backtrack(string digits, map<char,string> m, string current, vector<string>& result) {
        if (current.length() == digits.length()) {
            result.push_back(current);
            return;
        }
        
        char digit = digits[current.length()];
        string letters = m[digit];
        
        for (char letter : letters) {
            backtrack(digits, m, current + letter, result);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        vector<string>result;
        backtrack(digits, m, "", result);
        return result;
       
    }
};