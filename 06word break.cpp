//time: O(N * 2^N) and space: O(N)
class Solution {
public:
    vector<string> output;
    unordered_map<string, int> dict;
    void solve(string s, string sentence) {
        if (s.size() == 0) {
            output.push_back(sentence);
            return;
        }
        for (int k = 0; k < s.size(); k++) {
            if (dict.count(s.substr(0, k + 1))) {
                if (k == s.size() - 1) {
                    solve(s.substr(k + 1), sentence + s.substr(0, k + 1));
                }
                else {
                    solve(s.substr(k + 1), sentence + s.substr(0, k + 1) + ' ');
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto i : wordDict) {
            dict[i] = 1;
        }
        solve(s, "");
        return output;
    }
};
