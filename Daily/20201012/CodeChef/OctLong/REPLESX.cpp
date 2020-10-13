#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

const int mod97 = 1000000000+7;
long long expo(long long p,long long q)
{
    long long z=1;
    while(q>0)
    {
        if(q%2==1)
            z= (z*p)%mod97;
        p=(p*p)%mod97;
        q >>=1;
    }
    return z;
}

int main(){
int t;
cin>>t;
while(t--){
    int n, x, p, k;
    cin >> n >> x >> p >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    vector<int> px;
    for(int i = 0; i < n; i++)
        if (arr[i] == x)
            px.push_back(i+1);


    bool add = false;
    if (px.size() == 0)
    {
        arr[k] = x;
        add = true;

        sort(arr, arr + n);
        vector<int> px;
        for(int i = 0; i < n; i++)
            if (arr[i] == x)
                px.push_back(i+1);
    }

    bool found = false;
    int ans = n+1;
    for(int i = 0; i < px.size(); i++)
    {
        if (px[i] == p)
        {
            found = true;
            ans = 0;
            break;
        }
        if (px[i] <= p && p <= k)
        {
            found = true;
            if (p - px[i] < ans)
                ans = p - px[i];
        }

        if (px[i] >= p && p >= k)
        {
            found = true;
            if (px[i] - p < ans)
                ans = px[i] - p;
        }
    }

    if (found){
        if (add)
            cout << ans + 1 << endl;
        else
            cout << ans << endl;
    }
    else
        cout << -1 << endl;
}
return 0;}
