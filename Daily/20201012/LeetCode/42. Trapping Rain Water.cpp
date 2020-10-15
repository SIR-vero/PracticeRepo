class Solution {
public:
    int trap(vector<int>& height) {
        int currmax = 0;
        int currwater = 0;
        int ans = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] >= currmax)
            {
                ans += currwater;
                currwater = 0;
                cout << "ans : " << i << " : " << (currwater) << endl;
                currmax = height[i];
            }
            else
            {
                currwater += (currmax - height[i]);
                cout << "curwater : " << i << " : " << (currmax - height[i]) << endl;
            }
        }
        
        cout << ans << endl;
        
        currmax = 0;
        currwater = 0;
        for (int i = height.size() - 1; i >= 0; i--)
        {
            if (height[i] > currmax)
            {
                ans += currwater;
                currwater = 0;
                currmax = height[i];
            }
            else
                currwater += (currmax - height[i]);
        }
        
        return ans;
    }
};