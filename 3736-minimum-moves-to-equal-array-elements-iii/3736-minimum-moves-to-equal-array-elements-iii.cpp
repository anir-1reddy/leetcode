class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int big = nums.back();
        int ans = 0;

        for(int i = 0 ;i < nums.size() - 1; i++){
            ans += (big - nums[i]);
        }

        return ans;
    }
};