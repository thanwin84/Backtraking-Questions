// using extra space
class Solution {
    vector<vector<int>> permutations;
    vector<int> permutation;
    vector<int> seen;
public:
    void solve(vector<int> &nums){
        if (permutation.size() == nums.size()){
            permutations.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size();i++){
            if (seen[i] == 0){
                seen[i] = 1;
                permutation.push_back(nums[i]);
                solve(nums);
                seen[i] = 0;
                permutation.pop_back();
                
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        seen = vector<int>(nums.size() + 1, 0);
        solve(nums);
        return permutations;
        

    }
};

// without using extra space
class Solution {
    vector<vector<int>> permutations;
public:
    void swap(vector<int> &nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void solve(vector<int> &permutation, int start){
        if (start == permutation.size() - 1){
            permutations.push_back(permutation);
            return;
        }
        for (int ind = start; ind < permutation.size();ind++){
            swap(permutation, start, ind);
            solve(permutation, start + 1);
            swap(permutation, start, ind);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        return permutations;
        

    }
};
