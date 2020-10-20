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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> li;
    int l = 0;
    for (int i = 0; i < n ; i++)
        if (a[i] > l)
            l = a[i];

    for (int i = 0; i < n ; i++)
        if (a[i] == l)
            li.push_back(i);

    int ans = -1;
    for(auto i : li)
    {
        if (i > 0)
            if (a[i-1] < a[i])
            {
                ans = i+1;
                break;
            }
        if (i < n-1)
            if (a[i+1] < a[i])
            {
                ans = i+1;
                break;
            }
    }
    cout << ans << endl;
}
return 0;}
