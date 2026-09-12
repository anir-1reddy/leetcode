class Solution {
public:
    int n;
    vector<int> nextIdx;

    struct Node {
        long long score = 0;
        vector<int> idxs;
    };

    vector<vector<Node>> t;

    int findNext(vector<vector<int>>& intervals, int r) {
        int lo = 0, hi = n - 1;
        int result = n;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (intervals[mid][0] > r) {
                result = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

     
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        
        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            nextIdx[i] = findNext(intervals, end);
        }

        int k = 4;

        
        t.assign(n + 1, vector<Node>(k + 1));

        for (int i = n - 1; i >= 0; i--) {

            int weight = intervals[i][2];
            int idx = intervals[i][3];

            int j = nextIdx[i];

            for (int cnt = 1; cnt <= k; cnt++) {

               
                Node skip = t[i + 1][cnt];

              
                Node temp = t[j][cnt - 1];

                Node take;

                take.score = temp.score + weight;
                take.idxs = temp.idxs;
                take.idxs.push_back(idx);

               
                sort(take.idxs.begin(), take.idxs.end());

                Node result;

                if (skip.score > take.score) {
                    result = skip;
                }
                else if (skip.score < take.score) {
                    result = take;
                }
                else {
                    result = (skip.idxs < take.idxs) ? skip : take;
                }

                t[i][cnt] = result;
            }
        }

        return t[0][k].idxs;
    }
};