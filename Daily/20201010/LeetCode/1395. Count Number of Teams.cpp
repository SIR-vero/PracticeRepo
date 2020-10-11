class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        for (int i = 0; i < n; i++)
        {
            int leftsmaller = 0;
            int leftlarger = 0;
            for (int j = 0; j < i; j++)
            {
                if (rating[j] < rating[i])
                    leftsmaller++;
                if (rating[j] > rating[i])
                    leftlarger++;
            }
            
            int rightsmaller = 0;
            int rightlarger = 0;
            for (int j = i+1; j < n; j++)
            {
                if (rating[j] < rating[i])
                    rightsmaller++;
                if (rating[j] > rating[i])
                    rightlarger++;
            }
            
            ans += (leftsmaller * rightlarger) + (leftlarger * rightsmaller);
        }
        return ans;
    }
};