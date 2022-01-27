
class Solution {
public:
    
    vector<vector<int>> comb_li;
    vector<int> temp_arr;
    unordered_map<string, int> seen;
    void solve(vector<int>& nums, int target, int ind, string arr) {
        if (target == 0) {
            if (!seen.count(arr)) {
                seen[arr] = 1;
                comb_li.push_back(temp_arr);
            }
            return;
        }
        if (ind < 0) {
            return;
        }
        if (nums[ind] <= target) {
            //do
            temp_arr.push_back(nums[ind]);
            //recurse
            solve(nums, target - nums[ind], ind, arr + to_string(nums[ind])+'-');
            //undo
            temp_arr.pop_back();
        }
        solve(nums, target, ind - 1, arr);
    }
    vector<vector<int> > combinationSum(vector<int>& A, int target) {
        // Your code here
        sort(A.begin(), A.end(), greater<int>());
        solve(A, target, A.size() -1, "");
        return comb_li;
    }
};
