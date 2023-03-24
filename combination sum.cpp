
class Solution {
    vector<vector<int>> combinations;
    vector<int> combination;
public:
    void solve(vector<int> &candidates, int target, int currentSum, int choice){
        if (choice == candidates.size() || currentSum > target){
            return;
        }
        if (currentSum == target){
            combinations.push_back(combination);
            return;
        }
        currentSum += candidates[choice];
        combination.push_back(candidates[choice]);
        solve(candidates, target, currentSum, choice);
        currentSum -= candidates[choice];
        combination.pop_back();
        solve(candidates, target, currentSum, choice + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0, 0);
        return combinations;
    }
};

// time complexity: O(2^n) * K(average size of combination)
// space: since the size of combination is unpredictable, let's assume the size of the combinations is k and size 
// of the combination is x, so time complexity will be O(k * x)
