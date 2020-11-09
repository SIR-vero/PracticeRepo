class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ksum(n-k+1);
        int s = 0;
        for (int i = 0; i < k; i++)
            s += nums[i];
        
        ksum[0] = s;
        for (int i = 1; i < n-k+1; i++){
            s += nums[i+k-1];
            s -= nums[i-1];
            ksum[i] = s;
        }
        cout << "here\n"; 
        
        int left[n-k+1], right[n-k+1];
        int l = 0, li = -1;
        for (int i = 0; i < n-k+1; i++){
            if (ksum[i] > l){
                l = ksum[i];
                li = i;
            }
            left[i] = li;
        }
        
        l = 0, li = -1;
        for (int i = n-k; i >= 0; i--){
            if (ksum[i] >= l){
                l = ksum[i];
                li = i;
            }
            right[i] = li;
        }
        
        
        
        l = 0;
        vector<int> ans(3);
        for (int i = k; i <= n-(2*k); i++){
            if (l < (ksum[left[i-k]] + ksum[right[i+k]] + ksum[i])){
                l = (ksum[left[i-k]] + ksum[right[i+k]] + ksum[i]);
                ans[0] = left[i-k];
                ans[1] = i;
                ans[2] = right[i+k];
            }
        }
        return ans;
    }
};