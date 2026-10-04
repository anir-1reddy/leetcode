class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int m = intervals.size();
        int n = intervals[0].size();

        vector<vector<int>>ans ;
        sort(intervals.begin() , intervals.end());

        for(const auto& it : intervals){
            if(!ans.empty() && it[0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1] , it[1]);
            }
            else{
                ans.push_back(it);
            }
        }

        return ans;
    }
};