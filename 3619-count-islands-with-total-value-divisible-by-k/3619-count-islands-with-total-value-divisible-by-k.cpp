class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long islandValue = dfs(grid, i, j, m, n);
                    if (islandValue % k == 0) {
                        islandCount++;
                    }
                }
            }
        }
        return islandCount;
    }

private:
    long long dfs(std::vector<std::vector<int>>& grid, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }

        long long total = grid[r][c];
        grid[r][c] = 0;

        total += dfs(grid, r + 1, c, m, n);
        total += dfs(grid, r - 1, c, m, n);
        total += dfs(grid, r, c + 1, m, n);
        total += dfs(grid, r, c - 1, m, n);

        return total;
        
    }
};