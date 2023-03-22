//time: O(N * 2^n)
class Solution {
    vector<vector<string>> output;
    vector<string> temp;
public:
    bool isPalindrone(string &s, int start, int end){
        while(start <= end){
            if (s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(string &s, int start){
        if (start == s.size()){
            output.push_back(temp);
            return;
        }
        for (int end = start; end < s.size(); end++){
            // partition only if the current substring is a palindrone
            if (isPalindrone(s, start, end)){
                temp.push_back(s.substr(start, end - start + 1));
                // recurse for the rest of the substring
                solve(s, end + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return output;
    }
};
