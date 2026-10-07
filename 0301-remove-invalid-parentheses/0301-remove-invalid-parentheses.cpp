class Solution {
public:

    bool isvalid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push('(');
            }
            else if (s[i] == ')') {

                if (!st.empty()) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }


    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        queue<string> q;
        set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string curr = q.front();
                q.pop();

                if (isvalid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }
                if (found)
                    continue;

                for (int i = 0; i < curr.size(); i++) {

                    if (curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = "";

                    for (int j = 0; j < curr.size(); j++) {

                        if (j == i)
                            continue;

                        next += curr[j];
                    }

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

           
            if (found)
                break;
        }

        return ans;
    }
};