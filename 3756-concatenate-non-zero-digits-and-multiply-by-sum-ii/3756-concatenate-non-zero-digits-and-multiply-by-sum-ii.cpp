class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b) {
            if (b & 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> val(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        vector<int> sum(n + 1, 0);

        vector<long long> pow10(n + 1);
        vector<long long> inv10(n + 1);

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i <= n; i++)
            inv10[i] = power(pow10[i], MOD - 2);


        // suffix preprocessing
        for (int i = n - 1; i >= 0; i--) {

            if (s[i] != '0') {
                int d = s[i] - '0';

                val[i] = (d * pow10[cnt[i + 1]] + val[i + 1]) % MOD;
                cnt[i] = cnt[i + 1] + 1;
            }
            else {
                val[i] = val[i + 1];
                cnt[i] = cnt[i + 1];
            }
        }


        // prefix sum of digits
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + (s[i] - '0');
        }


        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int remove = cnt[r + 1];

            long long x = val[l];

            // remove suffix after r
            x = (x - val[r + 1] + MOD) % MOD;
            x = (x * inv10[remove]) % MOD;

            long long digitSum = sum[r + 1] - sum[l];

            ans.push_back((x * digitSum) % MOD);
        }

        return ans;
    }
};