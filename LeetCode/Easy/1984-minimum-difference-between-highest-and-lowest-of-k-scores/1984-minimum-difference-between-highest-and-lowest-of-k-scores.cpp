class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i =0; i < k; i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        int ans = maxi - mini;
        for(int i = k; i<nums.size();i++){
            mini = nums[i-k+1];
            maxi = nums[i];
            ans = min(ans, maxi-mini);
        }
        return ans;
    }
};