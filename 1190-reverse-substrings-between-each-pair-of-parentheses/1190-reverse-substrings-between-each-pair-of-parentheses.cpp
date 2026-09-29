class Solution {
public:
    string reverseParentheses(string s) {
       int n = s.size();
       vector<int>pair(n);
       stack<int>st;

      for(int i = 0 ; i < n ; i++){
        if(s[i] == '('){
            st.push(i);
        }
        else if(s[i] == ')')
        {
            int j = st.top();
            st.pop();
            pair[i] = j ; 
            pair[j] = i ;
        }
      }

      string res ;
      int flag = 1;
      for(int i = 0  ; i < n ; i+= flag){
        if(s[i] == '(' || s[i] ==')'){
            i = pair[i];
            flag = -flag;
        }
        else{
            res.push_back(s[i]);
        }
      }
      return res;
    }

};