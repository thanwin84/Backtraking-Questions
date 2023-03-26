class Solution {
    vector<vector<int>> combinations;
    vector<int> combination;
public:
    void solve(vector<int> &candidates, int target, int choice){
        // we've already got the combination
        if (target == 0){
            combinations.push_back(combination);
            return;
        }
        for(int ind = choice; ind < candidates.size(); ind++){
            // if the current candidate is equal to previous candidate, we won't take it
            // cause it will give duplicate combination
            // ind == choice means, candidates[ind] is the first element in the group
            if (ind > choice && candidates[ind] == candidates[ind - 1]){
                continue;
            }
            // if the current candidate is greater than target, then we don't need to check further
            // cause the array is sorted
            if (candidates[ind] > target){
                break;
            }
            // do
            combination.push_back(candidates[ind]);
            // recurse
            solve(candidates, target - candidates[ind], ind + 1);
            // undo
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort the array so that all duplicates value stay in the same portion
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return combinations;

    }
};
