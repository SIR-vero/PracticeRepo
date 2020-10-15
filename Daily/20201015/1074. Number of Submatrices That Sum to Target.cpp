class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j-1];
        
        unordered_map<int, int> freq;
        int ans = 0, currsum = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
            {
                freq = {{0, 1}};
                currsum = 0;
                
                for (int k = 0; k < m; k++)
                {
                    currsum += (matrix[k][j] - (i > 0 ? matrix[k][i-1] : 0));
                    ans += freq.find(currsum - target) != freq.end() ? freq[currsum - target] : 0;
                    freq[currsum]++;
                }
            }
        return ans;
    }
};