class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;

        // remove trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int count = 0;

        // count last word characters
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};