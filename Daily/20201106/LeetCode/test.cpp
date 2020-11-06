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
int n, t;
cin >> n >> t;
int x;
int sum = 0;
for (int i = 0;i < n; i++)
{
    cin >> x;
    if (x % t != 0)
        sum += (x/t)+1;
    else
        sum += (x/t);
}

cout << sum << endl;
return 0;}
