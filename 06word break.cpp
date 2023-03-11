//time: O(N * 2^N) and space: O(N)
class Solution{
    unordered_map<string, int> dict_words;
    vector<string> sentences;
public:
    void solve(string s, string sentence){
        if (s.size() == 0){
            sentences.push_back(sentence);
            return;
        }
        for (int k = 0; k < s.size(); k++){
            if (dict_words.count(s.substr(0, k + 1))){
                if (k == s.size() - 1){
                    solve(s.substr(k + 1), sentence + s.substr(0, k + 1));
                }
                else {
                    solve(s.substr(k + 1), sentence + s.substr(0, k + 1) + " ");
                }
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        for(auto word: dict){
            dict_words[word] = 1;
        }
        solve(s, "");
        return sentences;
    }
};
