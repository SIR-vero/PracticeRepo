#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mi = 1;
        int ma = 0;
        for (int i : nums){
            if(i > ma)
                ma = i;
        }

        int mid;
        while(ma >= mi){
            mid = (mi+ma)/2;
            //calculate answer;
            cout << "mi: " << mi << " ma: " << ma << " mid: " << mid << endl;
            int ans = 0;
            for (int i : nums)
                if (i % mid != 0)
                    ans += (i/mid) + 1;
                else
                    ans += i/mid;

            cout << "ans: " << ans << endl;

            if (ans == threshold){
                //cout << "ans: " << ans << endl;
                //cout << "ans == threshold\n";
                if (mid == 1){
                    cout << "mid == 1\n";
                    break;
                }

                ans = 0;
                for (int i : nums)
                if (i % (mid-1) != 0)
                    ans += (i/(mid-1)) + 1;
                else
                    ans += i/(mid-1);

                if (ans == threshold)
                    ma = mid-1;
                else{
                    cout << "ans == threshold\n";
                    break;
                }
            }
            else if (ans < threshold){
                if (mid == 1){
                    cout << "ans: " << ans << endl;
                    break;
                }
                ans = 0;
                for (int i : nums)
                if (i % (mid-1) != 0)
                    ans += (i/(mid-1)) + 1;
                else
                    ans += i/(mid-1);

                if (ans > threshold){
                    cout << "ans > threshold\n";
                    break;
                }
                ma = mid-1;
            }
            else
                mi = mid+1;
        }
        return mid;

    }
};


int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0;i < n; i++)
        cin >> nums[i];

    int th;
    cin >> th;
    Solution s;
    cout << s.smallestDivisor(nums, th) << endl;
}

return 0;}
