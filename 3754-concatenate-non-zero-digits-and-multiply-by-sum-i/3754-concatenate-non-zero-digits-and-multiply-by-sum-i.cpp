class Solution {
public:

   vector<long long>solve( int n ){
    vector<long long>ans ;

    while(n){
        long long x = n / 10 ;
        long long y = n % 10 ;
        n = x ;
        if(y != 0){
            ans.push_back(y);
        }
    }

    return ans ;
   }

    long long sumAndMultiply(int n) {
       vector<long long > num ;
       
       num = solve(n) ;
       long long sum = 0 ;

       for(int i = 0 ;i < num.size() ; i++){
        sum += num[i] ;
       }
       
       long long number = 0 ;
       for(int i = num.size() - 1 ; i >= 0 ; i--){
        number = number*10 + num[i] ;
       }

       return number*sum ;
    }
};