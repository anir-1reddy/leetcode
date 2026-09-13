class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int,int>>a , b ;
        for(int i = 0 ; i < n  ; i++){
            for(int j = 0 ; j < n ; j++){
                if(img1[i][j] == 1) a.emplace_back(i,j);
                if(img2[i][j] == 1) b.emplace_back(i,j);
            }
        }

        vector<vector<int>>cnt(2*n , vector<int>(2*n, 0));
        int best = 0 ;
        for(auto &i : a){
            for(auto &j : b){
                int dx = j.first - i.first + n;
                int dy = j.second - i.second + n ;
                best = max(best , ++cnt[dx][dy]);
            }
        }
        return best;
    }
};