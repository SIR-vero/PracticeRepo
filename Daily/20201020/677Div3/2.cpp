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

    int f1 = -1, l1 = n;
    for (int i = 0; i < n ;i++)
        if (a[i] == 1)
        {
            f1 = i;
            break;
        }

    for (int i = n-1; i >= 0 ;i--)
        if (a[i] == 1)
        {
            l1 = i;
            break;
        }
    int ans = 0;
    for (int i = f1; i < l1; i++)
        if (a[i] == 0)
            ans++;


    cout << ans << endl;
}
return 0;}
