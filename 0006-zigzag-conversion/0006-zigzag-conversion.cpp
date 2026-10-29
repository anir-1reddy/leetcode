class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;

        vector<string>list(numRows , "");
        int currline = 0;
        bool reachededge = true;

        for(int i = 0; i < s.length() ; i++){
            if(currline == 0 || currline == numRows - 1){
                reachededge = !reachededge;
            }
            list.at(currline) += s.at(i);
            if(!reachededge){
                currline++;
            }
            else{
                currline--;
            }
        }

        string result;
        for(int i = 0 ; i< numRows ; i++){
            result += list.at(i);
        }
        return result;
    }
};