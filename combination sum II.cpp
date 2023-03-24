class Solution {
    vector<vector<int>> combinations;
    vector<int> combination;
    unordered_map<int, int> candidates_group;
public:
    void solve(vector<int> &candidates, int target, int choice){
        if (target == 0){
            combinations.push_back(combination);
            return;
        }
        for(int ind = choice; ind < candidates.size(); ind++){
            if (ind > choice && candidates[ind] == candidates[ind - 1]){
                continue;
            }
            if (candidates[ind] > target){
                break;
            }
            combination.push_back(candidates[ind]);
            solve(candidates, target - candidates[ind], ind + 1);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return combinations;

    }
};
