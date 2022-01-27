#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
#define mod 1000000007
using namespace std;
class Solution {
public:
    vector<int> first_half;
    vector<int> temp_arr;
    int ans = INT_MAX;
    void solve(vector<int>& nums, int curr_ind, int current_sum, int count, int sum) {
        if (curr_ind >= nums.size()) {
            return;
        }
        if (count == nums.size() / 2) {
            int second_sum = sum - current_sum;
            int diff = abs(second_sum - current_sum);
       
            if (diff < ans) {
                ans = diff;
                first_half = temp_arr;
            }
            return;
        }
        temp_arr.push_back(curr_ind);
        solve(nums, curr_ind + 1, current_sum + nums[curr_ind], count + 1, sum);
        temp_arr.pop_back();
        solve(nums, curr_ind + 1, current_sum, count, sum);
       
    }
    void tug_of_war(vector<int> nums) {
        int sum = 0;
        for (auto i : nums) sum += i;
        solve(nums, 0, 0, 0, sum);
        unordered_map<int, int> seen;
        for (auto i : first_half) seen[i] = 1;
        vector<int> first;
        vector<int> second;
        for (int i = 0; i < nums.size(); i++) {
            if (seen.count(i)) {
                first.push_back(nums[i]);
            }
            else second.push_back(nums[i]);
        }
        cout << "first half: ";
        for (auto i : first) {
            cout << i << " ";
        }
        cout << endl;
        cout << "second half: ";
        for (auto i : second) {
            cout << i << " ";
        }
    }
};

int main() {
    Solution ob;
    vector<int> arr = { 23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4 };
    ob.tug_of_war(arr);
    
    return 0;
}
