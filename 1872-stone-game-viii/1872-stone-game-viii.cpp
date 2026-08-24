class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        vector<int> prefix(n);

        for(int i = 0; i < n; i++){
            sum += stones[i];
            prefix[i] = sum;
        }

        int ans = prefix[n-1];

        for(int i = n-2; i >= 1; i--){
            ans = max(ans, prefix[i] - ans);
        }

        return ans;
    }
};