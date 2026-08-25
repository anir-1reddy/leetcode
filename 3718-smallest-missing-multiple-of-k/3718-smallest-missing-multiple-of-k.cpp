class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int m = nums.back()/k ;
        int s = 1;
        while(s<=m){
            int a = s*k;
            bool found = false;
            for(int i = 0 ; i < nums.size(); i++){
                if(a == nums[i]){
                    found = true;
                    break;
                }
            }
            if(found == false) return a ;
            s++;
        }
        return (m+1)*k;
        
    }
};