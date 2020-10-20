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

long long nCr(long long n, long long r)
{
    long long den = 1;
    for (int i = 0; i < r; i++){
        den *= n;
        n--;
    }
    long long num = 1;
    for (long long i = 1; i <= r; i++)
        num *= i;

    return den/num;
}

long long fact(long long n)
{
    long long ans = 1;
    for (long long i = 1; i <= n; i++)
        ans *= i;
    return ans;
}

int main(){
int t = 1;
//cin>>t;
while(t--){
    long long n;
    cin >> n;

    long long f = nCr(n , n/2);
    f = f/2;
    long long s = fact(n/2)/(n/2);

    cout << f*s*s << endl;
}
return 0;}
