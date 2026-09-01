class Solution {
public:
    int ladderLength(string startword, string targetword, vector<string>& wordList) {
       queue<pair<string,int>>q;
       q.push({startword,1});

       unordered_set<string> st(wordList.begin() , wordList.end());
       st.erase(startword);

       while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        
        q.pop();
        if(word == targetword) return steps;

        for(int i = 0 ; i < word.size() ; i++){
            char original = word[i];
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                word[i] = ch ;

                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word , steps + 1});
                }
            }
            word[i] = original ;
        }
       }
       return 0;
    }
};