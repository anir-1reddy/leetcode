
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        int a = l;
        int ans = INT_MAX;

        while(a <= r) {
            for(int i = 0; i + a <= n; i++) {
                int count = 0;

                for(int j = i; j < i + a; j++) {
                    count += nums[j];
                }

                if(count > 0) {
                    ans = min(ans, count);
                }
            }
            a++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
