class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0)
            return 0;
        int greaterOnLeft[n];
        int greaterOnRight[n];
        greaterOnLeft[0] = -1;
        greaterOnRight[heights.size()-1] = heights.size();
        
        for (int i = 1; i < heights.size(); i++){
            int p = i-1;
            while(p >=0 && heights[p] >= heights[i])
                p = greaterOnLeft[p];
            greaterOnLeft[i] = p;
        }
        
        for (int i = heights.size()-2; i >= 0; i--){
            int p = i+1;
            while(p < heights.size() && heights[p] >= heights[i])
                p = greaterOnRight[p];
            greaterOnRight[i] = p;
        }
        
        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
            if (ans < (heights[i]*(greaterOnRight[i] - greaterOnLeft[i] - 1)))
                ans = (heights[i]*(greaterOnRight[i] - greaterOnLeft[i] - 1));
        
        return ans;
    }
};