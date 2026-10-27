class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
       int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
       auto today = [&](const string& s){
        int m = (s[0] - '0')*10 + (s[1] - '0');
        int d = (s[3] - '0')*10 + (s[4] - '0');
        int res = d;
        for(int i = 0 ; i < m - 1 ; i++) res += days[i];
        return res;
       };

       int astart = today(arriveAlice) , aend = today(leaveAlice);
       int bstart = today(arriveBob) , bend = today(leaveBob);
       int start = max(astart , bstart);
       int end = min(aend , bend);

       return start <= end ? end - start + 1 : 0;
    }
};