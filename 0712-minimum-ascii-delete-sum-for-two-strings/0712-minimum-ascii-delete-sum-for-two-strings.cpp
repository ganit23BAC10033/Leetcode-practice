class Solution {
public:
    int n, m;
    int t[1001][1001];

    int solve(int i, int j, string &s1, string &s2) {
         
        if (i >= n && j >= m) return 0;
        if (i >= n) return s2[j] + solve(i, j + 1, s1, s2);
        if (j >= m) return s1[i] + solve(i + 1, j, s1, s2);

         
        if (t[i][j] != -1) return t[i][j];

         
        if (s1[i] == s2[j]) {
            return t[i][j] = solve(i + 1, j + 1, s1, s2);
        }

        
        int del1 = s1[i] + solve(i + 1, j, s1, s2);
        int del2 = s2[j] + solve(i, j + 1, s1, s2);

        return t[i][j] = min(del1, del2);
    }

    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, s1, s2);
    }
};
