class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans[m][n];
        
        ans[0][0] = grid[0][0];
        
        for (int i = 0; i < m; i++)
        {
            ans[i][0] = grid[i][0];
            if (i > 0)
                ans[i][0] += ans[i-1][0];
        }
        
        for (int j = 0; j < n; j++)
        {
            ans[0][j] = grid[0][j];
            if (j > 0)
                ans[0][j] += ans[0][j-1];
        }
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                int up = -1;
                int left = -1;
                
                ans[i][j] = grid[i][j];
                
                up = ans[i-1][j];
                left = ans[i][j-1];
                
                ans[i][j] += min(up, left);
            }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
        
        return ans[m-1][n-1];
    }
};