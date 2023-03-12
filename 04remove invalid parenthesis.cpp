// --------algorithm
// minimum number of removal = size of string - number of valid pairs and characters
// remove one parenthesis every time and check if rest of the string can form a valid parenthesis
class Solution {
    vector<string> valid_parenthesis;
    unordered_map<string, bool> seen;
public:
    int getMin(string s){
        // all the non matching backets will remain in the stack
        // and it will be also used to find the matching pair of bracket
        vector<char> stack;
        // keep track of valid pairs
        int valid_pairs = 0;
        int chars = 0;
        for (auto ch: s){
            if (ch == '(') stack.push_back(ch);
            else if (ch == ')'){
                //  found a matching pair
                if (stack.size() > 0 && stack.back() == '('){
                    // pop the matching bracket
                    stack.pop_back();
                    valid_pairs += 2;
                }
            }
            else chars++;
            
        }
        return s.size() - valid_pairs - chars;
    }
    bool isValid(string &s){
        vector<char> stack;
        for (auto ch: s){
            if (ch == '(') stack.push_back(ch);
            else if (ch == ')'){
                //  found a matching pair
                if (stack.size() > 0 && stack.back() == '('){
                    // pop the matching bracket
                    stack.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        return stack.size() == 0;

    }
    void solve(string s, int minRemoval){
        seen[s] = true;
        // if it is valid, save it
        if (isValid(s)){
            valid_parenthesis.push_back(s);
            return;
        }
        // it will make sure we only remove minimum parenthesis
        if (minRemoval == 0){
            return;
        }
        // removing one parenthesis every time
        // and checking if rest string can form valid parenthesis
        for (int k = 0; k < s.size(); k++){
            if (s[k] == '(' || s[k] == ')'){
                string left = s.substr(0, k);
                // excluding the current character
                string right = s.substr(k + 1);
                // check if we've already solve the problem
                if (!seen.count(left + right)){
                    solve(left + right, minRemoval - 1);
                }
            }
            
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int minRemove = getMin(s);
        solve(s, minRemove);
        return valid_parenthesis;
    }
};
