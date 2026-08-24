class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int count_b = 0 , count_a = 0 , sum_b = 0 , sum_a = 0;
        for(int i = 0 ; i < n/2 ; i++){
            if(num[i] != '?'){
               sum_b += num[i] - '0';
            }
            else count_b++;
        }

         for(int i = n/2 ; i < n ; i++){
            if(num[i] != '?'){
               sum_a += num[i] - '0';
            }
            else count_a++;
        }

       return 2 * (sum_b - sum_a) + 9 * (count_b - count_a) != 0;
    }
};