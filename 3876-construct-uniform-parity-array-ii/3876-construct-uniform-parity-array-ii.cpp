class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int minodd = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            int x = nums1[i];
            if(x%2 == 1){
                minodd = min(minodd,x);
            }
        }

        if(minodd == INT_MAX) return true;

        for(int i = 0 ;i < n ; i++){
            if(nums1[i]%2 == 0 && nums1[i] < minodd) return false;
        }
        return true;
    }
};