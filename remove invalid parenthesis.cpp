class Solution {
public:
    vector<string> output;
    unordered_map<string, int> visited;
    vector<string> removeInvalidParentheses(string s) {
        int min_allowed = get_min(s);
        solve(s, min_allowed);
        return output;
    }
    void solve(string s, int allowed) {
        visited[s] = 1;
        if (is_valid(s)) {
            if (visited[s] != 2) {
                output.push_back(s);
            }
            visited[s] = 2;
            return;
        }
        if (allowed == 0) {
            return;
        }
        for (int k = 0; k < s.size(); k++) {
            if (s[k] == '(' or s[k] == ')') {
                string left = s.substr(0, k);
                string right = s.substr(k + 1);
                if (!visited.count(left + right)) {
                    solve(left + right, allowed - 1);
                }
            }
        }
    }
    int get_min(string s) {
        vector<char> stack;
        int paired_parenthesis = 0;
        int count_char = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back(s[i]);
            }
            else if (s[i] == ')') {
                if (stack.size() > 0 and stack.back() == '(') {
                    stack.pop_back();
                    paired_parenthesis += 2;
                }
            }
            else {
                count_char += 1;
            }
        }
        return s.size() - count_char - paired_parenthesis;
    }
    bool is_valid(string s) {
        vector<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back(s[i]);
            }
            else if (s[i] == ')') {
                if (stack.size() > 0 and stack.back() == '(') {
                    stack.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        if (stack.size() > 0) {
            return false;
        }
        return true;
    }
};
