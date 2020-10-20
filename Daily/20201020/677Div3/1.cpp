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
    int x;
    cin >> x;
    int ng = 0;
    int temp = x;
    while(temp){
        ng++;
        temp = temp/10;
    }

    int f = x % 10;

    int prev = f-1;
    int ans = 10*prev;

    ans += (ng)*(ng+1)/2;

    cout << ans << endl;
}
return 0;}
