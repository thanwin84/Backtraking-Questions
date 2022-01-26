//time: O(N * 2^n)
class Solution {
public:
    vector<vector<string>> output;
    vector<string> palindrones;
    bool is_palindrone(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string s) {
        if (s.size() == 0) {
            output.push_back(palindrones);
            return;
        }
        for (int k = 0; k < s.size(); k++) {
            if (is_palindrone(s.substr(0, k + 1))) {
                palindrones.push_back(s.substr(0, k + 1));
                solve(s.substr(k + 1));
                palindrones.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        solve(S);
        return output;
    }
};
