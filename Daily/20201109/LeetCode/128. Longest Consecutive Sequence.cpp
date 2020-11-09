class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (int i : nums)
            s.insert(i);
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            if (s.count(nums[i]-1) == 0){
                int tans = 0;
                int tn = nums[i];
                while(s.count(tn)){
                    tans++;
                    tn++;
                }
                if (tans > ans)
                    ans = tans;
            }
        }
        return ans;
    }
};