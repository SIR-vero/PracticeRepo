class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int height = books[i-1][1];
            int width = books[i-1][0];
            
            dp[i] = height + dp[i-1];
            
            int ma = height;
            
            for (int j = i-1; j > 0 ; j--)
            {
                width += books[j-1][0];
                if (width > shelf_width)
                    break;
                if (ma < books[j-1][1])
                    ma = books[j-1][1];
                dp[i] = min(dp[i], ma + dp[j-1]);
            }
        }
        
        for (int i : dp)
            cout << i << " ";
        
        return dp[n];
    }
};