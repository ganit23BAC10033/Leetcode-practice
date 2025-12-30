class Solution {
public:
    bool possible(vector<vector<int>>& grid, int row, int col) {
        unordered_set<int> st;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9 || st.count(num)) {
                    return false;
                }
                st.insert(num);
            }
        }

        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];

        for (int i = 0; i < 3; i++) {
            if (grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2] != sum)
                return false;

            if (grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i] != sum)
                return false;
        }

        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != sum)
            return false;

        if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (possible(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
