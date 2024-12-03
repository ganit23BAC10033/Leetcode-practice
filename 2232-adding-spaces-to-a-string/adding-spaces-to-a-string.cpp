class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int t = 0;
        int m = spaces.size();
        string ans;

        for (int i = 0; i < n; i++) {
            if (t < m && i == spaces[t]) {
                ans += " ";
                t++;
            }
            ans += s[i];
        }
        return ans;
    }
};


