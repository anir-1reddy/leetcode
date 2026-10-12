class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int>diff((int) 1e5+1);
        for(int i = 0 ;i < n ; i++){
            diff[abs(nums1[i] - nums2[i])]++;
        }

        int value = 0 , acc = 0;
        int k = k1+k2;

        for(int i = (int)1e5 ; i >= 0 ; i--){
            acc = diff[i];
            if(acc <= k){
                if(i <= 1)
                return 0;

                diff[i-1] += diff[i];
                diff[i] = 0;
                k -= acc;
            }
            else{
                if(i == 0) return 0;
                diff[i] -= k;
                diff[i-1] += k;
                break;
            }
        }
        long long ans = 0;
        for(int i = 1ll; i<=1e5; i++)
        {
            ans += (long long)diff[i] * ((long long)i*i);
        }
        
        return ans;
    }
};