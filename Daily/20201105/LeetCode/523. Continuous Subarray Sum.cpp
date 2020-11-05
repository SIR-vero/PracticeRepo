class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        bool pos = false;
        if (k < 0)
            k = (-1)*k;
        if (k == 0){
            for (int i = 0; i < nums.size()-1; i++)
                if (nums[i] == nums[i+1] && nums[i] == 0)
                    return true;
            return false;
        }
        if (nums.size() == 1)
            return false;
        map<int, bool> isp;
        
        isp[0] = true;
        
        int curr = nums[0]; 
        for (int i = 1; i < nums.size(); i++){
            curr += nums[i];
            if (isp[(curr%k)]){
                pos = true;
                break;
            }
            
            isp[(curr - nums[i]) % k] = true;
        }
        
        return pos;
    }
};